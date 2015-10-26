#include "load_csv.h"
#include "verify_csv.h"
#include "ui_verify_csv.h"
#include "publicationdto.h"
#include <QtWidgets>
#include <iostream>
#include "csvdataassembler.h"


VerifyCSV::VerifyCSV(QString filename, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VerifyCSV)
{
    ui->setupUi(this);

    data = shared_ptr<CSVData<PublicationDTO>>(new CSVData<PublicationDTO>);

    bool success = AssembleData(data,filename.toStdString());

    ui->error_table->setModel(PublicationTableModel());
    select = ui->error_table->selectionModel();
    connect(ui->error_table->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChanged(const QModelIndex&, const QModelIndex&)));

    ui->file_name->setText(filename);
    changesMade = false;
    ui->confirm_btn->setDisabled(true);
}

VerifyCSV::~VerifyCSV()
{
    delete ui;
}

QStandardItemModel* VerifyCSV::PublicationTableModel()
{
        /*define a model with the number of rows as error lines, and columns as mandatory columns*/
        QStandardItemModel *model = new QStandardItemModel(data->errorRows->size(),data->nMan,NULL);

        //Set headers
        for (int i = 0; i < data->nMan;i++)
        {
            model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(data->header->at(i))));
        }

        /*loop through strings and add each to the table model*/
        for(int i = 0; i < data->errorRows->size(); i++){
            vector<string> line = data->errorRows->at(i);
            for(int j = 0; j < data->nMan; j++){
                QString qstr = QString::fromStdString(line[j]);
                QStandardItem *tempRow = new QStandardItem(qstr);
                model->setItem(i,j,tempRow);
            };
        }
        return model;
}

/*SLOTS*/

void VerifyCSV::on_load_btn_clicked()
{
    // show alert, "are you sure you are done viewing?"
    QMessageBox::StandardButton reload;
    reload = QMessageBox::question(this, "Load New Data",
                                   "Importing new data will lose the current data.\n"
                                   "Would you like to continue?",
                                   QMessageBox::Yes|QMessageBox::No);
    if (reload == QMessageBox::Yes) {
        LoadCSV * load_csv_page = new LoadCSV();
        this->setCentralWidget(load_csv_page);
    }
}
//else do nothing

void VerifyCSV::on_analyze_btn_clicked()
{
    //open the analyze page within the existing window
    analyze_csv_page = new AnalyzeCSV(data);
    this->setCentralWidget(analyze_csv_page);
}

void VerifyCSV::on_ignoreall_btn_clicked()
{
    int size = data->errorRows->size();
    for(int i=0; i< size; i++)
    {
        ui->error_table->hideRow(i);
    }
    data->errorRows->clear();
    data->errorRows->shrink_to_fit();
    enableConfirmChanges();
}


void VerifyCSV::on_ignore_btn_clicked()
{
    QModelIndexList selection = ui->error_table->selectionModel()->selectedRows();

    // Multiple rows can be selected
    for(int i=selection.count()-1; i >= 0; i--)
    {

        QModelIndex index = selection.at(i);
        cout<<"Index: "<<index.data().toString().toStdString()<<endl;
        cout<<"Index row: "<<index.row()<<endl;
        ui->error_table->model()->removeRow(index.row());
        data->errorRows->erase(data->errorRows->begin() + index.row());
    }
    enableConfirmChanges();
}

void VerifyCSV::onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight)
{
    enableConfirmChanges();

}

void VerifyCSV::enableConfirmChanges()
{
    cout << "Cell has been changed"<<endl;
    if (!changesMade)
    {
        changesMade = true;
        ui->confirm_btn->setDisabled(false);
    }
}

void VerifyCSV::on_confirm_btn_clicked()
{
    QModelIndex idx;
    string str;

    /*clear all errors
      then reload all data from the table into errors vector
    */

    cout << "Confirming changes"<<endl;

    for(int i = 0; i < data->errorRows->size(); i++){

        for(int j = 0; j < data->nMan; j++){
            idx = ui->error_table->model()->index(i, j);
            str = ui->error_table->model()->data(idx).toString().toStdString();
            //line.push_back(str);
            (data->errorRows->at(i))[j] = str;
        };
    }
    data->validateErrors();//This is leaving the errors vector empty?

    ui->error_table->setModel(PublicationTableModel());
    //Next: reload model on table (if blank, allow user to proceed to anaylze page)

}
