#include "graphvisualizations.h"

Graphvisualizations::Graphvisualizations()
{
    // default constructor
}

void Graphvisualizations::plot_pub_vs_type(QCustomPlot* customPlot)
{
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }


    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("Type");
    customPlot->yAxis->setLabel("Publications");
    customPlot->xAxis->setRange(-1, 1);
    customPlot->yAxis->setRange(0, 1);
    customPlot->replot();
}

