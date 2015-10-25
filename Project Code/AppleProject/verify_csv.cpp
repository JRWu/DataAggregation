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
}

VerifyCSV::~VerifyCSV()
{
    delete ui;
}

void VerifyCSV::on_analyze_btn_clicked()
{
    //open the analyze page within the existing window
    analyze_csv_page = new AnalyzeCSV(data);
    this->setCentralWidget(analyze_csv_page);
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

