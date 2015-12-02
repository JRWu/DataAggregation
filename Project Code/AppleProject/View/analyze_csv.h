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

#include "View/load_csv.h"

#include "DTO/data.h"
#include "DTO/csvdto.h"

#include "Tab-Objects/combobox.h"
#include "Tab-Objects/filtervalue.h"

#define PUB 0
#define GRANT 1
#define PRES 2
#define TEACH 3
#define NCSV 4

enum FilterValueType: unsigned int;


namespace Ui {
class AnalyzeCSV;
}

class AnalyzeCSV : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnalyzeCSV(QWidget *parent = 0);
    ~AnalyzeCSV();

//    void GenerateTreeView()

private slots:
    void on_load_btn_clicked();

    void on_verify_btn_clicked();

    void on_filter_btn_pres_clicked();

    void on_filter_btn_teach_clicked();

    void on_filter_btn_pub_clicked();

    void on_filter_btn_grnt_clicked();

    void on_name_combo_pub_activated();

    void on_type_combo_pub_activated();

    void on_name_combo_grnt_activated();

    void on_type_combo_grnt_activated();

    void on_name_combo_pres_activated();

    void on_type_combo_pres_activated();

    void on_name_combo_teach_activated();

    void on_program_combo_teach_activated();

private:
    Ui::AnalyzeCSV *ui;
    QGraphicsScene * scene; // Added to display the graph through the graph area
    QCustomPlot *customPlot;

    // tree_list_vo pointers for respective csv generation
    //tree_list_vo* p_tree;
    //tree_list_vo* teach_tree;

    void AddRoot(QString field, QString total);
    QTreeWidgetItem* AddChild(QTreeWidgetItem *parent, QString field, QString total);
    QTreeWidgetItem* AddGrandChild(QTreeWidgetItem *parent, QString field, QString total);

    void resizeEvent(QResizeEvent*);
};

#endif // ANALYZE_CSV_H
