#ifndef ANALYZE_CSV_H
#define ANALYZE_CSV_H

#include <QMainWindow>
#include <qcustomplot.h>
#include <QtCore>
#include <QtGui>
#include <QStringList>

#include <vector>

#define NTAB 4

enum FilterValueType: unsigned int;
class Data;
class ComboBox;

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


private:
    Data *data;
    std::vector<ComboBox *> cmbBoxes;
    Ui::AnalyzeCSV *ui;
    QGraphicsScene * scene; // Added to display the graph through the graph area
    QCustomPlot *customPlot;

    void resizeEvent(QResizeEvent*);

    //Getter methods for constructor
    QComboBox *getCmbStartYear(std::size_t i);
    QComboBox *getCmbEndYear(size_t i);
    QComboBox *getCmbName(size_t i);
    QComboBox *getCmbType(size_t i);
};

#endif // ANALYZE_CSV_H
