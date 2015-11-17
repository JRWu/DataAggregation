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
    ui->domain_lbl_teach->setText(QString::fromStdString(_data->dtos->at(0).domain));

    /// DATE FILTER COMBO BOX ///
    /// \brief startDate_strs
    QStringList startDate_strs = PopulateDateCombos(_data);
    QStringList endDate_strs = PopulateDateCombos(_data);

    // set the dates list to the combo boxes
    ui->start_date_teach->addItems(startDate_strs);
    ui->start_date_teach->setCurrentIndex(0);
    ui->end_date_teach->addItems(endDate_strs);
    ui->end_date_teach->setCurrentIndex(endDate_strs.size()-1);

    // Populate the teaching tree with the parsed data
    populate_teaching_tree();
    populate_teaching_bargraph();
}

/* Populating the Publications tab */
AnalyzeCSV::AnalyzeCSV(std::shared_ptr<CSVData<PublicationDTO>> _data, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    datanew = _data;    // set the global data poiner

    std::shared_ptr<CSVData<PublicationDTO>> data = _data;
    ui->setupUi(this);

    /// DOMAIN LABEL SET ///
    ui->domain_lbl1->setText(QString::fromStdString(data->dtos->at(0).domain));

    /// DATE FILTER COMBO BOX ///
    QStringList date_strs = PopulateDateCombos(data);

    // set the dates list to the combo boxes
    ui->start_date_publications->addItems(date_strs);
    ui->start_date_publications->setCurrentIndex(0);
    ui->end_date_publications->addItems(date_strs);
    ui->end_date_publications->setCurrentIndex(date_strs.size()-1);

    // Populate the Tree Drop down list and the Graph View
    populate_publication_tree();
    populate_publication_bargraph();

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

    gdatanew = _data;
    
    std::shared_ptr<CSVData<GrantDTO>> data = _data;
    ui->setupUi(this);
    
    /// DOMAIN LABEL SET ///
    ui->domain_lbl3_2->setText(QString::fromStdString(_data->dtos->at(0).domain));
    
    /// DATE FILTER COMBO BOX ///
    QStringList date_strs = PopulateDateCombos(_data);
    
    // set the dates list to the combo boxes
    ui->start_date1_2->addItems(date_strs);     //change to start_date_grants if possible
    ui->start_date1_2->setCurrentIndex(0);
    ui->end_date1_2->addItems(date_strs);
    ui->end_date1_2->setCurrentIndex(date_strs.size()-1);
    
    // Populate the QTreeWidget item
    populate_grant_tree();
    
    
    // PUT THIS IN A FUNCTION vvvvv
    /* getting a Undefined symbols for architecture x86_64; commented out for now
    Grant_BarGraph1_VO* graphable = new Grant_BarGraph1_VO(_data, 1900, 4000);*/

    
    scene = new QGraphicsScene(this);   // Added for graphics window
    
    QCustomPlot *customPlot = new QCustomPlot();
    customPlot->setGeometry(0,0,345,375);   // added to resize graph
    
    // Graph handling functions go here
    /*
    Graphvisualizations *graph_handler = new Graphvisualizations();
    graph_handler->plot_grants_vs_trials(customPlot, graphable);*/
    
    scene->addWidget(customPlot);   // Add plot to the window & Essential
    ui->graph_area->setScene(scene);    // Added for grpahics & Essential

}

//Constructor for Presentation - ideally merge this with the above one
// Jerry will do this one
AnalyzeCSV::AnalyzeCSV(std::shared_ptr<CSVData<PresentationDTO>> _data, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    pr_data = _data;
    ui->setupUi(this);

    /// DOMAIN LABEL SET ///
    ui->domain_lbl_presentation->setText(QString::fromStdString(_data->dtos->at(0).domain));

    /// DATE FILTER COMBO BOX //
    QStringList date_strs = PopulateDateCombos(_data);

    ui->start_date_presentation->addItems(date_strs);
    ui->start_date_presentation->setCurrentIndex(0);
    ui->end_date_presentation->addItems(date_strs);
    ui->end_date_presentation->setCurrentIndex(date_strs.size()-1);

    populate_presentation_tree();
    populate_presentation_bargraph();

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

// JX --> implemented 11.15.15
// Jaisen/Jennifer (Need to implement this function to populate the date combos box)
// Its very similar to PopulateDateCombos for PublicationDTO however theres no "date" field
// in the constructor for the GrantDTO so just be weary of that when writing the line
//                 if ((int)data->dtos->at(i).date == dates.at(j)) {
QStringList AnalyzeCSV::PopulateDateCombos(std::shared_ptr<CSVData<GrantDTO>> data) {
    std::vector<int> dates;
    
    // loop through the dtos to get a list of dates
    for (int i=0; i < data->dtos->size(); i++) {
        // loop again to see if the current date is already in the list
        if (dates.empty()) {
            dates.push_back((int)data->dtos->at(i).startDate);      // add the start and end dates to the date list
            dates.push_back((int)data->dtos->at(i).endDate);
        }else {
            bool add_start = true;
            bool add_end = true;
            
            for (int j=0; j < dates.size(); j++) {
                
                // if the start date already exists in the list of dates
                if ((int)data->dtos->at(i).startDate == dates.at(j)) {
                    add_start = false;
                    break;
                }
            }
            
            for (int k=0; k<dates.size(); k++){

                // if the end date already exists in the list of dates
                if ((int)data->dtos->at(i).endDate == dates.at(k)) {
                    add_end = false;
                    break;
                }
                
            }
            if (add_start) {
                dates.push_back((int)data->dtos->at(i).startDate);
            }
            if (add_end) {
                dates.push_back((int)data->dtos->at(i).endDate);
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

// Angus wrote this function
QStringList AnalyzeCSV::PopulateStartDateCombos(std::shared_ptr<CSVData<TeachingDTO>> data) {
    //QStringList date_strs;  // DUMMY DATA REPLACE WITH REAL DATA WHEN IMPLEMENTING

    std::vector<int> startDates;

    // loop through the dtos to get a list of dates
    for (int i=0; i < data->dtos->size(); i++) {
        // loop again to see if the current date is already in the list
        if (startDates.empty()) {
            startDates.push_back((int)data->dtos->at(i).startDate);
        }else {
            bool add = true;
            for (int j=0; j < startDates.size(); j++) {
                // if it isn't add it to the list
                if ((int)data->dtos->at(i).startDate == startDates.at(j)) {
                    add = false;
                    break;
                }
            }
            if (add) {
                startDates.push_back((int)data->dtos->at(i).startDate);
            }
        }
    }

    //sort the dates
    std::sort(startDates.begin(), startDates.end());

    //put the dates in a QString vector list
    QStringList date_strs;
    for (int i=0; i < startDates.size(); i++)
    {

        ostringstream stream;
        stream << startDates.at(i);
        string datestr = stream.str();
        date_strs << QString::fromStdString(datestr);
    }

    //std::sort(date_strs.begin(), date_strs.end());

    return date_strs;   // DUMMY DATA REPLACE WITH REAL DATA WHEN IMPLEMENTING
}

// Angus wrote this function
QStringList AnalyzeCSV::PopulateEndDateCombos(std::shared_ptr<CSVData<TeachingDTO>> data) {

    std::vector<int> endDates;

    // loop through the dtos to get a list of dates
    for (int i=0; i < data->dtos->size(); i++) {
        // loop again to see if the current date is already in the list
        if (endDates.empty()) {
            endDates.push_back((int)data->dtos->at(i).endDate);
        }else {
            bool add = true;
            for (int j=0; j < endDates.size(); j++) {
                // if it isn't add it to the list
                if ((int)data->dtos->at(i).endDate == endDates.at(j)) {
                    add = false;
                    break;
                }
            }
            if (add) {
                endDates.push_back((int)data->dtos->at(i).endDate);
            }
        }
    }

    // Sort the dates in increasing order
    std::sort(endDates.begin(), endDates.end());

    //put the dates in a QString vector list
    QStringList date_strs;
    for (int i=0; i < endDates.size(); i++)
    {

        ostringstream stream;
        stream << endDates.at(i);
        string datestr = stream.str();
        date_strs << QString::fromStdString(datestr);
    }

    //std::sort(date_strs.begin(), date_strs.end());

    return date_strs;   // DUMMY DATA REPLACE WITH REAL DATA WHEN IMPLEMENTING
}

QStringList AnalyzeCSV::PopulateDateCombos(std::shared_ptr<CSVData<TeachingDTO>> data) {
    std::vector<string> dates;

    // Loop through DTOs to get list of the dates in them
    for (int i = 0; i < (int)data->dtos->size(); i ++)
    {
        string date = to_string(data->dtos->at(i).endDate);
        vector<string>::iterator index;
        index = std::find(dates.begin(), dates.end(), date);
        if(index == dates.end()) dates.push_back(date);
    }
    std::sort(dates.begin(), dates.end());  // Sort the date list
    QStringList date_strs;        // Add dates to a qstringlist for qcombobox

    for (int i = 0; i < dates.size(); i ++)
    {
        date_strs << QString::fromStdString(dates.at(i));
    }

    return date_strs;
}

// Jerry will implement this later
QStringList AnalyzeCSV::PopulateDateCombos(std::shared_ptr<CSVData<PresentationDTO>> data) {
    std::vector<int> dates;

    // Loop through DTOs to get list of the dates in them
    for (int i = 0; i < data->dtos->size(); i ++)
    {
        if(dates.empty())
        {
            dates.push_back((int)data->dtos->at(i).date);   // Add the first date
        }
        else
        {
            bool add = true;    // Assume new date encountered is novel
            for (int j = 0; j < dates.size(); j++)
            {
                if ((int)data->dtos->at(i).date==dates.at(j))   // check to prevent duplicate dates
                {
                    add = false;
                    break;
                }
            }
            if (add)    // New date encountered, add it to the list
            {
                dates.push_back((int)data->dtos->at(i).date);
            }
        }
    }
    std::sort(dates.begin(), dates.end());  // Sort the date list
    QStringList date_strs;                          // Add dates to a qstringlist for qcombobox

    for (int i = 0; i < dates.size(); i ++)
    {
        ostringstream stream;
        stream << dates.at(i);
        string datestr = stream.str();
        date_strs << QString::fromStdString(datestr);
    }

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

// For publications display the updated tree and updated graph
// JERRY
void AnalyzeCSV::on_filter_btn_clicked()
{
    //ui->graph_area;           // update this to display what plot is being updated
    //ui->graph_combo;      // used to get type of plot (0 is bargraph)

    // Catch to prevent analysis on a null pointer
    // Only catches error if data is loaded ONCE, therefore the pointers not being cleared at the end of a session
    if (datanew == NULL)
    {
        // Add code to inform user that they didn't load proper information
    }
    else
    {
        // Index 0 bargraph
        // Index 1 is pie chart
        populate_publication_tree();
        populate_publication_bargraph();
    }
}

/**
 * @brief AnalyzeCSV::populate_publication_tree fills the tree_list_vo with publication info
 * @param p_tree holds the publication info to be written to the QTreeWidget
 */
void AnalyzeCSV::populate_publication_tree()
{
    std::shared_ptr<CSVData<PublicationDTO>> _data = datanew;
    QString st_string = ui->start_date_publications->itemText(ui->start_date_publications->currentIndex());
    QString en_string = ui->end_date_publications->itemText(ui->end_date_publications->currentIndex());

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

    std::shared_ptr<CSVData<GrantDTO>> _data = gdatanew;
    QString st_string = ui->start_date1_2->itemText(ui->start_date1_2->currentIndex()); // JX: FIX V NAMES
    QString en_string = ui->end_date1_2->itemText(ui->end_date1_2->currentIndex()); // FIX V NAMES
    
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
        
        // Create 2 new tree lists from the selected interval (1 for grants and 1 for clinical trials)
        tree_list_vo *g_treeNew = new tree_list_vo(_data);                    //grant tree
        tree_list_vo *c_treeNew = new tree_list_vo(_data);                    //clinical tree
        
        // Populate the VOs, still needs the new params
        g_treeNew->populate_for_grants(_data, (int)s,(int)e, "Grants");           //create tree_list_vo object for Grants
        c_treeNew->populate_for_grants(_data, (int)s,(int)e, "Clinical Trials");    //create tree_list_vo object for Clinical Funding
        tmpUI->present_tree_2->clear(); // all present_tree_2's should be changed to grant_tree
        
        //////////// GRANTS //////////////
        tmpUI->present_tree_2->setColumnCount(2);
        tmpUI->present_tree_2->setColumnWidth(0, 275);
        tmpUI->present_tree_2->setHeaderLabels(QStringList() << "Funding" << "Total");
        
        int gCounter = 0;   //counts the number of grants
        
        // root 1: grant
        QTreeWidgetItem *grant_root = new QTreeWidgetItem(tmpUI->present_tree_2, QStringList() << "Grants" << QString::fromStdString(std::to_string(_data->dtos->size())));
        for (int i = 0; i < g_treeNew->get_parent_set().size(); i ++)
        {
            cout << i << endl;
            QTreeWidgetItem * child = new QTreeWidgetItem(grant_root, QStringList() << QString::fromStdString(g_treeNew->get_parent_set().at(i).label)
                                                          <<QString::fromStdString(std::to_string((int)g_treeNew->get_parent_set().at(i).num)) );

            vector<string_data_object> tmp = g_treeNew->get_child_set().at(i);
            for (int j = 0; j < tmp.size(); j++) 
            {
                new QTreeWidgetItem(child, QStringList() << QString::fromStdString(tmp.at(j).label)
                                    << QString::fromStdString(std::to_string((int)tmp.at(j).num)) );
                gCounter += tmp.at(j).num;
            }
        }
        // expand publications grant_root by default
        tmpUI->present_tree_2->expandItem(grant_root);
        /// LIST TREE VIEW ///
        grant_root->setText(1,QString::fromStdString(std::to_string(gCounter)));    // updates text
        

        //////////// CLINICAL TRIALS //////////////
        
        int cCounter = 0;       //counts the number of clinical trials
        // root 1: clinical
        QTreeWidgetItem *clinical_root = new QTreeWidgetItem(tmpUI->present_tree_2, QStringList() << "Clinical Trials" << QString::fromStdString(std::to_string(_data->dtos->size())));
        for (int i = 0; i < c_treeNew->get_parent_set().size(); i ++)
        {
            cout << i << endl;
            QTreeWidgetItem * child = new QTreeWidgetItem(clinical_root, QStringList() << QString::fromStdString(c_treeNew->get_parent_set().at(i).label)
                                                          <<QString::fromStdString(std::to_string((int)c_treeNew->get_parent_set().at(i).num)) );
            
            vector<string_data_object> tmp = c_treeNew->get_child_set().at(i);
            for (int j = 0; j < tmp.size(); j++)
            {
                new QTreeWidgetItem(child, QStringList() << QString::fromStdString(tmp.at(j).label)
                                    << QString::fromStdString(std::to_string((int)tmp.at(j).num)) );
                cCounter += tmp.at(j).num;
            }
        }
        // expand publications clinical_root by default
        tmpUI->present_tree_2->expandItem(clinical_root);
        /// LIST TREE VIEW ///
        clinical_root->setText(1,QString::fromStdString(std::to_string(cCounter)));    // updates text
        
        
        /*
        // Create a new graphics scene
        scene = new QGraphicsScene(this);   // Added for graphics window
        Grant_BarGraph1_VO* g = new Grant_BarGraph1_VO(_data, s, e);        // BUG IS BREAKING THIS HERE
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
        */
    }
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

    std::shared_ptr<CSVData<TeachingDTO>> _data = teaching_data_new;

    QString st_string = ui->start_date_teach->itemText(ui->start_date_teach->currentIndex());
    QString en_string = ui->end_date_teach->itemText(ui->end_date_teach->currentIndex());
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
        //Sort by Program, then by Date, then by Faculty
        tree_list_vo *p_PMEtree = new tree_list_vo(_data);
        tree_list_vo *p_UMEtree = new tree_list_vo(_data);
        tree_list_vo *p_CMEtree = new tree_list_vo(_data);
        //tree_list_vo *p_Othertree = new tree_list_vo(_data);
        // Populates the VO , still needs the new params

        //p_PMEtree->populate_for_teaching(_data, std::string str, (int)s,(int)e);
        std::string PMEstr = "Postgraduate Medical Education";
        std::string UMEstr = "Undergraduate Medical Education";
        std::string CMEstr = "Continuing Medical Education";
        std::string Otherstr = "";

        p_PMEtree->populate_for_teaching(_data, PMEstr.c_str(), (int)s,(int)e);        
        p_UMEtree->populate_for_teaching(_data, UMEstr.c_str(), (int)s,(int)e);
        p_CMEtree->populate_for_teaching(_data, CMEstr.c_str(), (int)s,(int)e);
        //p_Othertree->populate_for_teaching(_data, PMEstr.c_str(), (int)s,(int)e);
        tmpUI->teach_tree->clear();

        /// LIST TREE VIEW ///
        tmpUI->teach_tree->setColumnCount(3);   //Main field, hours, students
        tmpUI->teach_tree->setColumnWidth(0, 175);
        tmpUI->teach_tree->setHeaderLabels(QStringList() << "Type" << "Hours" << "Hours/Session");

        int tCounter = 0;

        //change Teaching to PME/UME/etc. - get it from the actual data
        QTreeWidgetItem *PMEroot = new QTreeWidgetItem(tmpUI->teach_tree, QStringList() << "PME" << QString::fromStdString(std::to_string(_data->dtos->size())) << "None");
        QTreeWidgetItem *UMEroot = new QTreeWidgetItem(tmpUI->teach_tree, QStringList() << "UME" << QString::fromStdString(std::to_string(_data->dtos->size())) << "None");
        QTreeWidgetItem *CMEroot = new QTreeWidgetItem(tmpUI->teach_tree, QStringList() << "CME" << QString::fromStdString(std::to_string(_data->dtos->size())) << "None");
        //QTreeWidgetItem *Otherroot = new QTreeWidgetItem(tmpUI->teach_tree, QStringList() << "Other" << QString::fromStdString(std::to_string(_data->dtos->size())));
        for (int i = 0; i < p_PMEtree->get_parent_set().size(); i ++)
        {
            QTreeWidgetItem * child = new QTreeWidgetItem(PMEroot, QStringList() << QString::fromStdString(p_PMEtree->get_parent_set().at(i).label)
                                                      <<QString::fromStdString(std::to_string((int)p_PMEtree->get_parent_set().at(i).num))
                                                      <<QString::fromStdString(std::to_string((int)p_PMEtree->get_parent_set().at(i).num2)));

            vector<string_data_object> tmp = p_PMEtree->get_child_set().at(i);
            for (int j = 0; j < tmp.size(); j++)
            {
                new QTreeWidgetItem(child, QStringList() << QString::fromStdString(tmp.at(j).label)
                                << QString::fromStdString(std::to_string((int)tmp.at(j).num))
                                << QString::fromStdString(std::to_string((int)tmp.at(j).num2)));
                tCounter += tmp.at(j).num;
            }
        }
        // expand the initial root of teachings by default
        tmpUI->teach_tree->expandItem(PMEroot);
        /// LIST TREE VIEW ///
        PMEroot->setText(1,QString::fromStdString(std::to_string(tCounter)));
        tCounter = 0;

        for (int i = 0; i < p_UMEtree->get_parent_set().size(); i ++)
        {
            QTreeWidgetItem * child = new QTreeWidgetItem(UMEroot, QStringList() << QString::fromStdString(p_UMEtree->get_parent_set().at(i).label)
                                                      <<QString::fromStdString(std::to_string((int)p_UMEtree->get_parent_set().at(i).num))
                                                      <<QString::fromStdString(std::to_string((int)p_UMEtree->get_parent_set().at(i).num2)));

            vector<string_data_object> tmp = p_UMEtree->get_child_set().at(i);
            for (int j = 0; j < tmp.size(); j++)
            {
                new QTreeWidgetItem(child, QStringList() << QString::fromStdString(tmp.at(j).label)
                                << QString::fromStdString(std::to_string((int)tmp.at(j).num))
                                << QString::fromStdString(std::to_string((int)tmp.at(j).num2)));
                tCounter += tmp.at(j).num;
            }
        }
        // expand the initial root of teachings by default
        tmpUI->teach_tree->expandItem(UMEroot);
        /// LIST TREE VIEW ///
        UMEroot->setText(1,QString::fromStdString(std::to_string(tCounter)));
        tCounter = 0;

        for (int i = 0; i < p_CMEtree->get_parent_set().size(); i ++)
        {
            QTreeWidgetItem * child = new QTreeWidgetItem(CMEroot, QStringList() << QString::fromStdString(p_CMEtree->get_parent_set().at(i).label)
                                                      <<QString::fromStdString(std::to_string((int)p_CMEtree->get_parent_set().at(i).num))
                                                      <<QString::fromStdString(std::to_string((int)p_CMEtree->get_parent_set().at(i).num2)) );

            vector<string_data_object> tmp = p_CMEtree->get_child_set().at(i);
            for (int j = 0; j < tmp.size(); j++)
            {
                new QTreeWidgetItem(child, QStringList() << QString::fromStdString(tmp.at(j).label)
                                << QString::fromStdString(std::to_string((int)tmp.at(j).num))
                                << QString::fromStdString(std::to_string((int)tmp.at(j).num2)));
                tCounter += tmp.at(j).num;
            }
        }
        // expand the initial root of teachings by default
        tmpUI->teach_tree->expandItem(CMEroot);
        /// LIST TREE VIEW ///
        CMEroot->setText(1,QString::fromStdString(std::to_string(tCounter)));
        tCounter = 0;

        // create a new graphics scene for teachings
/*        scene = new QGraphicsScene(this);
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
*/
    }

}

// Do by jerry
void AnalyzeCSV::populate_presentation_tree()
{

    std::shared_ptr<CSVData<PresentationDTO>> _data = pr_data;
    QString st_string = ui->start_date_presentation->itemText(ui->start_date_presentation->currentIndex());
    QString en_string = ui->end_date_presentation->itemText(ui->end_date_presentation->currentIndex());

    long s = stol(st_string.toStdString());
    long e = stol(en_string.toStdString());

    if (e <= s)
    {
        cout << "Cannot filter. Filter dates error." << endl;
    }
    else
    {
        Ui::AnalyzeCSV *tmpUI = get_ui_ptr();

        // Create 1 tree list VO for the Presentation data
        tree_list_vo *pr_treeNew = new tree_list_vo(pr_data);
        // Populate the VO with Presentation data and complete range
        pr_treeNew->populate_for_presentations(pr_data,(int)s,(int)e);
        tmpUI->present_tree->clear();

        ///LIST TREE VIEW (POPULATE TREE LIST IN GUI WITH DATA)///
        tmpUI->present_tree->setColumnCount(2);
        tmpUI->present_tree->setColumnWidth(0,275);
        tmpUI->present_tree->setHeaderLabels(QStringList() << "Presentation Type" << "# Presentations");


        int presCounter = 0;    // Counter for presentations added
        QTreeWidgetItem * root = new QTreeWidgetItem(tmpUI->present_tree, QStringList() << "Presentations" << QString::fromStdString(std::to_string(_data->dtos->size())));
        for (int i = 0; i < pr_treeNew->get_parent_set().size(); i ++)
        {
            QTreeWidgetItem * child = new QTreeWidgetItem(root, QStringList() << QString::fromStdString(pr_treeNew->get_parent_set().at(i).label)
                                                          <<QString::fromStdString(std::to_string((int)pr_treeNew->get_parent_set().at(i).num)) );

            vector<string_data_object> tmp = pr_treeNew->get_child_set().at(i);
            for (int j = 0; j < tmp.size(); j ++)
            {
                new QTreeWidgetItem(child, QStringList() << QString::fromStdString(tmp.at(j).label)
                                    << QString::fromStdString(std::to_string((int)tmp.at(j).num)) );
                presCounter += tmp.at(j).num;
            }
        }

        tmpUI->present_tree->expandItem(root);
        root->setText(1, QString::fromStdString(std::to_string(presCounter)));
    }

}

void AnalyzeCSV::populate_teaching_bargraph(){
    QString st_string = ui->start_date_teach->itemText(ui->start_date_teach->currentIndex());
    QString en_string = ui->end_date_teach->itemText(ui->end_date_teach->currentIndex());

    string s = st_string.toStdString(); // start date
    string e = en_string.toStdString(); // end date

    if (e <= s)
    {
        cout << "Cannot filter. Filter dates error." << endl;
    }
    else
    {
        string name = teaching_data_new->dtos->at(0).getName();
        shared_ptr<BarGraph_VO<TeachingDTO>> graphable(new BarGraph_VO<TeachingDTO>(teaching_data_new, name, s, e, 1));
        scene = new QGraphicsScene(this);   // Added for graphics window

        QCustomPlot *customPlot = new QCustomPlot();
        customPlot->setGeometry(0,0,345,375);   // added to resize graph

        // Graph handling functions go here
        Graphvisualizations *graph_handler = new Graphvisualizations();
        graph_handler->plot_bargraph(customPlot, graphable);

        scene->addWidget(customPlot);   // Add plot to the window & Essential
        ui->graph_area_teach->setScene(scene);    // Added for grpahics & Essential
    }
}

/**
 * @brief AnalyzeCSV::populate_publication_bargraph populates the Graph1 tab
 * also known as the Publication bargraph on the Analyze  Page
 * DO NOT MODIFY (Jerry)
 */
void AnalyzeCSV::populate_publication_bargraph()
{
    QString st_string = ui->start_date_publications->itemText(ui->start_date_publications->currentIndex());
    QString en_string = ui->end_date_publications->itemText(ui->end_date_publications->currentIndex());

    string s = st_string.toStdString(); // start date
    string e = en_string.toStdString(); // end date

    if (e <= s)
    {
        cout << "Cannot filter. Filter dates error." << endl;
    }
    else
    {
        string name = datanew->dtos->at(0).getName();
        shared_ptr<BarGraph_VO<PublicationDTO>> graphable(new BarGraph_VO<PublicationDTO>(datanew, name, s, e, 1));
        scene = new QGraphicsScene(this);   // Added for graphics window

        QCustomPlot *customPlot = new QCustomPlot();
        customPlot->setGeometry(0,0,345,375);   // added to resize graph

        // Graph handling functions go here
        Graphvisualizations *graph_handler = new Graphvisualizations();
        graph_handler->plot_bargraph(customPlot, graphable);

        scene->addWidget(customPlot);   // Add plot to the window & Essential
        ui->graph_area->setScene(scene);    // Added for grpahics & Essential
     }
}

/**
 * @brief AnalyzeCSV::populate_presentation_bargraph populates the Graph1 tab
 * also known as Presentation bargraph on the Analyze Page
 *  DO NOT MODIFY(Jerry)
 */
void AnalyzeCSV::populate_presentation_bargraph()
{
    std::shared_ptr<CSVData<PresentationDTO>> _data = pr_data;
    QString st_string = ui->start_date_presentation->itemText(ui->start_date_presentation->currentIndex());
    QString en_string = ui->end_date_presentation->itemText(ui->end_date_presentation->currentIndex());

    string s = st_string.toStdString();
    string e = en_string.toStdString();

    if (e <= s)
    {
        cout << "Cannot filter. Filter dates error." << endl;
    }
    else
    {

           // define name
        string name = pr_data->dtos->at(0).getName();

        shared_ptr<BarGraph_VO<PresentationDTO>>graphable (new BarGraph_VO<PresentationDTO>(pr_data,name, s, e, 1));

//        Pres_BarGraph1_VO* graphable = new Pres_BarGraph1_VO(pr_data, s, e);
        scene = new QGraphicsScene(this);

        QCustomPlot *customPlot = new QCustomPlot();
        customPlot->setGeometry(0,0,345,375);   // Should make this dynamic

        Graphvisualizations *graph_handler = new Graphvisualizations();
        graph_handler->plot_bargraph(customPlot, graphable);
        scene->addWidget(customPlot);
        ui->graph_area_7->setScene(scene);  // rename graph_are_7 to graph_area_Presentations
    }
}



// Jennifer/Jaisen this is called when the filter button on the Grants page is clicked
// JX --> implemented 11.15.15
void AnalyzeCSV::on_filter_btn_2_clicked()
{
    //ui->graph_area;           // update this to display what plot is being updated
    //ui->graph_combo;      // used to get type of plot (0 is bargraph)
    
    // Catch to prevent analysis on a null pointer
    // Only catches error if data is loaded ONCE, therefore the pointers not being cleared at the end of a session
    if (datanew == NULL)
    {
        // Add code to inform user that they didn't load proper information
    }
    else
    {
        // Index 0 bargraph
        // Index 1 is pie chart
        populate_grant_tree();
        //populate_grant_bargraph();
    }
}

// Jerry This populates the preseentation tree in the tree view
void AnalyzeCSV::on_filter_btn_presentation_clicked()
{
    // Catch to prevent analysis on a null pointer
    // Only catches error if data is loaded ONCE, therefore the pointers not being cleared at the end of a session
    if (pr_data == NULL)
    {
        // Add code to inform user that they didn't load proper information
    }
    else
    {
        // Index 0 bargraph
        // Index 1 is pie chart
        populate_presentation_tree();
        populate_presentation_bargraph();
    }
}

void AnalyzeCSV::on_filter_btn_teaching_clicked()
{

    if (teaching_data_new == NULL)
    {
        // Add code to inform user that they didn't load proper information
    }
    else
    {
        // Index 0 bargraph
        // Index 1 is pie chart
        //cout <<"CURRENT INDEX:"<< ui->graph_combo->currentIndex() << endl;
        populate_teaching_tree();
        populate_teaching_bargraph();
    }
}

void AnalyzeCSV::on_filter_btn_pub_clicked()
{
    // DUMMY FUNCTION TO SILENCE ERROR (NEED TO FIX LATER)
}

void AnalyzeCSV::on_filter_btn_grnt_clicked()
{
    // DUMMY FUNCTION TO SILENCE ERROR (NEED TO FIX LATER)
}

void AnalyzeCSV::on_filter_btn_pres_clicked()
{
    // DUMMY FUNCTION TO SILENCE ERROR (NEED TO FIX LATER)
}

void AnalyzeCSV::on_filter_btn_teach_clicked()
{
    // DUMMY FUNCTION TO SILENCE ERROR (NEED TO FIX LATER)
}
