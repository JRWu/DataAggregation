#include "dtofilter.h"

using namespace std;

DTOFilter::DTOFilter(std::string n, std::string sy, std::string ey, std::string t)
{
    name = n;
    syear = sy;
    eyear = ey;
    type = t;
}

bool DTOFilter::filter(FilterAdapter *b){
    string n = b->getName();
    string y = b->getYear();
    string t = b->getType();

    return (n == name)&&((type == "ALL")||(t == type))&&(syear <= y)&&(y <= eyear);
}

bool DTOFilter::isValid(){
    return (syear <= eyear);
}
