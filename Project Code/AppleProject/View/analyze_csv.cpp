#include "View/analyze_csv.h"
#include "View/ui_analyze_csv.h"

#include "DTO/data.h"
#include "DTO/csvdto.h"
#include "View/load_csv.h"
#include "Tab-Objects/combobox.h"
#include "Tab-Objects/bargraph.h"
#include "Tab-Objects/qcustomplot.h"
#include "Tab-Objects/treelist.h"

AnalyzeCSV::AnalyzeCSV(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::AnalyzeCSV)
{
    ui->setupUi(this);
    ui->verify_btn->setDisabled(true);

    data = Data::Instance();

    for(size_t i = 0; i < NTAB; ++i){
        if(data->isEmpty(i)){
            ui->tabWidget->setTabEnabled(i, false);
        }
        else{
            ui->tabWidget->setTabEnabled(i, true);

            CSVDTO *dto = data->getDTO(i);

            getLblDomain(i)->setText(QString::fromStdString(*dto->getDomain()));

            QComboBox *startY = getCmbStartYear(i);
            QComboBox *endY = getCmbEndYear(i);
            QComboBox *name = getCmbName(i);
            QComboBox *type = getCmbType(i);
            QGraphicsView *bar = getBarGraph(i);
            QTreeWidget *tree = getTreeList(i);

            ComboBox *sy = new ComboBox(startY, dto, FILTERYEAR);
            ComboBox *ey = new ComboBox(endY, dto, FILTERYEAR, sy);
            sy->update();
            ComboBox *n = new ComboBox(name, dto, FILTERNAME, ey);
            ComboBox *ty = new ComboBox(type, dto, FILTERTYPE, n);

            cmbBoxes.push_back(sy);
            cmbBoxes.push_back(ey);
            cmbBoxes.push_back(n);
            cmbBoxes.push_back(ty);

            BarGraph *b = new BarGraph(bar, dto, this, ty);
            barGraphs.push_back(b);

            TreeList *t = new TreeList(tree, dto, ey);
            sy->attach(t);
            treeLists.push_back(t);

            endY->setCurrentIndex(endY->count() - 1);
            ey->notify();
        }
    }

    ui->tabWidget->setCurrentIndex(data->getLastType());
}

void AnalyzeCSV::doneloading(){
    emit resizeEvent(0);
}

AnalyzeCSV::~AnalyzeCSV()
{
    for(size_t i = 0; i < cmbBoxes.size(); ++i){
        delete cmbBoxes[i];
    }
    for(size_t i = 0; i < barGraphs.size(); ++i){
        delete barGraphs[i];
    }
    for(size_t i = 0; i < treeLists.size(); ++i){
        delete treeLists[i];
    }

    delete ui;
}

void AnalyzeCSV::on_load_btn_clicked()
{
    this->setCentralWidget(new LoadCSV);
}

QTreeWidget *AnalyzeCSV::getTreeList(size_t i){
    switch(i){
    case(0): return ui->tree_list_pub;
    case(1): return ui->tree_list_grnt;
    case(2): return ui->tree_list_pres;
    case(3): return ui->tree_list_teach;
    }
    return 0;
}

QComboBox *AnalyzeCSV::getCmbStartYear(size_t i){
    switch(i){
    case(0): return ui->start_date_combo_pub;
    case(1): return ui->start_date_combo_grnt;
    case(2): return ui->start_date_combo_pres;
    case(3): return ui->start_date_combo_teach;
    }
    return 0;
}

QComboBox *AnalyzeCSV::getCmbEndYear(size_t i){
    switch(i){
    case(0): return ui->end_date_combo_pub;
    case(1): return ui->end_date_combo_grnt;
    case(2): return ui->end_date_combo_pres;
    case(3): return ui->end_date_combo_teach;
    }
    return 0;
}

QComboBox *AnalyzeCSV::getCmbName(size_t i){
    switch(i){
    case(0): return ui->name_combo_pub;
    case(1): return ui->name_combo_grnt;
    case(2): return ui->name_combo_pres;
    case(3): return ui->name_combo_teach;
    }
    return 0;
}

QComboBox *AnalyzeCSV::getCmbType(size_t i){
    switch(i){
    case(0): return ui->type_combo_pub;
    case(1): return ui->type_combo_grnt;
    case(2): return ui->type_combo_pres;
    case(3): return ui->program_combo_teach;
    }
    return 0;
}

QLabel *AnalyzeCSV::getLblDomain(size_t i){
    switch(i){
    case(0): return ui->domain_lbl_pub;
    case(1): return ui->domain_lbl_grnt;
    case(2): return ui->domain_lbl_pres;
    case(3): return ui->domain_lbl_teach;
    }
    return 0;
}

QGraphicsView *AnalyzeCSV::getBarGraph(size_t i){
    switch(i){
    case(0): return ui->graph_area_pub;
    case(1): return ui->graph_area_grnt;
    case(2): return ui->graph_area_pres;
    case(3): return ui->graph_area_teach;
    }
    return 0;
}



/*void AnalyzeCSV::populate_publication_tree(std::shared_ptr<CSVData<PublicationDTO>> data)
{

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
}*/

/*void AnalyzeCSV::populate_grant_tree(std::shared_ptr<CSVData<GrantDTO>> data)
{

    QString st_string = ui->start_date_combo_grnt->itemText(ui->start_date_combo_grnt->currentIndex());
    QString en_string = ui->end_date_combo_grnt->itemText(ui->end_date_combo_grnt->currentIndex());
    int s = stoi(st_string.toStdString()); // start date
    int e = stoi(en_string.toStdString()); // end date

    // Ensure the retrieved years are in the accepted range
    if (e < s)
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

    if (e < s)
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

}*/
