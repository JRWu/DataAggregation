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

    ui->error_table->setModel(PublicationTableModel(filename));
    select = ui->error_table->selectionModel();
}

VerifyCSV::~VerifyCSV()
{
    delete ui;
}

void VerifyCSV::on_load_btn_clicked()
{
    //open the verify page within the existing window
    LoadCSV * load_csv_page = new LoadCSV();
    this->setCentralWidget(load_csv_page);
}

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
        data->errorRows->erase(data->errorRows->begin() + i);
    }

}


void VerifyCSV::on_ignore_btn_clicked()
{
    QModelIndexList selection = ui->error_table->selectionModel()->selectedRows();

    // Multiple rows can be selected
    for(int i=0; i< selection.count(); i++)
    {
        QModelIndex index = selection.at(i);
        ui->error_table->hideRow(index.row());
        data->errorRows->erase(data->errorRows->begin() + index.row());

    }
}

QStandardItemModel* VerifyCSV::PublicationTableModel(QString filename)
{

    data = shared_ptr<CSVData<PublicationDTO>>(new CSVData<PublicationDTO>);

    /*REPLACE this file with filename from load page selector*/
    bool success = AssembleData(data,filename.toStdString());

    if (success)
    {
        /*define a model with the number of rows as error lines, and columns as mandatory columns*/
        QStandardItemModel *model = new QStandardItemModel(data->errorRows->size(),data->nMan,NULL);

        //Set headers
        for (int i = 0; i < 27;i++)
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
    return NULL;
}
