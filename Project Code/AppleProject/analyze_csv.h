#ifndef ANALYZE_CSV_H
#define ANALYZE_CSV_H

#include "csvdata.h"
#include "publicationdto.h"
#include <QMainWindow>
#include <qcustomplot.h>
#include <QtCore>
#include <QtGui>
#include <QStringList>

#include <iostream> // rm later
#include <stdio.h>  // rem later

#include "graphvisualizations.h"

namespace Ui {
class AnalyzeCSV;
}

class AnalyzeCSV : public QMainWindow
{
    Q_OBJECT

void AddRoot(QString field, QString total);
void AddChild(QTreeWidgetItem *parent, QString field, QString total);
void AddGrandChild(QTreeWidgetItem *parent, QString field, QString total);

public:
    explicit AnalyzeCSV(std::shared_ptr<CSVData<PublicationDTO>> data, QWidget *parent = 0);
    ~AnalyzeCSV();

private slots:
    void on_load_btn_clicked();

    void on_verify_btn_clicked();


private:
    Ui::AnalyzeCSV *ui;
    QGraphicsScene * scene; // Added to display the graph through the graph area
    QCustomPlot *customPlot;
};

#endif // ANALYZE_CSV_H
