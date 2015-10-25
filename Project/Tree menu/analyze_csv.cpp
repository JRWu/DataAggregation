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

    QCustomPlot *customPlot = new QCustomPlot();
    customPlot->setGeometry(0,0,350,200);   // added to resize graph
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    customPlot->xAxis->setRange(-1, 1);
    customPlot->yAxis->setRange(0, 1);
    customPlot->replot();

    scene->addWidget(customPlot);   // Add plot to the window & Essential
//    scene->update();                // Draw updated plot  (Nonessential)
    ui->graph_area->setScene(scene);    // Added for grpahics & Essential
//    ui->graph_area->update();           // Draw updated plot  (nonessential)

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

