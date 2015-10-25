#include "analyze_csv.h"
#include "ui_analyze_csv.h"

AnalyzeCSV::AnalyzeCSV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);   // Added for graphics window

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

    // list tree
    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(QStringList() << "Field" << "Total");

    AddRoot("Publications", "275");

    /* algorithm for implementing this
     * create a view object type which is a has a list of publication types,
     * which each item in the list has a list of authors
     * then loop through the list of types, and for each one add all the children to the list
     */

    // for demonstration purposes, here is a tree vie example
    AddChild(ui->treeWidget->topLevelItem(0), "Journal Articles", "82");

    AddGrandChild(ui->treeWidget->itemBelow(ui->treeWidget->topLevelItem(0)), "Jean-Luc Picard", "30");
    AddGrandChild(ui->treeWidget->itemBelow(ui->treeWidget->topLevelItem(0)), "James T. Kirk", "15");
    AddGrandChild(ui->treeWidget->itemBelow(ui->treeWidget->topLevelItem(0)), "Kathryn Janeway", "25");
    AddGrandChild(ui->treeWidget->itemBelow(ui->treeWidget->topLevelItem(0)), "Benjamin Lafayette Sisko", "12");

    AddChild(ui->treeWidget->topLevelItem(0), "Books", "4");
    AddChild(ui->treeWidget->topLevelItem(0), "Book Chapters", "20");
    AddChild(ui->treeWidget->topLevelItem(0), "Letters to Editor", "19");
}

AnalyzeCSV::~AnalyzeCSV()
{
    delete ui;
}

void AnalyzeCSV::on_verify_btn_clicked()
{
    // show alert, "Information has already been verified. Would you like to import new information?"

}

void AnalyzeCSV::AddRoot(QString field, QString total) {
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
    root->setText(0, field);
    root->setText(1, total);
    root->setExpanded(true);

    ui->treeWidget->addTopLevelItem(root);
}

void AnalyzeCSV::AddChild(QTreeWidgetItem *parent, QString field, QString total) {
    QTreeWidgetItem *child = new QTreeWidgetItem();
    child->setText(0, field);
    child->setText(1, total);
    parent->addChild(child);
}

void AnalyzeCSV::AddGrandChild(QTreeWidgetItem *parent, QString field, QString total) {
    QTreeWidgetItem *grandchild = new QTreeWidgetItem();
    grandchild->setText(0, field);
    grandchild->setText(1, total);
    parent->addChild(grandchild);
}

