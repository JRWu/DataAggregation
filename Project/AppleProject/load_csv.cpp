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

void LoadCSV::on_verify_btn_clicked()
{
    //open the verify page within the existing window
    verify_csv_page = new VerifyCSV();
    this->setCentralWidget(verify_csv_page);
}

void LoadCSV::on_analyze_btn_clicked()
{
    //open the analyze page within the existing window
    analyze_csv_page = new AnalyzeCSV();
    this->setCentralWidget(analyze_csv_page);
}
