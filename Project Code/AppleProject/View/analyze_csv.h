#ifndef ANALYZE_CSV_H
#define ANALYZE_CSV_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>

#include <vector>



#define NTAB 4

enum FilterValueType: unsigned int;
class Data;
class ComboBox;
class BarGraph;
class QGraphicsScene;
class QCustomPlot;
class QComboBox;
class QLabel;
class QGraphicsView;

namespace Ui {
class AnalyzeCSV;
}

class AnalyzeCSV : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnalyzeCSV(QWidget *parent = 0);
    ~AnalyzeCSV();

signals:
    //Capture a resize event
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_load_btn_clicked();



private:
    Data *data;
    std::vector<ComboBox *> cmbBoxes;
    std::vector<BarGraph *> barGraphs;
    Ui::AnalyzeCSV *ui;
    QGraphicsScene * scene; // Added to display the graph through the graph area
    QCustomPlot *customPlot;

    //Getter methods for constructor
    QComboBox *getCmbStartYear(std::size_t i);
    QComboBox *getCmbEndYear(std::size_t i);
    QComboBox *getCmbName(std::size_t i);
    QComboBox *getCmbType(std::size_t i);
    QLabel *getLblDomain(std::size_t i);
    QGraphicsView *getBarGraph(std::size_t i);
};

#endif // ANALYZE_CSV_H
