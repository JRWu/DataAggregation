#include "load_csv.h"
#include "analyze_csv.h"
#include "ui_analyze_csv.h"

static std::shared_ptr<CSVData<TeachingDTO>> teach_data;
static std::shared_ptr<CSVData<PublicationDTO>> pub_data;
static std::shared_ptr<CSVData<PresentationDTO>> pres_data;
static std::shared_ptr<CSVData<GrantDTO>> grant_data;

/* Populating the Teaching tab */
AnalyzeCSV::AnalyzeCSV(std::shared_ptr<CSVData<TeachingDTO>> data, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    teach_data = data;
    ui->setupUi(this);

    /// DOMAIN LABEL SET for Teaching ///
    ui->domain_lbl_teach->setText(QString::fromStdString(teach_data->dtos->at(0).domain));

    /// DATE FILTER COMBO BOX ///
    QStringList startDate_strs = PopulateDateCombos(teach_data);
    QStringList endDate_strs = PopulateDateCombos(teach_data);

    // set the dates list to the combo boxes
    ui->start_date_combo_teach->addItems(startDate_strs);
    ui->start_date_combo_teach->setCurrentIndex(0);
    ui->end_date_combo_teach->addItems(endDate_strs);
    ui->end_date_combo_teach->setCurrentIndex(endDate_strs.size()-1);

    /// GRAPH FILTER COMBO BOX ///
    QStringList names = PopulateGraphComboName(teach_data);
    QStringList programs = PopulateGraphComboProgram(teach_data);

    ui->name_combo_teach->addItems(names);
    ui->name_combo_teach->setCurrentIndex(0);
    ui->program_combo_teach->addItems(programs);
    ui->program_combo_teach->setCurrentIndex(0);

    // Populate the teaching tree with the parsed data
    populate_teaching_tree(teach_data);
    populate_teaching_bargraph(teach_data);
}

/* Populating the Publications tab */
AnalyzeCSV::AnalyzeCSV(std::shared_ptr<CSVData<PublicationDTO>> data, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    pub_data = data;
    ui->setupUi(this);

    /// DOMAIN LABEL SET ///
    ui->domain_lbl_pub->setText(QString::fromStdString(pub_data->dtos->at(0).domain));

    /// DATE FILTER COMBO BOX ///
    QStringList date_strs = PopulateDateCombos(pub_data);

    // set the dates list to the combo boxes
    ui->start_date_combo_pub->addItems(date_strs);
    ui->start_date_combo_pub->setCurrentIndex(0);
    ui->end_date_combo_pub->addItems(date_strs);
    ui->end_date_combo_pub->setCurrentIndex(date_strs.size()-1);

    /// GRAPH FILTER COMBO BOXES ///
    QStringList combo_names = PopulateGraphComboName(pub_data);
    QStringList combo_types = PopulateGraphComboType(pub_data);

    //set combos with data
    ui->name_combo_pub->addItems(combo_names);
    ui->name_combo_pub->setCurrentIndex(0);
    ui->type_combo_pub->addItems(combo_types);
    ui->type_combo_pub->setCurrentIndex(0);

    // Populate the Tree Drop down list and the Graph View
    populate_publication_tree(pub_data);
    populate_publication_bargraph(pub_data);

}

// Populate Grant tab
AnalyzeCSV::AnalyzeCSV(std::shared_ptr<CSVData<GrantDTO>> data, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    grant_data = data;
    ui->setupUi(this);

    /// DOMAIN LABEL SET ///
    ui->domain_lbl_grnt->setText(QString::fromStdString(grant_data->dtos->at(0).domain));

    /// DATE FILTER COMBO BOX ///
    QStringList date_strs = PopulateDateCombos(grant_data);

    // set the dates list to the combo boxes
    ui->start_date_combo_grnt->addItems(date_strs);     //change to start_date_grants if possible
    ui->start_date_combo_grnt->setCurrentIndex(0);
    ui->end_date_combo_grnt->addItems(date_strs);
    ui->end_date_combo_grnt->setCurrentIndex(date_strs.size()-1);

    /// GRAPH FILTER COMBO BOX ///
    QStringList names = PopulateGraphComboName(grant_data);
    QStringList funding_types = PopulateGraphComboFunding(grant_data);

    ui->name_combo_grnt->addItems(names);
    ui->name_combo_grnt->setCurrentIndex(0);
    ui->type_combo_grnt->addItems(funding_types);
    ui->type_combo_grnt->setCurrentIndex(0);

    // Populate the QTreeWidget item
    populate_grant_tree(grant_data);
    populate_grant_bargraph(grant_data);

}

//Constructor for Presentation - ideally merge this with the above one
// Jerry will do this one
AnalyzeCSV::AnalyzeCSV(std::shared_ptr<CSVData<PresentationDTO>> data, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    pres_data = data;
    ui->setupUi(this);

    /// DOMAIN LABEL SET ///
    ui->domain_lbl_pres->setText(QString::fromStdString(pres_data->dtos->at(0).domain));

    /// DATE FILTER COMBO BOX ///
    QStringList date_strs = PopulateDateCombos(pres_data);

    ui->start_date_combo_pres->addItems(date_strs);
    ui->start_date_combo_pres->setCurrentIndex(0);
    ui->end_date_combo_pres->addItems(date_strs);
    ui->end_date_combo_pres->setCurrentIndex(date_strs.size()-1);

    /// GRAPH FILTER COMBO BOX ///
    QStringList names = PopulateGraphComboName(pres_data);
    QStringList types = PopulateGraphComboType(pres_data);

    ui->name_combo_pres->addItems(names);
    ui->name_combo_pres->setCurrentIndex(0);
    ui->type_combo_pres->addItems(types);
    ui->type_combo_pres->setCurrentIndex(0);

    populate_presentation_tree(pres_data);
    populate_presentation_bargraph(pres_data);

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

Ui::AnalyzeCSV* AnalyzeCSV::get_ui_ptr()
{
    return ui;
}


void AnalyzeCSV::on_filter_btn_pub_clicked()
{

    // Catch to prevent analysis on a null pointer
    // Only catches error if data is loaded ONCE, therefore the pointers not being cleared at the end of a session
    if (pub_data == NULL)
    {
        // Add code to inform user that they didn't load proper information
    }
    else
    {
        populate_publication_tree(pub_data);
        populate_publication_bargraph(pub_data);
    }
}

/**
 * @brief AnalyzeCSV::populate_publication_tree fills the tree_list_vo with publication info
 * @param p_tree holds the publication info to be written to the QTreeWidget
 */
void AnalyzeCSV::populate_publication_tree(std::shared_ptr<CSVData<PublicationDTO>> data)
{
    QString st_string = ui->start_date_combo_pub->itemText(ui->start_date_combo_pub->currentIndex());
    QString en_string = ui->end_date_combo_pub->itemText(ui->end_date_combo_pub->currentIndex());

    int s = stoi(st_string.toStdString()); // start date
    int e = stoi(en_string.toStdString()); // end date

    // Ensure the retrieved years are in the accepted range
    if (e < s)
    {
        cout << "Filter dates error" << endl;
    }
    else
    {
        TreeList_VO<PublicationDTO> treelistvo(data, s, e);

        //Failed to make vo due to empty data range for that year
        if(treelistvo.isEmpty()) return;

        ui->tree_list_pub->clear();
        treelistvo.makeQTree(ui->tree_list_pub);
        ui->tree_list_pub->setColumnCount(treelistvo.nCol);
        ui->tree_list_pub->setColumnWidth(0, 275);
        ui->tree_list_pub->setHeaderLabels(QStringList() << "Type" << "Total");


        ui->tree_list_pub->expandItem(ui->tree_list_pub->topLevelItem(0));
    }
}

/**
 * @brief AnalyzeCSV::populate_grant_tree fills the tree_list_vo with grant info
 * @param p_tree holds the grant info to be written to QTreeWidget
 */
void AnalyzeCSV::populate_grant_tree(std::shared_ptr<CSVData<GrantDTO>> data)
{

    QString st_string = ui->start_date_combo_grnt->itemText(ui->start_date_combo_grnt->currentIndex());
    QString en_string = ui->end_date_combo_grnt->itemText(ui->end_date_combo_grnt->currentIndex());
    int s = stoi(st_string.toStdString()); // start date
    int e = stoi(en_string.toStdString()); // end date

    // Ensure the retrieved years are in the accepted range
    if (e <= s)
    {
        cout << "Filter dates error" << endl;
    }
    else
    {
        TreeList_VO<GrantDTO> treelistvo(data, s, e);

        //Failed to make vo due to empty data range for that year
        if(treelistvo.isEmpty()) return;

        ui->tree_list_grnt->clear();
        treelistvo.makeQTree(ui->tree_list_grnt);
        ui->tree_list_grnt->setColumnCount(treelistvo.nCol);
        ui->tree_list_grnt->setColumnWidth(0, 275);
        ui->tree_list_grnt->setHeaderLabels(QStringList() << "Type" << "Total#" << "Total$");


        ui->tree_list_grnt->expandItem(ui->tree_list_grnt->topLevelItem(0));
    }
}

/**
 * @brief AnalyzeCSV::populate_teaching_tree fills the tree_list_vo with teaching info
 * @param p_tree holds the teaching info to be written to QTreeWidget
 */
void AnalyzeCSV::populate_teaching_tree(std::shared_ptr<CSVData<TeachingDTO>> data)
{
    QString st_string = ui->start_date_combo_teach->itemText(ui->start_date_combo_teach->currentIndex());
    QString en_string = ui->end_date_combo_teach->itemText(ui->end_date_combo_teach->currentIndex());
    int s = stoi(st_string.toStdString()); // start date
    int e = stoi(en_string.toStdString()); // end date

    // Ensure the retrieved years are in the accepted range
    if (e < s)
    {
        cout << "Filter dates error" << endl;
    }
    else
    {
        TreeList_VO<TeachingDTO> treelistvo(data, s, e);

        //Failed to make vo due to empty data range for that year
        if(treelistvo.isEmpty()) return;

        ui->tree_list_teach->clear();
        treelistvo.makeQTree(ui->tree_list_teach);
        ui->tree_list_teach->setColumnCount(treelistvo.nCol);
        ui->tree_list_teach->setColumnWidth(0, 275);
        ui->tree_list_teach->setHeaderLabels(QStringList() << "Type" << "Hours" << "Students");


        ui->tree_list_teach->expandItem(ui->tree_list_grnt->topLevelItem(0));
    }


}

// Do by jerry
void AnalyzeCSV::populate_presentation_tree(std::shared_ptr<CSVData<PresentationDTO>> data)
{
    QString st_string = ui->start_date_combo_pres->itemText(ui->start_date_combo_pres->currentIndex());
    QString en_string = ui->end_date_combo_pres->itemText(ui->end_date_combo_pres->currentIndex());

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
        tree_list_vo *pr_treeNew = new tree_list_vo(data);
        // Populate the VO with Presentation data and complete range
        pr_treeNew->populate_for_presentations(data,(int)s,(int)e);
        tmpUI->tree_list_pres->clear();

        ///LIST TREE VIEW (POPULATE TREE LIST IN GUI WITH DATA)///
        tmpUI->tree_list_pres->setColumnCount(2);
        tmpUI->tree_list_pres->setColumnWidth(0,275);
        tmpUI->tree_list_pres->setHeaderLabels(QStringList() << "Presentation Type" << "# Presentations");


        int presCounter = 0;    // Counter for presentations added
        QTreeWidgetItem * root = new QTreeWidgetItem(tmpUI->tree_list_pres, QStringList() << "Presentations" << QString::fromStdString(std::to_string(data->dtos->size())));
        for (size_t i = 0; i < pr_treeNew->get_parent_set().size(); i ++)
        {
            QTreeWidgetItem * child = new QTreeWidgetItem(root, QStringList() << QString::fromStdString(pr_treeNew->get_parent_set().at(i).label)
                                                          <<QString::fromStdString(std::to_string((int)pr_treeNew->get_parent_set().at(i).num)) );

            vector<string_data_object> tmp = pr_treeNew->get_child_set().at(i);
            for (size_t j = 0; j < tmp.size(); j ++)
            {
                new QTreeWidgetItem(child, QStringList() << QString::fromStdString(tmp.at(j).label)
                                    << QString::fromStdString(std::to_string((int)tmp.at(j).num)) );
                presCounter += tmp.at(j).num;
            }
        }

        tmpUI->tree_list_pres->expandItem(root);
        root->setText(1, QString::fromStdString(std::to_string(presCounter)));
    }

}

void AnalyzeCSV::populate_teaching_bargraph(std::shared_ptr<CSVData<TeachingDTO>> data){
    QString st_string = ui->start_date_combo_teach->itemText(ui->start_date_combo_teach->currentIndex());
    QString en_string = ui->end_date_combo_teach->itemText(ui->end_date_combo_teach->currentIndex());

    string s = st_string.toStdString(); // start date
    string e = en_string.toStdString(); // end date

    if (e <= s)
    {
        cout << "Cannot filter. Filter dates error." << endl;
    }
    else
    {
        string name = (ui->name_combo_teach->currentText()).toStdString();
        string program = (ui->program_combo_teach->currentText()).toStdString();

        scene = new QGraphicsScene(this);   // Added for graphics window

        QCustomPlot *customPlot = new QCustomPlot();
        customPlot->setGeometry(0,0,345,375);   // added to resize graph

        Graphvisualizations *graph_handler = new Graphvisualizations();

        try {
            if (program == "ALL") {
                shared_ptr<BarGraph_VO<TeachingDTO>> graphable(new BarGraph_VO<TeachingDTO>(data, name, s, e, 1));
                graph_handler->plot_bargraph(customPlot, graphable, QString::fromStdString("Year"), QString::fromStdString("All Programs"));
            }
            else {
                shared_ptr<BarGraph_VO<TeachingDTO>> graphable(new BarGraph_VO<TeachingDTO>(data, name, program, s, e, 1));
                graph_handler->plot_bargraph(customPlot, graphable, QString::fromStdString("Year"), QString::fromStdString(program));
            }
        }
        catch (const std::out_of_range& oor) {
            std::fprintf(stderr, "No data to graph");
        }

        scene->addWidget(customPlot);   // Add plot to the window & Essential
        ui->graph_area_teach->setScene(scene);    // Added for grpahics & Essential
    }
}

void AnalyzeCSV::populate_publication_bargraph(std::shared_ptr<CSVData<PublicationDTO>> data)
{
    QString st_string = ui->start_date_combo_pub->itemText(ui->start_date_combo_pub->currentIndex());
    QString en_string = ui->end_date_combo_pub->itemText(ui->end_date_combo_pub->currentIndex());

    string s = st_string.toStdString(); // start date
    string e = en_string.toStdString(); // end date

    if (e <= s) // Make sure the end date is greater than the start date
    {
        fprintf(stderr, "Cannot filter. Filter dates error.");
    }
    else
    {
        string name = (ui->name_combo_pub->currentText()).toStdString(); // Allows user to choose name of author
        string type = (ui->type_combo_pub->currentText()).toStdString(); // Allows user to choose type of publication

        scene = new QGraphicsScene(this);   // Create the scene for plotting

        QCustomPlot *customPlot = new QCustomPlot();
        customPlot->setGeometry(0,0,345,375);   // added to resize graph

        // Graph handling functions go here
        Graphvisualizations *graph_handler = new Graphvisualizations();

        try {
            if (type == "ALL")  // Graph ALL publication types by default
            {
                shared_ptr<BarGraph_VO<PublicationDTO>> graphable(new BarGraph_VO<PublicationDTO>(data, name, s, e, 1));
                graph_handler->plot_bargraph(customPlot, graphable, QString::fromStdString("Year"), QString::fromStdString("All Types"));
            }
            else                    // Create graphable of only specified publication types
            {
                shared_ptr<BarGraph_VO<PublicationDTO>> graphable(new BarGraph_VO<PublicationDTO>(data, name, type, s, e, 1));
                graph_handler->plot_bargraph(customPlot, graphable, QString::fromStdString("Year"), QString::fromStdString(type));
            }
        }
        // no data return, catch the exception
        catch (const std::out_of_range& oor) {
            fprintf(stderr, "No data to graph");
        }

        scene->addWidget(customPlot);   // Add plot to the GUI window
        ui->graph_area_pub->setScene(scene);    // Added to update the graph area
     }
}

void AnalyzeCSV::populate_presentation_bargraph(std::shared_ptr<CSVData<PresentationDTO>> data)
{
    QString st_string = ui->start_date_combo_pres->itemText(ui->start_date_combo_pres->currentIndex());
    QString en_string = ui->end_date_combo_pres->itemText(ui->end_date_combo_pres->currentIndex());

    string s = st_string.toStdString();
    string e = en_string.toStdString();

    if (e <= s)
    {
        cout << "Cannot filter. Filter dates error." << endl;
    }
    else
    {
        // Get the name and the type of graph being analyzed on the UI page
        string name = (ui->name_combo_pres->currentText()).toStdString();
        string type = (ui->type_combo_pres->currentText()).toStdString();

        scene = new QGraphicsScene(this);   // Create the scene for plotting

        QCustomPlot *customPlot = new QCustomPlot();
        customPlot->setGeometry(0,0,345,375);   // added to resize graph

        // Graph the data
        Graphvisualizations *graph_handler = new Graphvisualizations();

        try {
            if (type.compare("ALL") == 0)   // Graph ALL presentation types by default
            {
                shared_ptr<BarGraph_VO<PresentationDTO>>graphable (new BarGraph_VO<PresentationDTO>(data, name, s, e, 1));
                graph_handler->plot_bargraph(customPlot, graphable, QString::fromStdString("Year"), QString::fromStdString("All Types"));
            }
            else    // Create graph of only specified presentation type
            {
                shared_ptr<BarGraph_VO<PresentationDTO>>graphable (new BarGraph_VO<PresentationDTO>(data, name, type, s, e, 1));
                graph_handler->plot_bargraph(customPlot, graphable, QString::fromStdString("Year"), QString::fromStdString(type));
            }
        }
        catch (const std::out_of_range& oor) {
            fprintf(stderr, "No data to graph");
        }

        scene->addWidget(customPlot);   // Add plot to GUI window
        ui->graph_area_pres->setScene(scene);  // rename graph_are_7 to graph_area_Presentations
    }
}

void AnalyzeCSV::populate_grant_bargraph(std::shared_ptr<CSVData<GrantDTO>> data)
{
    QString st_string = ui->start_date_combo_grnt->itemText(ui->start_date_combo_grnt->currentIndex());
    QString en_string = ui->end_date_combo_grnt->itemText(ui->end_date_combo_grnt->currentIndex());

    string s = st_string.toStdString();
    string e = en_string.toStdString();

    if (e <= s)
    {
        cout << "Cannot filter. Filter dates error." << endl;
    }
    else
    {
        string name = (ui->name_combo_grnt->currentText()).toStdString();
        string funding = (ui->type_combo_grnt->currentText()).toStdString();

        scene = new QGraphicsScene(this);

        QCustomPlot *customPlot = new QCustomPlot();
        customPlot->setGeometry(0,0,345,375);   // added to resize graph

        Graphvisualizations *graph_handler = new Graphvisualizations();

        try {
            if (funding == "ALL") {
                shared_ptr<BarGraph_VO<GrantDTO>> graphable(new BarGraph_VO<GrantDTO>(data, name, s, e, 1));
                graph_handler->plot_bargraph(customPlot, graphable, QString::fromStdString("Year"), QString::fromStdString("All Funding Types"));
            }
            else {
                shared_ptr<BarGraph_VO<GrantDTO>> graphable(new BarGraph_VO<GrantDTO>(data, name, funding, s, e, 1));
                graph_handler->plot_bargraph(customPlot, graphable, QString::fromStdString("Year"), QString::fromStdString(funding));
            }
        }
        catch (const std::out_of_range& oor) {
            fprintf(stderr, "No data to graph");
        }

        scene->addWidget(customPlot);   // Add plot to the window & Essential
        ui->graph_area_grnt->setScene(scene);    // Added for grpahics & Essential
    }
}


// JX --> implemented 11.15.15
void AnalyzeCSV::on_filter_btn_grnt_clicked()
{
    // Catch to prevent analysis on a null pointer
    // Only catches error if data is loaded ONCE, therefore the pointers not being cleared at the end of a session
    if (grant_data == NULL)
    {
        // Add code to inform user that they didn't load proper information
    }
    else
    {
        populate_grant_tree(grant_data);
        populate_grant_bargraph(grant_data);
    }
}

// Jerry This populates the preseentation tree in the tree view
void AnalyzeCSV::on_filter_btn_pres_clicked()
{
    // Catch to prevent analysis on a null pointer
    // Only catches error if data is loaded ONCE, therefore the pointers not being cleared at the end of a session
    if (pres_data == NULL)
    {
        // Add code to inform user that they didn't load proper information
    }
    else
    {
        // Index 0 bargraph
        // Index 1 is pie chart
        populate_presentation_tree(pres_data);
        populate_presentation_bargraph(pres_data);
    }
}

void AnalyzeCSV::on_filter_btn_teach_clicked()
{
    if (teach_data == NULL)
    {
        // Add code to inform user that they didn't load proper information
    }
    else
    {
        populate_teaching_tree(teach_data);
        populate_teaching_bargraph(teach_data);
    }
}

void AnalyzeCSV::on_name_combo_pub_activated()
{
    if (pub_data == NULL) {
        // Add code to inform user that they didn't load proper information
    }
    else {
        populate_publication_bargraph(pub_data);
    }
}

void AnalyzeCSV::on_type_combo_pub_activated()
{
    if (pub_data == NULL) {
        // Add code to inform user that they didn't load proper information
    }
    else {
        populate_publication_bargraph(pub_data);
    }
}

void AnalyzeCSV::on_name_combo_grnt_activated()
{
    if (grant_data == NULL) {
        // Add code to inform user that they didn't load proper information
    }
    else {
        populate_grant_bargraph(grant_data);
    }
}

void AnalyzeCSV::on_type_combo_grnt_activated()
{
    if (grant_data == NULL) {
        // Add code to inform user that they didn't load proper information
    }
    else {
        populate_grant_bargraph(grant_data);
    }
}

void AnalyzeCSV::on_name_combo_pres_activated()
{
    if (pres_data == NULL) {
        // Add code to inform user that they didn't load proper information
    }
    else {
        populate_presentation_bargraph(pres_data);
    }
}

void AnalyzeCSV::on_type_combo_pres_activated()
{
    if (pres_data == NULL) {
        // Add code to inform user that they didn't load proper information
    }
    else {
        populate_presentation_bargraph(pres_data);
    }
}

void AnalyzeCSV::on_name_combo_teach_activated()
{
    if (teach_data == NULL) {
        // Add code to inform user that they didn't load proper information
    }
    else {
        populate_teaching_bargraph(teach_data);
    }
}

void AnalyzeCSV::on_program_combo_teach_activated()
{
    if (teach_data == NULL) {
        // Add code to inform user that they didn't load proper information
    }
    else {
        populate_teaching_bargraph(teach_data);
    }
}
