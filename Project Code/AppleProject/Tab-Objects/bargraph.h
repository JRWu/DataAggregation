#ifndef BARGRAPH_H
#define BARGRAPH_H

#include <QVector>
#include <QObject>

#include <vector>
#include <string>

#include "Tab-Objects/tabobserver.h"

class TabSubject;
class CSVDTO;
class QGraphicsView;
class QCustomPlot;
class AnalyzeCSV;

class BarGraph:public QObject, public TabObserver
{
    Q_OBJECT

    QGraphicsView *view;
    QCustomPlot *plot = 0;
    CSVDTO *dto;

    void loadValues(QVector<QString> *years, QVector<QString> *types, QVector<QVector<double> > *values );
    void makeGraph(QVector<QString> *years, QVector<QString> *types, QVector<QVector<double> > *values );
    std::string getYLabel();
    std::string getYTickLabel(double v);
public:
    BarGraph(QGraphicsView *v, CSVDTO *dto, AnalyzeCSV *p, TabSubject *s);
    void resize();
    void update();
public slots:
    void onResize();
};

#endif // BARGRAPH_H
