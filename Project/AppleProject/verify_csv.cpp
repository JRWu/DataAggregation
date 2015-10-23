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

void VerifyCSV::on_load_btn_clicked()
{
    // show alert "Are you sure you want to lose your current progress?"

    // if returns true, open Load page

    // if returns false, stay on page

}

void VerifyCSV::on_analyze_btn_clicked()
{
    // check that all errors have been resolved
    // error list empty (??)

    // if true, proceed to analyze page


    // show alert "Please verify all errors before proceeding"
    // stay on page

}
