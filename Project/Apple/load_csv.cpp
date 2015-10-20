#include "loadcsv.h"
#include "ui_loadcsv.h"

LoadCSV::LoadCSV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadCSV)
{
    ui->setupUi(this);
}

LoadCSV::~LoadCSV()
{
    delete ui;
}
