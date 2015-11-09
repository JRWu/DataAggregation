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

class tree_list_vo;     //forward pointer

namespace Ui {
class AnalyzeCSV;
}

class AnalyzeCSV : public QMainWindow
{
    Q_OBJECT

QStringList PopulateDateCombos(std::shared_ptr<CSVData<PublicationDTO>> data);
QStringList PopulateDateCombos(std::shared_ptr<CSVData<PresentationDTO>> data);
QStringList PopulateDateCombos(std::shared_ptr<CSVData<GrantDTO>> gdata);


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
    void on_filter_btn_clicked_teaching();

    void on_filter_btn_teach_clicked();

private:
    Ui::AnalyzeCSV *ui;
    QGraphicsScene * scene; // Added to display the graph through the graph area
    QCustomPlot *customPlot;
    tree_list_vo* p_tree;
    tree_list_vo* teach_tree;
    std::shared_ptr<CSVData<PublicationDTO>> data;
    std::shared_ptr<CSVData<GrantDTO>> gdata;
    std::shared_ptr<CSVData<PresentationDTO>> data4; //data for presentation

    void populate_publication_tree();
    void populate_grant_tree();
    void populate_teaching_tree();
    void pouplate_presentation_tree();
};

#endif // ANALYZE_CSV_H
