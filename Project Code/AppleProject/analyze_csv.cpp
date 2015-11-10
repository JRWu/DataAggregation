#include "load_csv.h"
#include "analyze_csv.h"
#include "ui_analyze_csv.h"

std::shared_ptr<CSVData<PublicationDTO>> datanew;
std::shared_ptr<CSVData<PublicationDTO>> datanew4; //presentation data
// Create a new pointer the for Teaching CSV data
std::shared_ptr<CSVData<TeachingDTO>> teaching_data_new;
std::shared_ptr<CSVData<GrantDTO>> gdatanew;

/* Populating the Teaching tab */
AnalyzeCSV::AnalyzeCSV(std::shared_ptr<CSVData<TeachingDTO>> _data, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    // set the pointer to the passed data
    teaching_data_new = _data;


    std::shared_ptr<CSVData<TeachingDTO>> teaching_data = _data;
    ui->setupUi(this);

    /// DOMAIN LABEL SET for Teaching ///
    ui->domain_lbl_teach->setText(QString::fromStdString(data->dtos->at(0).domain));

    /// DATE FILTER COMBO BOX ///
    QStringList date_strs = PopulateDateCombos(data);

    // set the dates list to the combo boxes



    ui->start_date_teach->addItems(date_strs);
    ui->start_date_teach->setCurrentIndex(0);
    ui->end_date_teach->addItems(date_strs);
    ui->end_date_teach->setCurrentIndex(date_strs.size()-1);






    // Populate the QTreeWidget item
    populate_teaching_tree();

    // PUT THIS IN A FUNCTION vvvvv
    Teach_BarGraph1_VO* graphable = new Teach_BarGraph1_VO(_data, 1900, 4000);
    scene = new QGraphicsScene(this);   // Added for graphics window

    QCustomPlot *customPlot = new QCustomPlot();
    customPlot->setGeometry(0,0,345,375);   // added to resize graph

    // Graph handling functions go here
    Graphvisualizations *graph_handler = new Graphvisualizations();
    graph_handler->plot_teaching_vs_course(customPlot, graphable);

    scene->addWidget(customPlot);   // Add plot to the window & Essential

    ui->graph_area_teach->setScene(scene);    // Added for graphics & Essential
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
    ui->start_date_publications->addItems(date_strs);
    ui->start_date_publications->setCurrentIndex(0);
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

// Populate Grant tab
AnalyzeCSV::AnalyzeCSV(std::shared_ptr<CSVData<GrantDTO>> _data, QWidget *parent) :
QMainWindow(parent),
ui(new Ui::AnalyzeCSV)
{
    /*
    Jennifer/Jaisen

    I commented this out because there are some errors in populating the grant tab for Analyze
    I think its mostly because of the fact that populate_grant_tree doesn't 100% work yet
    Also,the ui->start_date_publications name seems kinda weird since this is on the Grants tab
    You may want to verify the names of the actual objects being populated on the analyze_csv.ui form
    PopulateDateCombos for GraphDTO's needs to be written, I've included the function
    prototypes and tagged your guys' names there as well

    This is the one you're interested in, in analyze_csv.cpp
    QStringList AnalyzeCSV::PopulateDateCombos(std::shared_ptr<CSVData<GrantDTO>> data) {


    */

    /*
    gdatanew = _data;
    
    std::shared_ptr<CSVData<GrantDTO>> data = _data;
    ui->setupUi(this);
    
    /// DOMAIN LABEL SET ///
    ui->domain_lbl1->setText(QString::fromStdString(data->dtos->at(0).domain));
    
    /// DATE FILTER COMBO BOX ///
    QStringList date_strs = PopulateDateCombos(_data);
    
    // set the dates list to the combo boxes
    ui->start_date_publications->addItems(date_strs);       // Why is this start_date_publications?
    ui->start_date_publications->setCurrentIndex(0);        // Why is this start_date_publications?
    ui->end_date1->addItems(date_strs);
    ui->end_date1->setCurrentIndex(date_strs.size()-1);
    
    // Populate the QTreeWidget item
    populate_grant_tree();
    
    
    // PUT THIS IN A FUNCTION vvvvv
    Grant_BarGraph1_VO* graphable = new Grant_BarGraph1_VO(_data, 1900, 4000);

    
    scene = new QGraphicsScene(this);   // Added for graphics window
    
    QCustomPlot *customPlot = new QCustomPlot();
    customPlot->setGeometry(0,0,345,375);   // added to resize graph
    
    // Graph handling functions go here
    Graphvisualizations *graph_handler = new Graphvisualizations();
    graph_handler->plot_grants_vs_trials(customPlot, graphable);
    
    scene->addWidget(customPlot);   // Add plot to the window & Essential
    ui->graph_area->setScene(scene);    // Added for grpahics & Essential
    */
}

//Constructor for Presentation - ideally merge this with the above one
// Jerry will do this one
AnalyzeCSV::AnalyzeCSV(std::shared_ptr<CSVData<PresentationDTO>> _data, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    /*datanew4 = _data;
    std::shared_ptr<CSVData<PresentationDTO>> data = _data;
    dtoType = 4;
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
    /*Pub_BarGraph1_VO* graphable = new Pub_BarGraph1_VO(_data, 1900, 4000);
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
    ui->graph_area->setScene(scene);    // Added for grpahics & Essential*/
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

// Jaisen/Jennifer (Need to implement this function to populate the date combos box)
// Its very similar to PopulateDateCombos for PublicationDTO however theres no "date" field
// in the constructor for the GrantDTO so just be weary of that when writing the line
//                 if ((int)data->dtos->at(i).date == dates.at(j)) {
QStringList AnalyzeCSV::PopulateDateCombos(std::shared_ptr<CSVData<GrantDTO>> data) {
    QStringList date_strs;// DUMMY DATA REPLACE WITH REAL DATA WHEN IMPLEMENTING
    return date_strs;// DUMMY DATA REPLACE WITH REAL DATA WHEN IMPLEMENTING
}

// Eric/Emily  (Need to implement this function to populate the date combos box)
// I don't know how the Teaching DTO is implemented yet so you guys will have to figure
// out how tocreate this function
QStringList AnalyzeCSV::PopulateDateCombos(std::shared_ptr<CSVData<TeachingDTO>> data) {
    QStringList date_strs;  // DUMMY DATA REPLACE WITH REAL DATA WHEN IMPLEMENTING
    return date_strs;   // DUMMY DATA REPLACE WITH REAL DATA WHEN IMPLEMENTING
}

// Jerry will implement this later
QStringList AnalyzeCSV::PopulateDateCombos(std::shared_ptr<CSVData<PresentationDTO>> data) {
    QStringList date_strs;
    return date_strs;
}

// Use this to model the other 3 PopulateDateCombos functions
// Remember the DTOs you wrote (Presentations/Teaching/Grants) may/may not have the .date fields
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

/**
 * @brief AnalyzeCSV::populate_publication_tree fills the tree_list_vo with publication info
 * @param p_tree holds the publication info to be written to the QTreeWidget
 */
void AnalyzeCSV::populate_publication_tree()
{
    std::shared_ptr<CSVData<PublicationDTO>> _data = datanew;
    QString st_string = ui->start_date_publications->itemText(ui->start_date_publications->currentIndex());
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
    // Jaisen/Jennifer
    /*
   This is where you would make 2 tree_list_vo objects.
   There would be 2 roots added to the tree.

   For example:
   i.e. for Publications, the 2 lines necessary to generate the tree and data are:
   tree_list_vo *p_treeNew = new tree_list_vo(_data);
   p_treeNew->populate_for_publications(_data, (int)s,(int)e);

   You would create 2 tree_list_vo objects; 1 for Grants and 1 for Clinical Funding
   You should have written the function populate_for_grants in tree_list_vo.cpp
   such that it can populate either a Grants field or a Clinical Funding field

    Then using these 2 tree_list_vo objects, follow the code in populate_publication_tree()
    in order to generate the Grants Tree (it should have 2 roots vs the 1 in publications)
    https://www.youtube.com/watch?v=TpkiVlOS3o4

    ^^ This is a useful resource I used to generate it
    I didn't delete any of your code, but it might be worthwhile to re-write this function
    from beginning so you can debug it as you go along.
    As always, feel free to message me if you have issues with generating the tree_list_vo's
    and subsequently updating the QTreeWidget! - Jerry
    */


    /*
    std::shared_ptr<CSVData<GrantDTO>> _data = gdatanew;
    QString st_string = ui->start_date_publications->itemText(ui->start_date_publications->currentIndex());
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
        p_treeNew->populate_for_grants(_data, (int)s,(int)e);
        tmpUI->pub_tree->clear();
        
        /// LIST TREE VIEW ///
        tmpUI->grant_tree->setColumnCount(2);
        tmpUI->grant_tree->setColumnWidth(0, 275);
        tmpUI->grant_tree->setHeaderLabels(QStringList() << "Funding" << "Total");
        
        int gCounter = 0;
        QTreeWidgetItem *root = new QTreeWidgetItem(tmpUI->pub_tree, QStringList() << "Grants" << QString::fromStdString(std::to_string(_data->dtos->size())));
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
                gCounter += tmp.at(j).num;
            }
        }
        // expand publications root by default
        tmpUI->grant_tree->expandItem(root);
        /// LIST TREE VIEW ///
        root->setText(1,QString::fromStdString(std::to_string(gCounter)));    // updates text
        
        // Create a new graphics scene
        scene = new QGraphicsScene(this);   // Added for graphics window
        Pub_BarGraph1_VO* g = new Pub_BarGraph1_VO(_data, s, e);        // BUG IS BREAKING THIS HERE
        cout << "exit constructor" << endl;
        cout << g->grantTypes.size() << endl;
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
*/
}

/**
 * @brief AnalyzeCSV::populate_teaching_tree fills the tree_list_vo with teaching info
 * @param p_tree holds the teaching info to be written to QTreeWidget
 */
void AnalyzeCSV::populate_teaching_tree()
{
    // Eric/Emily
    /*
   This is where you would make 4 tree_list_vo objects.
   There would be 4 roots added to the tree.

   For example:
   i.e. for Publications, the 2 lines necessary to generate the tree and data are:
   tree_list_vo *p_treeNew = new tree_list_vo(_data);
   p_treeNew->populate_for_publications(_data, (int)s,(int)e);

   You would create 4 tree_list_vo objects; PME, UME, CME, Other
   You should have written the function populate_for_teaching in tree_list_vo.cpp
   such that it can populate for 1 of the 4 objects

    Then using these 4  tree_list_vo objects, follow the code in populate_publication_tree()
    in order to generate the Teaching Tree (it should have 4 roots vs the 1 in publications)
    https://www.youtube.com/watch?v=TpkiVlOS3o4

    ^^ This is a useful resource I used to generate it
    I didn't delete any of your code, but it might be worthwhile to re-write this function
    from beginning so you can debug it as you go along.
    As always, feel free to message me if you have issues with generating the tree_list_vo's
    and subsequently updating the QTreeWidget! - Jerry
    */

    /*
    std::shared_ptr<CSVData<TeachingDTO>> _data = teaching_data_new;

    QString st_string = ui->start_date_publications->itemText(ui->start_date_publications->currentIndex());
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

    }
    */

}

void AnalyzeCSV::on_filter_btn_teach_clicked()
{
    populate_teaching_tree();
}

// Jennifer/Jaisen this is called when the filter button on the Grants page is clicked
void AnalyzeCSV::on_filter_btn_2_clicked()
{
    populate_grant_tree();
}
