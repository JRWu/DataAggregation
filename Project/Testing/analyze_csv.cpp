#include "analyze_csv.h"
#include "ui_analyze_csv.h"

AnalyzeCSV::AnalyzeCSV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);   // Added for graphics window
    ui->statusbar->close(); // Remove redundant bar

    // check height/width of graph area
    int height = ui->graph_area->geometry().height();
    int width = ui->graph_area->geometry().width();
    std::cout <<"height: "<< height << "\n";
    std::cout <<"width: "<< width << "\n";
    // check height/width of graph area

    
    // Confirm box height
    height = scene->height();
    width = scene->width();
    width = ui->graph_area->geometry().width();
    std::cout <<"sheight: "<< height << "\n";
    std::cout <<"swidth: "<< width << "\n";
    // Confirm box height
}

AnalyzeCSV::~AnalyzeCSV()
{
    delete ui;
}

void AnalyzeCSV::on_verify_btn_clicked()
{
    // show alert, "Information has already been verified. Would you like to import new information?"

}

