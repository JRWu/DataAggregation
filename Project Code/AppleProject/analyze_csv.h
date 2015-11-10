#ifndef ANALYZE_CSV_H
#define ANALYZE_CSV_H

#include "csvdata.h"
#include "grantdto.h"
#include "publicationdto.h"
#include "teachingdto.h"
#include "tree_list_vo.h"
#include <QMainWindow>
#include <qcustomplot.h>
#include <QtCore>
#include <QtGui>
#include <QStringList>

#include <iostream> // rm later
#include <stdio.h>  // rem later

#include "graphvisualizations.h"
#include "pub_bargraph1_vo.h"
#include "grant_bargraph1_vo.h"
#include "teach_bargraph1_vo.h"
#include "ui_analyze_csv.h"

class tree_list_vo;     //forward pointer

namespace Ui {
class AnalyzeCSV;
}

class AnalyzeCSV : public QMainWindow
{
    Q_OBJECT

QStringList PopulateDateCombos(std::shared_ptr<CSVData<PublicationDTO>> data);
QStringList PopulateDateCombos(std::shared_ptr<CSVData<PresentationDTO>> data); // Needs to be implemented
QStringList PopulateDateCombos(std::shared_ptr<CSVData<GrantDTO>> gdata);          // Needs to be implemented
QStringList PopulateDateCombos(std::shared_ptr<CSVData<TeachingDTO>> gdata);     // Needs to be implemented


void AddRoot(QString field, QString total);
QTreeWidgetItem* AddChild(QTreeWidgetItem *parent, QString field, QString total);
QTreeWidgetItem* AddGrandChild(QTreeWidgetItem *parent, QString field, QString total);

public:
    explicit AnalyzeCSV(std::shared_ptr<CSVData<PublicationDTO>> data, QWidget *parent = 0);
    explicit AnalyzeCSV(std::shared_ptr<CSVData<GrantDTO>> data, QWidget *parent = 0);
    explicit AnalyzeCSV(std::shared_ptr<CSVData<PresentationDTO>> data, QWidget *parent = 0);
    explicit AnalyzeCSV(std::shared_ptr<CSVData<TeachingDTO>> data, QWidget *parent = 0);
    ~AnalyzeCSV();

//    void GenerateTreeView()

private slots:
    void on_load_btn_clicked();
    void on_verify_btn_clicked();
    Ui::AnalyzeCSV* get_ui_ptr();
    void on_filter_btn_clicked();
    void on_filter_btn_teach_clicked();
    void on_filter_btn_2_clicked();

    void on_filter_btn_presentation_clicked();


private:
    Ui::AnalyzeCSV *ui;
    QGraphicsScene * scene; // Added to display the graph through the graph area
    QCustomPlot *customPlot;

    // tree_list_vo pointers for respective csv generation
    tree_list_vo* p_tree;
    tree_list_vo* teach_tree;

    // Shared pointers for VO generation
    std::shared_ptr<CSVData<PublicationDTO>> data;
    std::shared_ptr<CSVData<GrantDTO>> gdata;
    std::shared_ptr<CSVData<TeachingDTO>> tdata;
    std::shared_ptr<CSVData<PresentationDTO>> pr_data; //data for presentation

    void populate_publication_tree();
    void populate_grant_tree();
    void populate_teaching_tree();
    void populate_presentation_tree();
};

#endif // ANALYZE_CSV_H
