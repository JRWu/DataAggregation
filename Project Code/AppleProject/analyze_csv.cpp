#include "load_csv.h"
#include "analyze_csv.h"
#include "ui_analyze_csv.h"

AnalyzeCSV::AnalyzeCSV(std::shared_ptr<CSVData<PublicationDTO>> _data, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    std::shared_ptr<CSVData<PublicationDTO>> data = _data;
    ui->setupUi(this);

    //Just checking to see if data passed through
    cout<<"Data: "<<_data->dtos->size();

    scene = new QGraphicsScene(this);   // Added for graphics window

    QCustomPlot *customPlot = new QCustomPlot();
    customPlot->setGeometry(0,0,345,375);   // added to resize graph

    // Graph handling functions go here
    Graphvisualizations *graph_handler = new Graphvisualizations();
    graph_handler->plot_pub_vs_type(customPlot);

    scene->addWidget(customPlot);   // Add plot to the window & Essential
    ui->graph_area->setScene(scene);    // Added for grpahics & Essential

    /// DOMAIN LABEL SET ///

    ui->domain_lbl1->setText(QString::fromStdString(data->dtos->at(0).domain));

    /// DATE FILTER COMBO BOX ///

        /* algorithm for adding implementing this
         * loop through the dtolist and if there is a unique year,
         * then add it to the combo list
         * perform a sort on the list
         */

        //for demonstration purposes only
    std::vector<int> dates;

    // loop through the dtos to get a list of dates
    for (int i=0; i < data->dtos->size(); i++) {
        // loop again to see if the current date is already in the list
        if (dates.empty()) {
            dates.push_back((int)data->dtos->at(i).date);
        }else {
            bool add = true;
            for (int j=0; j < dates.size(); j++) {
                // if it isn't add it to the list
                if ((int)data->dtos->at(i).date == dates.at(j)) {
                    add = false;
                    break;
                }
            }
            if (add) {
                dates.push_back((int)data->dtos->at(i).date);
            }
        }
    }

    //sort the dates
    std::sort(dates.begin(), dates.end());

    //put the dates in a QString vector list
    QStringList date_strs;
    for (int i=0; i < dates.size(); i++) {
        string datestr = static_cast<ostringstream*>( &(ostringstream() << dates.at(i)) )->str();
        date_strs << QString::fromStdString(datestr);
    }
    // set the dates list to the combo boxes
    ui->start_date1->addItems(date_strs);
    ui->end_date1->addItems(date_strs);


    /// LIST TREE VIEW ///

        ui->pub_tree->setColumnCount(2);
        ui->pub_tree->setHeaderLabels(QStringList() << "Field" << "Total");

        /* algorithm for implementing this
         * create a view object type which has a list of publication types,
         * which each item in the list has a list of authors
         * then loop through the list of types, and for each one add all the children to the list
         */

        AddRoot("Publications", "275");

        // for demonstration purposes, here is a tree vie example
        AddChild(ui->pub_tree->topLevelItem(0), "Journal Articles", "82");

        AddGrandChild(ui->pub_tree->itemBelow(ui->pub_tree->topLevelItem(0)), "Jean-Luc Picard", "30");
        AddGrandChild(ui->pub_tree->itemBelow(ui->pub_tree->topLevelItem(0)), "James T. Kirk", "15");
        AddGrandChild(ui->pub_tree->itemBelow(ui->pub_tree->topLevelItem(0)), "Kathryn Janeway", "25");
        AddGrandChild(ui->pub_tree->itemBelow(ui->pub_tree->topLevelItem(0)), "Benjamin Lafayette Sisko", "12");

        AddChild(ui->pub_tree->topLevelItem(0), "Books", "4");
        AddChild(ui->pub_tree->topLevelItem(0), "Book Chapters", "20");
        AddChild(ui->pub_tree->topLevelItem(0), "Letters to Editor", "19");
}

AnalyzeCSV::~AnalyzeCSV()
{
    delete ui;
}

void AnalyzeCSV::on_load_btn_clicked()
{
    // show alert, "are you sure you are done viewing?"
    QMessageBox::StandardButton reload;
    reload = QMessageBox::question(this, "Load New Data",
                                   "Importing new data will lose the current data.\n"
                                   "Would you like to continue?",
                                   QMessageBox::Yes|QMessageBox::No);
    if (reload == QMessageBox::Yes) {
        LoadCSV * load_csv_page = new LoadCSV();
        this->setCentralWidget(load_csv_page);
    }
    //else do nothing
}

void AnalyzeCSV::on_verify_btn_clicked()
{
    // show alert, "Information has already been verified. Would you like to import new information?"
    QMessageBox::StandardButton reload;
    reload = QMessageBox::question(this, "Already Verified",
                                   "Information has already been verified.\n"
                                   "Would you like to import new information?",
                                   QMessageBox::Yes|QMessageBox::No);
    if (reload == QMessageBox::Yes) {
        LoadCSV * load_csv_page = new LoadCSV();
        this->setCentralWidget(load_csv_page);
    }
    //else do nothing
}

void AnalyzeCSV::AddRoot(QString field, QString total) {
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->pub_tree);
    root->setText(0, field);
    root->setText(1, total);
    root->setExpanded(true);

    ui->pub_tree->addTopLevelItem(root);
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

