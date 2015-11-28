#include "bargraphadapter.h"

using namespace std;

BarGraphAdapter::BarGraphAdapter(vector<CSVField> *csvline, CSVType csvtype)
{
    line = csvline;
    t = csvtype;
    if(t == PUBLICATION){
        year = 1;
        type = 5;
        value = 1.0;
    }
    else if(t == GRANTS){
        year = 2;
        type = 5;

        string status = line->at(6).getValue();
        if(status == "Funded") value = stod(line->at(12).getValue());
        else value = 0.0;
    }
    else if(t == PRESENTATION){
        year = 1;
        type = 4;
        value = 1.0;
    }
    else{
        year = 2;
        type = 4;
        value = 1.0;
    }
}

string BarGraphAdapter::getYear(){
    return line->at(year).getField();
}

string BarGraphAdapter::getType(){
    return line->at(type).getField();
}

double BarGraphAdapter::getValue(){
    return value;
}
