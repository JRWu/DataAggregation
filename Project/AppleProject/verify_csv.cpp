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

void VerifyCSV::on_analyze_btn_clicked()
{
    //open the analyze page within the existing window
    analyze_csv_page = new AnalyzeCSV();
    this->setCentralWidget(analyze_csv_page);
}
