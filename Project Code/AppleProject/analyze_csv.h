#ifndef ANALYZE_CSV_H
#define ANALYZE_CSV_H

#include <QMainWindow>
#include <qcustomplot.h>
#include <QtCore>
#include <QtGui>
#include <QStringList>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>

#include <iostream> // rm later
#include <stdio.h>  // rem later

#include "csvdata.h"
#include "grantdto.h"
#include "publicationdto.h"
#include "teachingdto.h"
#include "tree_list_vo.h"
#include "graphvisualizations.h"
#include "grant_bargraph1_vo.h"
#include "teach_bargraph1_vo.h"
#include "bargraph_vo.h"
#include "graph_combo_box_populator.h"
#include "treelist_vo.h"
#include "date_filter_combo_populator.h"


class tree_list_vo;     //forward pointer

namespace Ui {
class AnalyzeCSV;
}

class AnalyzeCSV : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnalyzeCSV(std::shared_ptr<CSVData<PublicationDTO>> data, QWidget *parent = 0);
    explicit AnalyzeCSV(std::shared_ptr<CSVData<GrantDTO>> data, QWidget *parent = 0);
    explicit AnalyzeCSV(std::shared_ptr<CSVData<PresentationDTO>> data, QWidget *parent = 0);
    explicit AnalyzeCSV(std::shared_ptr<CSVData<TeachingDTO>> data, QWidget *parent = 0);
    ~AnalyzeCSV();

//    void GenerateTreeView()

private slots:
    Ui::AnalyzeCSV* get_ui_ptr();
    void on_load_btn_clicked();
    void on_verify_btn_clicked();

    void on_filter_btn_pres_clicked();

    void on_filter_btn_teach_clicked();

    void on_filter_btn_pub_clicked();

    void on_filter_btn_grnt_clicked();

private:
    Ui::AnalyzeCSV *ui;
    QGraphicsScene * scene; // Added to display the graph through the graph area
    QCustomPlot *customPlot;

    // tree_list_vo pointers for respective csv generation
    tree_list_vo* p_tree;
    tree_list_vo* teach_tree;

    void populate_publication_tree(std::shared_ptr<CSVData<PublicationDTO>> data);
    void populate_grant_tree(std::shared_ptr<CSVData<GrantDTO>> data);
    void populate_teaching_tree(std::shared_ptr<CSVData<TeachingDTO>> data);
    void populate_presentation_tree(std::shared_ptr<CSVData<PresentationDTO>> data);

    void populate_teaching_bargraph(std::shared_ptr<CSVData<TeachingDTO>> data);
    void populate_grant_bargraph(std::shared_ptr<CSVData<GrantDTO>> data);
    void populate_publication_bargraph(std::shared_ptr<CSVData<PublicationDTO>> data);
    void populate_presentation_bargraph(std::shared_ptr<CSVData<PresentationDTO>> data);

    void AddRoot(QString field, QString total);
    QTreeWidgetItem* AddChild(QTreeWidgetItem *parent, QString field, QString total);
    QTreeWidgetItem* AddGrandChild(QTreeWidgetItem *parent, QString field, QString total);

};

#endif // ANALYZE_CSV_H
