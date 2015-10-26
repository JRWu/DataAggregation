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

    QStringList date_strs = PopulateDateCombos(data);

    // set the dates list to the combo boxes
    ui->start_date1->addItems(date_strs);
    ui->end_date1->addItems(date_strs);


    /// LIST TREE VIEW ///

    ui->pub_tree->setColumnCount(2);
    ui->pub_tree->setHeaderLabels(QStringList() << "Field" << "Total");

    // top item
    QTreeWidgetItem *top1 = new QTreeWidgetItem(ui->pub_tree, QStringList() << "Publications" << "275");
    top1->setExpanded(true);

    // first child
    QTreeWidgetItem *child1 =
                   new QTreeWidgetItem(top1, QStringList() << "Journal Articles" << "82");

    // first's grandchildren.
    new QTreeWidgetItem(child1, QStringList() << "Jean-Luc Picard" << "30");
    new QTreeWidgetItem(child1, QStringList() << "James T. Kirk" << "15");

    // second child
    QTreeWidgetItem *child2 =
                   new QTreeWidgetItem(top1, QStringList() << "Books" << "4");

    // second child's grandchildren.
    new QTreeWidgetItem(child2, QStringList() << "Kathryn Janeway" << "2");
    new QTreeWidgetItem(child2, QStringList() << "Benjamin Lafayette Sisko" << "12");

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

QStringList AnalyzeCSV::PopulateDateCombos(std::shared_ptr<CSVData<PublicationDTO>> data) {
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

    return date_strs;
}

