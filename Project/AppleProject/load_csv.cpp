#include "load_csv.h"
#include "ui_load_csv.h"

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
