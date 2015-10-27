#include "load_csv.h"
#include "analyze_csv.h"
#include "ui_analyze_csv.h"

std::shared_ptr<CSVData<PublicationDTO>> datanew;

AnalyzeCSV::AnalyzeCSV(std::shared_ptr<CSVData<PublicationDTO>> _data, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    datanew = _data;

    std::shared_ptr<CSVData<PublicationDTO>> data = _data;
    ui->setupUi(this);

    /// DOMAIN LABEL SET ///
    ui->domain_lbl1->setText(QString::fromStdString(data->dtos->at(0).domain));

    /// DATE FILTER COMBO BOX ///
    QStringList date_strs = PopulateDateCombos(data);

    // set the dates list to the combo boxes
    ui->start_date1->addItems(date_strs);
    ui->start_date1->setCurrentIndex(0);
    ui->end_date1->addItems(date_strs);
    ui->end_date1->setCurrentIndex(date_strs.size()-1);

    tree_list_vo *p_tree = new tree_list_vo(_data);
    cout << "***made new tree***\n";

    // Populates the VO
    p_tree->populate_publication_set(_data);

    //for demonstration purposes only

    /// LIST TREE VIEW ///
    ui->pub_tree->setColumnCount(2);
    ui->pub_tree->setColumnWidth(0, 275);
    ui->pub_tree->setHeaderLabels(QStringList() << "Field" << "Total");

    QTreeWidgetItem *root = new QTreeWidgetItem(ui->pub_tree, QStringList() << "Publications" << QString::fromStdString(std::to_string(_data->dtos->size())));
    for (int i = 0; i < p_tree->get_publication_types().size(); i ++) // per 12
    {
        cout << i << endl;
        QTreeWidgetItem * child = new QTreeWidgetItem(root, QStringList() << QString::fromStdString(p_tree->get_publication_types().at(i))
                                                      <<QString::fromStdString(std::to_string(p_tree->get_publication_type_sums().at(i))) );

        vector<author_number> tmp = p_tree->get_author_name_set().at(i);
        for (int j = 0; j < tmp.size(); j++)  // per 5?
        {
            new QTreeWidgetItem(child, QStringList() << QString::fromStdString(tmp.at(j).author)
                                << QString::fromStdString(std::to_string(tmp.at(j).num)) );
        }
   }
    // expand publications root by default
    ui->pub_tree->expandItem(root);

    /// LIST TREE VIEW ///

    Pub_BarGraph1_VO* graphable = new Pub_BarGraph1_VO(_data);


    // RM THIS vvv LATER
    cout <<"Name: "<< graphable->name << endl;
    cout <<"Values size: "<< graphable->values.size()<< endl;
    cout <<"Years size: "<< graphable->years.size()<< endl;
    cout <<"PubTypes size: "<< graphable->pubTypes.size()<<endl;
    for (int i = 0; i < graphable->years.size(); i++)
    {
        cout << "Years["<<to_string(i)<<"] " << graphable->years.at(i) << endl;
    }
    for (int i = 0; i < graphable->pubTypes.size(); i++)
    {
        cout << "PubTypes["<<std::to_string(i)<<"] " << graphable->pubTypes.at(i) << endl;
    }
    // RM THIS ^^^ LATER


    scene = new QGraphicsScene(this);   // Added for graphics window

    QCustomPlot *customPlot = new QCustomPlot();
    customPlot->setGeometry(0,0,345,375);   // added to resize graph

    // Graph handling functions go here
    Graphvisualizations *graph_handler = new Graphvisualizations();
    graph_handler->plot_pub_vs_type(customPlot, graphable);

    scene->addWidget(customPlot);   // Add plot to the window & Essential
    ui->graph_area->setScene(scene);    // Added for grpahics & Essential



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
    for (int i=0; i < dates.size(); i++)
    {

        ostringstream stream;
        stream << dates.at(i);
        string datestr = stream.str();
        date_strs << QString::fromStdString(datestr);
    }

    return date_strs;
}


void AnalyzeCSV::on_filter_btn_clicked()
{

    std::shared_ptr<CSVData<PublicationDTO>> _data = datanew;

   // get the user selection from the QComboBox
    unsigned long s = ui->start_date1->itemData(ui->start_date1->currentIndex()).toInt();
    unsigned long e = ui->end_date1->itemData(ui->end_date1->currentIndex()).toInt();

    // Ensure the retrieved years are in the accepted range
    if (e <= s) {
        cout << "Filter dates error" << endl;
    }
    else {

        // Create new tree list from the selcted interval
        tree_list_vo *p_treeNew = new tree_list_vo(_data);
        // Populates the VO , still needs the new params
        p_treeNew->populate_publication_set(_data); // (_data, s, e);

        // Create a new graphics scene
        scene = new QGraphicsScene(this);   // Added for graphics window
        Pub_BarGraph1_VO* g = new Pub_BarGraph1_VO(_data);

        QCustomPlot *plot = new QCustomPlot();
        customPlot->setGeometry(0,0,345,375);   // added to resize graph

        // Graph handling functions go here
        Graphvisualizations *graph_handlerNew = new Graphvisualizations();
        graph_handlerNew->plot_pub_vs_type(plot, g);

        scene->addWidget(plot);   // Add plot to the window & Essential
        ui->graph_area->setScene(scene);    // Added for grpahics & Essential

    }
}
