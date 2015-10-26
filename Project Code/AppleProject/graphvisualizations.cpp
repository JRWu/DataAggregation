#include "graphvisualizations.h"
#include "pub_bargraph1_vo.h"
Graphvisualizations::Graphvisualizations()
{
    // default constructor
}

void Graphvisualizations::plot_pub_vs_type(QCustomPlot* customPlot, Pub_BarGraph1_VO* bargraph_vo)
{

    QCPBarsGroup *group = new QCPBarsGroup(customPlot);
    QCPBars *bars = new QCPBars(customPlot->xAxis, customPlot->yAxis);

    //Sort the year strings to int values
    QVector<double> xvalues;

    for (int i = 0; i < bargraph_vo->years.size(); i ++)    // Iterate through years, assign double values
    {
        xvalues.push_back(std::stod(bargraph_vo->years.at(i)) );
        cout <<"ixvalues: " << xvalues.at(i)<<endl;
    }   // Successfully stores string years into a set of doubles

    QVector<QVector<double>> yvalues; // Contains converted double vector of QVector type
    for (int i = 0; i < bargraph_vo->values.size(); i ++)   // Iterate through # Publications [13]
    {
        vector<int> y_add;          // Load the set of years from the bargraph_vo object
        y_add = bargraph_vo->values.at(i);

        QVector<double> y_add_to_yval;  // retrieve QVector<double> ytemp
        for (int j = 0; j < bargraph_vo->years.size(); j ++) // Iterate  through #years per Publication [11]
        {
            y_add_to_yval.push_back(y_add.at(j));
        }
        yvalues.push_back(y_add_to_yval);   // Add the converted set to final double vector of QVector type
    }

    int maxY = 0;   // Save the maximum value for y range

    //TEST  RM LATER vvv
    cout << "TESTING FOR SAVED VALUES\n";
    for(int i = 0; i < yvalues.size(); i ++)
    {

        QVector<double> size = yvalues.at(i);
        cout <<"QVector<double> size.size: " << std::to_string(size.size()) << endl;
        for (int j = 0; j < size.size(); j ++)
        {
            cout <<"x "<<": "<< std::to_string(size.at(j)) << " ";
            if(size.at(j) > maxY)
            {
                maxY= size.at(j);
            }
        }
        cout << endl;
    }

    //TEST  RM LATER ^^^




    // Add each component, with the colour changing based on index
    for (int i = 0; i < bargraph_vo->pubTypes.size(); i ++)
    {
        bars = new QCPBars(customPlot->xAxis, customPlot->yAxis);
        customPlot->addPlottable(bars);
        QVector<double> y_component = yvalues.at(i);
        bars->setData(xvalues,y_component);
        bars->setBrush(QColor(  (i*21)%255  ,(i*11)%255 ,255-(i*21)%255,50));  // 255/12 ~= 21 (21 gives best coverage)
        bars->setPen(QColor( (i*21)%255, (i*2)%255 , 255-(i*21)%255));
        bars->setWidth(0.3);
        bars->setBarsGroup(group);
    }

    // Angus you can add the title of the graph here
    customPlot->xAxis->setRange((xvalues.at(0))-3, (xvalues.at(xvalues.size()-1))+3);   // Set range of graph   +/-3 so bars wont be on edges
    customPlot ->yAxis->setRange(0,maxY);
    customPlot->xAxis->setLabel("Year");
    customPlot->yAxis->setLabel("Publications");
}

