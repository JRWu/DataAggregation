#ifndef ANALYZE_CSV_H
#define ANALYZE_CSV_H

#include <QMainWindow>
#include <qcustomplot.h>

#include <iostream> // rm later
#include <stdio.h>  // rem later

namespace Ui {
class AnalyzeCSV;
}

class AnalyzeCSV : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnalyzeCSV(QWidget *parent = 0);
    ~AnalyzeCSV();

private slots:
    //void on_load_btn_clicked();

    void on_verify_btn_clicked();


private:
    Ui::AnalyzeCSV *ui;
    QGraphicsScene * scene; // Added to display the graph through the graph area
    QCustomPlot *customPlot;
};

#endif // ANALYZE_CSV_H
