#include "View/verify_csv.h"
#include "View/ui_verify_csv.h"

using namespace std;

VerifyCSV::VerifyCSV(size_t csvType, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VerifyCSV)
{
    ui->setupUi(this);

    this->csvType = csvType;
    errors = Data::Instance()->getDTO(this->csvType)->getErrorLines();

    // Set the table model (currently only the publication model possible)
    ui->error_table->setModel(ErrorTableModel());

    // Connect the table model to a signal/slot to listen for changes to the table data
    connect(ui->error_table->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChanged(const QModelIndex&, const QModelIndex&)));

    //Display the file name
    QString fn = QString::fromStdString(Data::Instance()->getDTO(csvType)->getFile());
    ui->file_name->setText(fn);

    ui->analyze_btn->setEnabled(true);
}

VerifyCSV::~VerifyCSV()
{
    delete ui;
}

QStandardItemModel* VerifyCSV::ErrorTableModel()
{
    shared_ptr<CSVDTO> csv = Data::Instance()->getDTO(this->csvType);
    vector<string> header = csv->getHeader();
    col = csv->getNMan();

    // Define a model with the number of rows as error lines,
    //and columns as mandatory columns
    QStandardItemModel *model =
            new QStandardItemModel(errors->size(),col,NULL);

    for(size_t i = 0; i < col; i++){
        model->setHorizontalHeaderItem(i,
                    new QStandardItem(QString::fromStdString(header.at(i))));
    }

    // Loop through strings and add each to the table model
    for(size_t i = 0; i < errors->size(); i++){
        shared_ptr<vector<CSVField>> line = errors->at(i);
        for(size_t j = 0; j < col; j++){
            QString qstr = QString::fromStdString(line->at(j+1).getField());
            QStandardItem *newfield = new QStandardItem(qstr);
            model->setItem(i,j,newfield);
        };
    }
    return model;
}

void VerifyCSV::enableConfirmChanges()
{
    ui->confirm_btn->setDisabled(false);
}

/*SLOTS*/

void VerifyCSV::on_load_btn_clicked()
{
    // Show alert, "All unvalidated lines will be ignored. This will not change"
    //Your original file."
    if(errors->size() != 0){
        QMessageBox::StandardButton reload;
        reload = QMessageBox::question(this, "Load New Data",
                                       "All unvalidated data will be ignored.\n"
                                       "This will not change your original CSV.\n"
                                       "Would you like to continue?",
                                       QMessageBox::Yes|QMessageBox::No);
        if (reload == QMessageBox::No) {
            return;
        }
    }
    ignoreAll();
    this->setCentralWidget(new LoadCSV());
}


void VerifyCSV::on_analyze_btn_clicked()
{    
    if(errors->size() != 0){
        QMessageBox::StandardButton leave;
        //warn user that unvalidated data will be deleted
        leave = QMessageBox::question(this, "Analyze Data",
                                       "All unvalidated data will be ignored.\n"
                                       "Would you like to continue?",
                                       QMessageBox::Yes|QMessageBox::No);
        if(leave == QMessageBox::No) return;
    }
    ignoreAll();
    //Go to analyze page
}

void VerifyCSV::on_ignoreall_btn_clicked()
{    
    ignoreAll();
    //Go to analyze page
}

void VerifyCSV::on_ignore_btn_clicked()
{
    QModelIndexList selection = ui->error_table->selectionModel()->selectedRows();

    // For each row the user has selected, remove the rows from bottom up
    // Removing bottom up prevents any shifting of indexes
    for(int i = selection.count() - 1; i >= 0; i--)
    {
        QModelIndex index = selection.at(i);
        ui->error_table->model()->removeRow(index.row());
        errors->erase(errors->begin() + index.row());
    }
}

void VerifyCSV::onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight)
{
    enableConfirmChanges();
}

void VerifyCSV::on_confirm_btn_clicked()
{
    for(size_t i = 0; i < errors->size(); i++){
        for(size_t j = 0; j < col; j++){
            shared_ptr<vector<CSVField>> line = errors->at(i);
            QModelIndex k = ui->error_table->model()->index(i, j);
            string str = ui->error_table->model()->data(k).toString().toStdString();
            line->at(j+1).setField(str);
        };
    }

    //Try and validate the new lines. If a line is changed update the model;
    if(Data::Instance()->getDTO(csvType)->validateErrors()){
        ui->error_table->setModel(ErrorTableModel());
    }

    // Connect the table model to a signal/slot to listen for changes to the table data
    connect(ui->error_table->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChanged(const QModelIndex&, const QModelIndex&)));
}

void VerifyCSV::ignoreAll(){
    ui->error_table->setModel(NULL);
    errors->clear();
    errors->shrink_to_fit();

    ui->verify_btn->setDisabled(true);
    //Save CSV
}
