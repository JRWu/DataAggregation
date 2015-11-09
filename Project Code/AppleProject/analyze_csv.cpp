#include "load_csv.h"
#include "analyze_csv.h"
#include "ui_analyze_csv.h"

std::shared_ptr<CSVData<PublicationDTO>> datanew;

// Create a new pointer the for Teaching CSV data
std::shared_ptr<CSVData<TeachingDTO>> teaching_data_new;


/* Populating the Teaching tab */
AnalyzeCSV::AnalyzeCSV(std::shared_ptr<CSVData<TeachingDTO>> _data, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    // set the pointer to the passed data
    teaching_data_new = _data;


    std::shared_ptr<CSVData<PublicationDTO>> teaching_data = _data;
    ui->setupUi(this);

    /// DOMAIN LABEL SET for Teaching ///
    ui->domain_lbl4->setText(QString::fromStdString(data->dtos->at(0).domain));

    /// DATE FILTER COMBO BOX ///
    QStringList date_strs = PopulateDateCombos(data);

    // set the dates list to the combo boxes
    ui->start_date4->addItems(date_strs);
    ui->start_date4->setCurrentIndex(0);
    ui->end_date4->addItems(date_strs);
    ui->end_date4->setCurrentIndex(date_strs.size()-1);

    // Populate the QTreeWidget item
    populate_publication_tree();

    // PUT THIS IN A FUNCTION vvvvv
    Teach_BarGraph1_VO* graphable = new Teach_BarGraph1_VO(_data, 1900, 4000);
    scene = new QGraphicsScene(this);   // Added for graphics window

    QCustomPlot *customPlot = new QCustomPlot();
    customPlot->setGeometry(0,0,345,375);   // added to resize graph

    // Graph handling functions go here
    Graphvisualizations *graph_handler = new Graphvisualizations();
    graph_handler->plot_teaching_vs_course(customPlot, graphable);

    scene->addWidget(customPlot);   // Add plot to the window & Essential

    ui->graph_area4->setScene(scene);    // Added for graphics & Essential
}

/* Populating the Publications tab */
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

    // Populate the QTreeWidget item
    populate_publication_tree();



    // PUT THIS IN A FUNCTION vvvvv
    Pub_BarGraph1_VO* graphable = new Pub_BarGraph1_VO(_data, 1900, 4000);

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


Ui::AnalyzeCSV* AnalyzeCSV::get_ui_ptr()
{
    return ui;
}

void AnalyzeCSV::on_filter_btn_clicked()
{
    populate_publication_tree();
}

void AnalyzeCSV::on_filter_btn_clicked_teaching()
{
    populate_teaching_tree();
}

/**
 * @brief AnalyzeCSV::populate_publication_tree fills the tree_list_vo with publication info
 * @param p_tree holds the publication info to be written to the QTreeWidget
 */
void AnalyzeCSV::populate_publication_tree()
{
    std::shared_ptr<CSVData<PublicationDTO>> _data = datanew;
    QString st_string = ui->start_date1->itemText(ui->start_date1->currentIndex());
    QString en_string = ui->end_date1->itemText(ui->end_date1->currentIndex());

    long s = stol(st_string.toStdString()); // start date
    long e = stol(en_string.toStdString()); // end date

    // Ensure the retrieved years are in the accepted range
    if (e <= s)
    {
        cout << "Filter dates error" << endl;
    }
    else
    {
        Ui::AnalyzeCSV * tmpUI = get_ui_ptr();

        // Create new tree list from the selcted interval
        tree_list_vo *p_treeNew = new tree_list_vo(_data);
        // Populates the VO , still needs the new params
        p_treeNew->populate_for_publications(_data, (int)s,(int)e);
        tmpUI->pub_tree->clear();

        /// LIST TREE VIEW ///
        tmpUI->pub_tree->setColumnCount(2);
        tmpUI->pub_tree->setColumnWidth(0, 275);
        tmpUI->pub_tree->setHeaderLabels(QStringList() << "Field" << "Total");

        int pubCounter = 0;
        QTreeWidgetItem *root = new QTreeWidgetItem(tmpUI->pub_tree, QStringList() << "Publications" << QString::fromStdString(std::to_string(_data->dtos->size())));
        for (int i = 0; i < p_treeNew->get_parent_set().size(); i ++) // per 12
        {
            cout << i << endl;
            QTreeWidgetItem * child = new QTreeWidgetItem(root, QStringList() << QString::fromStdString(p_treeNew->get_parent_set().at(i).label)
                                                      <<QString::fromStdString(std::to_string((int)p_treeNew->get_parent_set().at(i).num)) );

            vector<string_data_object> tmp = p_treeNew->get_child_set().at(i);
            for (int j = 0; j < tmp.size(); j++)  // per 5?
            {
                new QTreeWidgetItem(child, QStringList() << QString::fromStdString(tmp.at(j).label)
                                << QString::fromStdString(std::to_string((int)tmp.at(j).num)) );
                pubCounter += tmp.at(j).num;
            }
        }
        // expand publications root by default
        tmpUI->pub_tree->expandItem(root);
        /// LIST TREE VIEW ///
        root->setText(1,QString::fromStdString(std::to_string(pubCounter)));    // updates text

        // Create a new graphics scene
        scene = new QGraphicsScene(this);   // Added for graphics window
        Pub_BarGraph1_VO* g = new Pub_BarGraph1_VO(_data, s, e);        // BUG IS BREAKING THIS HERE
        cout << "exit constructor" << endl;
        cout << g->pubTypes.size() << endl;
        cout << g->values.size() << endl;

        QCustomPlot *plot = new QCustomPlot();
        cout << "pass 4" << endl;
        plot->setGeometry(0,0,345,375);   // added to resize graph
        cout << "pass 5" << endl;
        // Graph handling functions go here
        Graphvisualizations *graph_handlerNew = new Graphvisualizations();
        graph_handlerNew->plot_pub_vs_type(plot, g);

        scene->addWidget(plot);   // Add plot to the window & Essential

        ui->graph_area->setScene(scene);    // Added for grpahics & Essential

    }
}

/**
 * @brief AnalyzeCSV::populate_grant_tree fills the tree_list_vo with grant info
 * @param p_tree holds the grant info to be written to QTreeWidget
 */
void AnalyzeCSV::populate_grant_tree()
{

}

/**
 * @brief AnalyzeCSV::populate_teaching_tree fills the tree_list_vo with teaching info
 * @param p_tree holds the teaching info to be written to QTreeWidget
 */
void AnalyzeCSV::populate_teaching_tree()
{

    std::shared_ptr<CSVData<TeachingDTO>> _data = teaching_data_new;

    QString st_string = ui->start_date1->itemText(ui->start_date1->currentIndex());
    QString en_string = ui->end_date1->itemText(ui->end_date1->currentIndex());
    long s = stol(st_string.toStdString()); // start date
    long e = stol(en_string.toStdString()); // end date

    // Ensure the retrieved years are in the accepted range
    if (e <= s)
    {
        cout << "Filter dates error" << endl;
    }
    else
    {

        Ui::AnalyzeCSV * tmpUI = get_ui_ptr();

        // Create new tree list from the selcted interval
        tree_list_vo *p_treeNew = new tree_list_vo(_data);
        // Populates the VO , still needs the new params
        p_treeNew->populate_for_teaching(_data, (int)s,(int)e);
        tmpUI->teach_tree->clear();

        /// LIST TREE VIEW ///
        tmpUI->teach_tree->setColumnCount(2);
        tmpUI->teach_tree->setColumnWidth(0, 275);
        tmpUI->teach_tree->setHeaderLabels(QStringList() << "Program / Course" << "Total Sessions");

        int tCounter = 0;
        QTreeWidgetItem *root = new QTreeWidgetItem(tmpUI->teach_tree, QStringList() << "Teaching" << QString::fromStdString(std::to_string(_data->dtos->size())));
        for (int i = 0; i < p_treeNew->get_parent_set().size(); i ++)
        {
            cout << i << endl;
            QTreeWidgetItem * child = new QTreeWidgetItem(root, QStringList() << QString::fromStdString(p_treeNew->get_parent_set().at(i).label)
                                                      <<QString::fromStdString(std::to_string((int)p_treeNew->get_parent_set().at(i).num)) );

            vector<string_data_object> tmp = p_treeNew->get_child_set().at(i);
            for (int j = 0; j < tmp.size(); j++)
            {
                new QTreeWidgetItem(child, QStringList() << QString::fromStdString(tmp.at(j).label)
                                << QString::fromStdString(std::to_string((int)tmp.at(j).num)) );
                tCounter += tmp.at(j).num;
            }
        }
        // expand the initial root of teachings by default
        tmpUI->teach_tree->expandItem(root);
        /// LIST TREE VIEW ///
        root->setText(1,QString::fromStdString(std::to_string(tCounter)));

        // create a new graphics scene for teachings
        scene = new QGraphicsScene(this);
        Teach_BarGraph1_VO* g = new Teach_BarGraph1_VO(_data, s, e);
        cout << "exit constructor" << endl;
        cout << g->teachingTypes.size() << endl;
        cout << g->values.size() << endl;

        QCustomPlot *plot = new QCustomPlot();
        cout << "pass 4" << endl;
        plot->setGeometry(0,0,345,375);
        cout << "pass 5" << endl;
        // Graph handling functions go here
        Graphvisualizations *graph_handlerNew = new Graphvisualizations();
        graph_handlerNew->plot_teaching_vs_course(plot, g);

        scene->addWidget(plot);   // Add plot to the window & Essential

        ui->graph_area->setScene(scene);    // Added for grpahics & Essential

//    }

}

/**
 * @brief AnalyzeCSV::populate_presentation_tree fills the tree_list_vo with presentation info
 * @param p_tree holds the presentation info to be written to QTreeWidget
 */
void AnalyzeCSV::pouplate_presentation_tree()
{

}
