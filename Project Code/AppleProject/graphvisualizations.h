#ifndef GRAPHVISUALIZATIONS_H
#define GRAPHVISUALIZATIONS_H

#include <qcustomplot.h>
#include <memory>

#include "pres_bargraph1_vo.h"
#include "bargraph_vo.h"

class Pub_BarGraph1_VO; // Forward pointer to silence warning
class Teach_BarGraph1_VO;   // To add by Eric + Emily
class Grant_BarGraph1_VO;   // to add by Jaisen/Jennifer
//class Pres_BarGraph1_VO;        // To add for Jerry

class Graphvisualizations
{
    //

public:
    Graphvisualizations();

    //Bar Graph Creator
    template <class DTOType> void plot_bargraph(QCustomPlot* customPlot, std::shared_ptr<BarGraph_VO<DTOType>> vo);

    // Add support for shared pointer afterwards
    void plot_pub_vs_type(QCustomPlot* plot, Pub_BarGraph1_VO* bargraph_vo);

    void plot_pres_vs_type(QCustomPlot* plot, Pres_BarGraph1_VO* bargraph_vo);

    //1)  For faculty member (name), graph publications by type
        // ^ For a certain date range

    //2)For faculty member (name), graph funded research(grants/trials)
        // ^ For a certain date range
    void plot_grants_vs_trials(QCustomPlot* plot, Grant_BarGraph1_VO* grant_vo);


    //3)For faculty name, graph publication types by date (bar chart?)
    void plot_pubtype_vs_date(QCustomPlot* plot);

    //4)For faculty name, graph teaching by program level
        // ^ for a certain date range
    void plot_teaching_vs_course(QCustomPlot* customPlot, Teach_BarGraph1_VO* bargraph_vo);

    //5)For faculty name, graph course/activity by program level
        // ^ For a certain date range

private:
    void bar_plot(QCustomPlot* plot);        // Deal with later
    void pie_chart(QCustomPlot* plot);      // Implement later
};


template <class DTOType> void Graphvisualizations::plot_bargraph(QCustomPlot* customPlot, std::shared_ptr<BarGraph_VO<DTOType>> vo){

    double maxY = 0;   // Save the maximum value for y range

    QCPBarsGroup *group = new QCPBarsGroup(customPlot);
    QCPBars *bars = new QCPBars(customPlot->xAxis, customPlot->yAxis);

    QVector<double> xvalues;

    //Store the year strings to double values
    for (int i = 0; i < (int)vo->field1.size(); i ++)    // Iterate through years, assign double values
    {
        xvalues.push_back(std::stod(vo->field1.at(i)) );
    }

    QVector<QVector<double>> yvalues; // Contains converted double vector of QVector type
    for (int i = 0; i < (int)vo->field2.size(); i ++)
    {
        vector<double> y_add = vo->values.at(i);  // Load the set data for each year for this field

        QVector<double> y_add_to_yval;  // retrieve QVector<double> ytemp
        for (int j = 0; j < (int)vo->field1.size(); j ++) // Iterate  through years
        {
            y_add_to_yval.push_back(y_add.at(j));

            if(y_add.at(j) > maxY)
            {
                maxY = y_add.at(j);
            }
        }
        yvalues.push_back(y_add_to_yval);   // Add the converted set to final double vector of QVector type
    }

    // Add each component, with the colour changing based on index
    for (int i = 0; i < vo->field2.size(); i++)
    {
        bars = new QCPBars(customPlot->xAxis, customPlot->yAxis);
        customPlot->addPlottable(bars);
        QVector<double> y_component = yvalues.at(i);
        bars->setData(xvalues,y_component);
        bars->setBrush(QColor(  (i*21)%255  ,(i*11)%255 ,255-(i*21)%255,50));  // 255/12 ~= 21 (21 gives best coverage)
        bars->setPen(QColor( (i*21)%255, (i*2)%255 , 255-(i*21)%255));
        bars->setWidth(0.1);
        bars->setBarsGroup(group);
    }

    //Title = faculty name
    customPlot->plotLayout()->insertRow(0);
    QString str = vo->name.c_str();  // Set the name of the author

    customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(customPlot, str)); //title of the graph
    customPlot->xAxis->setRange((xvalues.at(0))-1, (xvalues.at(xvalues.size()-1))+1);   // Set range of graph   +/-3 so bars wont be on edges
    customPlot->xAxis->setAutoTickStep(false);
    customPlot->xAxis->setTickStep(1);

    customPlot->yAxis->setAutoTickStep(false);  // force integer for Y only (be wary of doing this with grants)
    customPlot->yAxis->setTickStep(1);  // force integer for Y only (be wary of doing this with grants)

    customPlot ->yAxis->setRange(0,maxY+1);
    customPlot->xAxis->setLabel("Year");
    customPlot->yAxis->setLabel("Publications");
}

#endif // GRAPHVISUALIZATIONS_H

