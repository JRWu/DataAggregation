#include "analyze_csv.h"
#include "ui_analyze_csv.h"

AnalyzeCSV::AnalyzeCSV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    ui->setupUi(this);
}

AnalyzeCSV::~AnalyzeCSV()
{
    delete ui;
}
