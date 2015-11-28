#include "filteradapter.h"

using namespace std;

FilterAdapter::FilterAdapter(std::vector<CSVField> *csvline, CSVType t)
{
    line = csvline;
    if(t == PUBLICATION){
        year = 1;
        name = 2;
        type = 5;
    }
    else if(t == GRANTS){
        year = 2;
        name = 3;
        type = 5;
    }
    else if(t == PRESENTATION){
        year = 1;
        name = 2;
        type = 4;
    }
    else{
        year = 2;
        name = 3;
        type = 4;
    }
}

string FilterAdapter::getName(){
   return line->at(name).getField();
}

string FilterAdapter::getYear(){
    return line->at(year).getField();
}

string FilterAdapter::getType(){
    return line->at(type).getField();
}

