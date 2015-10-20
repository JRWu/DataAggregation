#include "verify_csv.h"
#include "ui_verify_csv.h"

VerifyCSV::VerifyCSV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VerifyCSV)
{
    ui->setupUi(this);
}

VerifyCSV::~VerifyCSV()
{
    delete ui;
}
