#ifndef GRAPHVISUALIZATIONS_H
#define GRAPHVISUALIZATIONS_H

#include <qcustomplot.h>
class Pub_BarGraph1_VO; // Forward pointer to silence warning
class Teach_BarGraph1_VO;

class Graphvisualizations
{
    //



public:
    Graphvisualizations();

    // Add support for shared pointer afterwards
    void plot_pub_vs_type(QCustomPlot* plot, Pub_BarGraph1_VO* bargraph_vo);

    //1)  For faculty member (name), graph publications by type
        // ^ For a certain date range




    //2)For faculty member (name), graph funded research(grants/trials)
        // ^ For a certain date range
    void plot_grants_vs_trials(QCustomPlot* plot);





    //3)For faculty name, graph publication types by date (bar chart?)
    void plot_pubtype_vs_date(QCustomPlot* plot);


    //4)For faculty name, graph teaching by program level
        // ^ for a certain date range
    void plot_teaching_vs_course(QCustomPlot* customPlot, Teach_BarGraph1_VO* bargraph_vo);

    //5)For faculty name, graph course/activity by program level
        // ^ For a certain date range

private:
    void bar_plot(QCustomPlot* plot);
    void pie_chart(QCustomPlot* plot);

};

#endif // GRAPHVISUALIZATIONS_H

