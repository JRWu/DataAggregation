#include "View/load_csv.h"
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

    // Empty data pointer accessible to the verify class
    data_pub = shared_ptr<CSVData<PublicationDTO>>(new CSVData<PublicationDTO>);
    data_pres = shared_ptr<CSVData<PresentationDTO>>(new CSVData<PresentationDTO>);
    data_teach = shared_ptr<CSVData<TeachingDTO>>(new CSVData<TeachingDTO>);
    data_grant = shared_ptr<CSVData<GrantDTO>>(new CSVData<GrantDTO>);


    // Assemble data from a given file and store in a data pointer
    switch(dtoType) {
        case 1:
            assembled = AssembleData(data_pub,filename.toStdString());
            break;
        case 4:
            assembled = AssembleData(data_pres,filename.toStdString());
            break;
        case 5:
            assembled = AssembleData(data_teach,filename.toStdString());
            break;

        case 6:
            assembled = AssembleData(data_grant,filename.toStdString());
            break;
    }
    if (assembled)
    {
        // Set the table model (currently only the publication model possible)
        ui->error_table->setModel(PublicationTableModel());

        // Connect the table model to a signal/slot to listen for changes to the table data
        connect(ui->error_table->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChanged(const QModelIndex&, const QModelIndex&)));

        // Display the file name
        ui->file_name->setText(filename);

        // Disable specific buttons to control user flow
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
        // Set headers
        size_t i;

        if(dtoType == 1) {
            // Define a model with the number of rows as error lines, and columns as mandatory columns
            QStandardItemModel *model = new QStandardItemModel(data_pub->errorRows->size(),data_pub->nMan,NULL);

            for (i = 0; i < data_pub->nMan; i++)
            {
             model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(data_pub->header->at(i))));
            }

            // Loop through strings and add each to the table model
            for(i = 0; i < data_pub->errorRows->size(); i++){
                vector<string> line = data_pub->errorRows->at(i);
                for(size_t j = 0; j < data_pub->nMan; j++){
                    QString qstr = QString::fromStdString(line[j]);
                    QStandardItem *newRow = new QStandardItem(qstr);
                    model->setItem(i,j,newRow);
                };
            }
            return model;

        } else if(dtoType == 4) {
            // Define a model with the number of rows as error lines, and columns as mandatory columns
            QStandardItemModel *model = new QStandardItemModel(data_pres->errorRows->size(),data_pres->nMan,NULL);

            for (i = 0; i < data_pres->nMan;i++)
            {
             model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(data_pres->header->at(i))));
            }

            // Loop through strings and add each to the table model
            for(i = 0; i < data_pres->errorRows->size(); i++){
                vector<string> line = data_pres->errorRows->at(i);
                for(size_t j = 0; j < data_pres->nMan; j++){
                    QString qstr = QString::fromStdString(line[j]);
                    QStandardItem *newRow = new QStandardItem(qstr);
                    model->setItem(i,j,newRow);
                };
            }
            return model;

        } else if (dtoType == 5) {
            QStandardItemModel *model = new QStandardItemModel(data_teach->errorRows->size(),data_teach->nMan,NULL);

            for (i = 0; i < data_teach->nMan;i++) {
                model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(data_teach->header->at(i))));
            }

            for(i = 0; i < data_teach->errorRows->size(); i++) {
                vector<string> line = data_teach->errorRows->at(i);
                for(size_t j = 0; j < data_teach->nMan; j++) {
                    QString qstr = QString::fromStdString(line[j]);
                    QStandardItem *newRow = new QStandardItem(qstr);
                    model->setItem(i,j,newRow);
                };
            }
            return model;

        }else if(dtoType == 6) {

            // Define a model with the number of rows as error lines, and columns as mandatory columns
            QStandardItemModel *model = new QStandardItemModel(data_grant->errorRows->size(),data_grant->nMan,NULL);

            for (i = 0; i < data_grant->nMan;i++){
                model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(data_grant->header->at(i))));
            }

            // Loop through strings and add each to the table model
            for(i = 0; i < data_grant->errorRows->size(); i++){
                vector<string> line = data_grant->errorRows->at(i);
                for(int j = 0; j < data_grant->nMan; j++){
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
    ui->confirm_btn->setDisabled(false);
}

/*SLOTS*/

void VerifyCSV::on_load_btn_clicked()
{
    // Show alert, "are you sure you are done viewing?"
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


void VerifyCSV::on_analyze_btn_clicked()
{
    // Open the analyze page within the existing window
    if(dtoType == 1){
        analyze_csv_page = new AnalyzeCSV(data_pub);
    } else if (dtoType == 4){
        analyze_csv_page = new AnalyzeCSV(data_pres);
    } else if (dtoType == 5) {
        analyze_csv_page = new AnalyzeCSV(data_teach);
    } else if (dtoType == 6){
        analyze_csv_page = new AnalyzeCSV(data_grant);
    }

    this->setCentralWidget(analyze_csv_page);
}

void VerifyCSV::on_ignoreall_btn_clicked()
{
    // Remove all errors from the table and errors list
    if(dtoType == 1){
        ui->error_table->model()->removeRows(0,data_pub->errorRows->size());
        data_pub->errorRows->clear();
        data_pub->errorRows->shrink_to_fit();
    } else if (dtoType == 4) {
        ui->error_table->model()->removeRows(0,data_pres->errorRows->size());
        data_pres->errorRows->clear();
        data_pres->errorRows->shrink_to_fit();
    } else if (dtoType == 5) {
        ui->error_table->model()->removeRows(0,data_teach->errorRows->size());
        data_teach->errorRows->clear();
        data_teach->errorRows->shrink_to_fit();
    }
    else if (dtoType == 6) {
        ui->error_table->model()->removeRows(0,data_grant->errorRows->size());
        data_grant->errorRows->clear();
        data_grant->errorRows->shrink_to_fit();
    }

    enableConfirmChanges();
}

void VerifyCSV::on_ignore_btn_clicked()
{
    QModelIndexList selection = ui->error_table->selectionModel()->selectedRows();

    // For each row the user has selected, remove the rows from bottom up
    // Removing bottom up prevents any shifting of indexes
    for(int i=selection.count()-1; i >= 0; i--)
    {
        QModelIndex index = selection.at(i);
        ui->error_table->model()->removeRow(index.row());
        if(dtoType == 1) {
            data_pub->errorRows->erase(data_pub->errorRows->begin() + index.row());
        } else if (dtoType == 4) {
            data_pres->errorRows->erase(data_pres->errorRows->begin() + index.row());
        } else if (dtoType == 5) {
            data_teach->errorRows->erase(data_teach->errorRows->begin() + index.row());
        }else if (dtoType == 6) {
            data_grant->errorRows->erase(data_grant->errorRows->begin() + index.row());
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
        // Clear all errors then reload all data from the table into errors vector
        for(size_t i = 0; i < data_pub->errorRows->size(); i++){
            for(int j = 0; j < data_pub->nMan; j++){
                idx = ui->error_table->model()->index(i, j);
                str = ui->error_table->model()->data(idx).toString().toStdString();
                (data_pub->errorRows->at(i))[j] = str;
            };
        }
        // Validate errors, corrected errors will move to dtos, uncorrected remain as errors
        data_pub->validateErrors();

        // Reload the model onto the table, remaining errors will display
        ui->error_table->setModel(PublicationTableModel());

        // If all errors have been either corrected or ignored, the user may proceed to the analyze page
        if (data_pub->errorRows->size() == 0)
        {
            ui->analyze_btn->setDisabled(false);
        }
    }
    else if(dtoType == 4) {
        // Clear all errors then reload all data from the table into errors vector
        for(size_t i = 0; i < data_pres->errorRows->size(); i++){
            for(int j = 0; j < data_pres->nMan; j++){
                idx = ui->error_table->model()->index(i, j);
                str = ui->error_table->model()->data(idx).toString().toStdString();
                (data_pres->errorRows->at(i))[j] = str;
            };
        }
        // Validate errors, corrected errors will move to dtos, uncorrected remain as errors
        data_pres->validateErrors();

        // Reload the model onto the table, remaining errors will display
        ui->error_table->setModel(PublicationTableModel());

        // If all errors have been either corrected or ignored, the user may proceed to the analyze page
        if (data_pres->errorRows->size() == 0)
        {
            ui->analyze_btn->setDisabled(false);
        }
    } else if (dtoType == 5) {
        // Clear all errors then reload all data from the table into errors vector
        for(size_t i = 0; i < data_teach->errorRows->size(); i++){
            for(int j = 0; j < data_teach->nMan; j++){
                idx = ui->error_table->model()->index(i, j);
                str = ui->error_table->model()->data(idx).toString().toStdString();
                (data_teach->errorRows->at(i))[j] = str;
            };
        }
        // Validate errors, corrected errors will move to dtos, uncorrected remain as errors
        data_teach->validateErrors();

        // Reload the model onto the table, remaining errors will display
        ui->error_table->setModel(PublicationTableModel());

        // If all errors have been either corrected or ignored, the user may proceed to the analyze page
        if (data_teach->errorRows->size() == 0)
        {
            ui->analyze_btn->setDisabled(false);
        }
    } else if(dtoType == 6) {
        // Clear all errors then reload all data from the table into errors vector
        for(size_t i = 0; i < data_grant->errorRows->size(); i++){
            for(int j = 0; j < data_grant->nMan; j++){
                idx = ui->error_table->model()->index(i, j);
                str = ui->error_table->model()->data(idx).toString().toStdString();
                (data_grant->errorRows->at(i))[j] = str;
            };
        }
        // Validate errors, corrected errors will move to dtos, uncorrected remain as errors
        data_grant->validateErrors();

        // Reload the model onto the table, remaining errors will display
        ui->error_table->setModel(PublicationTableModel());

        // If all errors have been either corrected or ignored, the user may proceed to the analyze page
        if (data_grant->errorRows->size() == 0)
        {
            ui->analyze_btn->setDisabled(false);
        }
    }

    // Reset confirm changes button
    ui->confirm_btn->setDisabled(true);

    // Connect the table model to a signal/slot to listen for changes to the table data
    connect(ui->error_table->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChanged(const QModelIndex&, const QModelIndex&)));
}
