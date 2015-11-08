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

    //empty data pointer accessible to the verify class
    data = shared_ptr<CSVData<PublicationDTO>>(new CSVData<PublicationDTO>);
    gdata = shared_ptr<CSVData<GrantDTO>>(new CSVData<GrantDTO>);

    //Assemble data from a given file and store in a data pointer
    if (AssembleData(data,filename.toStdString()))
    {
        //Set the table model (currently only the publication model possible)
        ui->error_table->setModel(PublicationTableModel());

        //Connect the table model to a signal/slot to listen for changes to the table data
        connect(ui->error_table->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChanged(const QModelIndex&, const QModelIndex&)));

        //display the file name
        ui->file_name->setText(filename);

        //Disable specific buttons to control user flow
        changesMade = false;
        ui->confirm_btn->setDisabled(true);
        ui->analyze_btn->setDisabled(true);
    }
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
        size_t i;
        for (i = 0; i < data->nMan;i++)
        {
            model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(data->header->at(i))));
        }

        /*loop through strings and add each to the table model*/
        for(i = 0; i < data->errorRows->size(); i++){
            vector<string> line = data->errorRows->at(i);
            for(size_t j = 0; j < data->nMan; j++){
                QString qstr = QString::fromStdString(line[j]);
                QStandardItem *newRow = new QStandardItem(qstr);
                model->setItem(i,j,newRow);
            };
        }
        return model;
}

QStandardItemModel* VerifyCSV::GrantTableModel()
{
    /*define a model with the number of rows as error lines, and columns as mandatory columns*/
    QStandardItemModel *model = new QStandardItemModel(data->errorRows->size(),data->nMan,NULL);
    
    //Set headers
    size_t i;
    for (i = 0; i < data->nMan;i++)
    {
        model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(data->header->at(i))));
    }
    
    /*loop through strings and add each to the table model*/
    for(i = 0; i < data->errorRows->size(); i++){
        vector<string> line = data->errorRows->at(i);
        for(size_t j = 0; j < data->nMan; j++){
            QString qstr = QString::fromStdString(line[j]);
            QStandardItem *newRow = new QStandardItem(qstr);
            model->setItem(i,j,newRow);
        };
    }
    return model;
}


void VerifyCSV::enableConfirmChanges()
{
    if (!changesMade)
    {
        changesMade = true;
        ui->confirm_btn->setDisabled(false);
    }
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
    //Remove all errors from the table and errors list
    ui->error_table->model()->removeRows(0,data->errorRows->size());
    data->errorRows->clear();
    data->errorRows->shrink_to_fit();
    enableConfirmChanges();
}

void VerifyCSV::on_ignore_btn_clicked()
{
    QModelIndexList selection = ui->error_table->selectionModel()->selectedRows();

    //For each row the user has selected, remove the rows from bottom up
    //Removing bottom up prevents any shifting of indexes
    for(int i=selection.count()-1; i >= 0; i--)
    {
        QModelIndex index = selection.at(i);
        ui->error_table->model()->removeRow(index.row());
        data->errorRows->erase(data->errorRows->begin() + index.row());
    }
    enableConfirmChanges();
}

void VerifyCSV::onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight)
{
    enableConfirmChanges();
}

void VerifyCSV::on_confirm_btn_clicked()
{
    QModelIndex idx;
    string str;

    /*clear all errors
      then reload all data from the table into errors vector*/
    for(size_t i = 0; i < data->errorRows->size(); i++){
        for(size_t j = 0; j < data->nMan; j++){
            idx = ui->error_table->model()->index(i, j);
            str = ui->error_table->model()->data(idx).toString().toStdString();
            (data->errorRows->at(i))[j] = str;
        };
    }
    //Validate errors, corrected errors will move to dtos, uncorrected remain as errors
    data->validateErrors();

    //Reload the model onto the table, remaining errors will display
    ui->error_table->setModel(PublicationTableModel());

    //Reset confirm changes button
    changesMade = false;
    ui->confirm_btn->setDisabled(true);

    //If all errors have been either corrected or ignored, the user may proceed to the analyze page
    if (data->errorRows->size() == 0)
    {
        ui->analyze_btn->setDisabled(false);
    }
}
