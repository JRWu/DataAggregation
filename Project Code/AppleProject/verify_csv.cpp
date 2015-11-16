#include "load_csv.h"
#include "verify_csv.h"
#include "ui_verify_csv.h"
#include "publicationdto.h"
#include <QtWidgets>
#include <iostream>
#include "csvdataassembler.h"


VerifyCSV::VerifyCSV(QString filename, int csvType, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VerifyCSV)
{
    ui->setupUi(this);

    dtoType = csvType;

    //empty data pointer accessible to the verify class
    data = shared_ptr<CSVData<PublicationDTO>>(new CSVData<PublicationDTO>);
    gdata = shared_ptr<CSVData<GrantDTO>>(new CSVData<GrantDTO>);
    data4 = shared_ptr<CSVData<PresentationDTO>>(new CSVData<PresentationDTO>);
    datat = shared_ptr<CSVData<TeachingDTO>>(new CSVData<TeachingDTO>);


    //Assemble data from a given file and store in a data pointer
    switch(dtoType) {
        case 1:
            assembled = AssembleData(data,filename.toStdString());
            break;
        case 4:
            assembled = AssembleData(data4,filename.toStdString());
            break;
        case 5:
            assembled = AssembleData(datat,filename.toStdString());
            break;

        case 6:
            assembled = AssembleData(gdata,filename.toStdString());
            break;
    }
    if (assembled)
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
        //Set headers
        size_t i;
    
        if(dtoType == 1) {
            /*define a model with the number of rows as error lines, and columns as mandatory columns*/
            QStandardItemModel *model = new QStandardItemModel(data->errorRows->size(),data->nMan,NULL);

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
            
        } else if(dtoType == 4) {
            /*define a model with the number of rows as error lines, and columns as mandatory columns*/
            QStandardItemModel *model = new QStandardItemModel(data4->errorRows->size(),data4->nMan,NULL);

            for (i = 0; i < data4->nMan;i++)
            {
             model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(data4->header->at(i))));
            }

            /*loop through strings and add each to the table model*/
            for(i = 0; i < data4->errorRows->size(); i++){
                vector<string> line = data4->errorRows->at(i);
                for(size_t j = 0; j < data4->nMan; j++){
                    QString qstr = QString::fromStdString(line[j]);
                    QStandardItem *newRow = new QStandardItem(qstr);
                    model->setItem(i,j,newRow);
                };
            }
            return model;
            
        } else if (dtoType == 5) {
            QStandardItemModel *model = new QStandardItemModel(datat->errorRows->size(),datat->nMan,NULL);

            for (i = 0; i < datat->nMan;i++) {
                model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(datat->header->at(i))));
            }

            for(i = 0; i < datat->errorRows->size(); i++) {
                vector<string> line = datat->errorRows->at(i);
                for(size_t j = 0; j < datat->nMan; j++) {
                    QString qstr = QString::fromStdString(line[j]);
                    QStandardItem *newRow = new QStandardItem(qstr);
                    model->setItem(i,j,newRow);
                };
            }
            return model;
            
        }else if(dtoType == 6) {

            /*define a model with the number of rows as error lines, and columns as mandatory columns*/
            QStandardItemModel *model = new QStandardItemModel(gdata->errorRows->size(),gdata->nMan,NULL);

            for (i = 0; i < gdata->nMan;i++){
                model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(gdata->header->at(i))));
            }

            /*loop through strings and add each to the table model*/
            for(i = 0; i < gdata->errorRows->size(); i++){
                vector<string> line = gdata->errorRows->at(i);
                for(size_t j = 0; j < gdata->nMan; j++){
                    QString qstr = QString::fromStdString(line[j]);
                    QStandardItem *newRow = new QStandardItem(qstr);
                    model->setItem(i,j,newRow);
                };
            }
            return model;
        }

  return NULL;
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
    if(dtoType == 1){
        analyze_csv_page = new AnalyzeCSV(data);
    } else if (dtoType == 4){
        analyze_csv_page = new AnalyzeCSV(data4);
    } else if (dtoType == 5) {
        analyze_csv_page = new AnalyzeCSV(datat);
    } else if (dtoType == 6){
        analyze_csv_page = new AnalyzeCSV(gdata);
    }

    this->setCentralWidget(analyze_csv_page);
}

void VerifyCSV::on_ignoreall_btn_clicked()
{
    if(dtoType == 1){
        //Remove all errors from the table and errors list
        ui->error_table->model()->removeRows(0,data->errorRows->size());
        data->errorRows->clear();
        data->errorRows->shrink_to_fit();
    } else if (dtoType == 4) {
        //Remove all errors from the table and errors list
        ui->error_table->model()->removeRows(0,data4->errorRows->size());
        data4->errorRows->clear();
        data4->errorRows->shrink_to_fit();
    } else if (dtoType == 5) {
        ui->error_table->model()->removeRows(0,datat->errorRows->size());
        datat->errorRows->clear();
        datat->errorRows->shrink_to_fit();
    }
    else if (dtoType == 6) {
        //Remove all errors from the table and errors list
        ui->error_table->model()->removeRows(0,gdata->errorRows->size());
        gdata->errorRows->clear();
        gdata->errorRows->shrink_to_fit();
    }
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
        if(dtoType == 1) {
            data->errorRows->erase(data->errorRows->begin() + index.row());
        } else if (dtoType == 4) {
            data4->errorRows->erase(data4->errorRows->begin() + index.row());
        } else if (dtoType == 5) {
            datat->errorRows->erase(datat->errorRows->begin() + index.row());
        }else if (dtoType == 6) {
            gdata->errorRows->erase(gdata->errorRows->begin() + index.row());
        }
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

    if(dtoType == 1) {
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
    else if(dtoType == 4) {
        /*clear all errors
       then reload all data from the table into errors vector*/
        for(size_t i = 0; i < data4->errorRows->size(); i++){
            for(size_t j = 0; j < data4->nMan; j++){
                idx = ui->error_table->model()->index(i, j);
                str = ui->error_table->model()->data(idx).toString().toStdString();
                (data4->errorRows->at(i))[j] = str;
            };
        }
        //Validate errors, corrected errors will move to dtos, uncorrected remain as errors
        data4->validateErrors();

        //Reload the model onto the table, remaining errors will display
        ui->error_table->setModel(PublicationTableModel());

        //Reset confirm changes button
        changesMade = false;
        ui->confirm_btn->setDisabled(true);

        //If all errors have been either corrected or ignored, the user may proceed to the analyze page
        if (data4->errorRows->size() == 0)
        {
            ui->analyze_btn->setDisabled(false);
        }
    } else if (dtoType == 5) {
        for(size_t i = 0; i < datat->errorRows->size(); i++){
            for(size_t j = 0; j < datat->nMan; j++){
                idx = ui->error_table->model()->index(i, j);
                str = ui->error_table->model()->data(idx).toString().toStdString();
                (datat->errorRows->at(i))[j] = str;
            };
        }
        datat->validateErrors();

        ui->error_table->setModel(PublicationTableModel());

        changesMade = false;
        ui->confirm_btn->setDisabled(true);

        if (datat->errorRows->size() == 0)
        {
            ui->analyze_btn->setDisabled(false);
        }
    } else if(dtoType == 6) {
        /*clear all errors
       then reload all data from the table into errors vector*/
        for(size_t i = 0; i < gdata->errorRows->size(); i++){
            for(size_t j = 0; j < gdata->nMan; j++){
                idx = ui->error_table->model()->index(i, j);
                str = ui->error_table->model()->data(idx).toString().toStdString();
                (gdata->errorRows->at(i))[j] = str;
            };
        }
        //Validate errors, corrected errors will move to dtos, uncorrected remain as errors
        gdata->validateErrors();

        //Reload the model onto the table, remaining errors will display
        ui->error_table->setModel(PublicationTableModel());

        //Reset confirm changes button
        changesMade = false;
        ui->confirm_btn->setDisabled(true);

        //If all errors have been either corrected or ignored, the user may proceed to the analyze page
        if (gdata->errorRows->size() == 0)
        {
            ui->analyze_btn->setDisabled(false);
        }
    }
}
