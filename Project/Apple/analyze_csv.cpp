#include "analyzecsv.h"
#include "ui_analyzecsv.h"

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
