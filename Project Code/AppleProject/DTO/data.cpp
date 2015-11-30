#include "data.h"

using namespace std;

Data* Data::_instance = 0;

Data::Data(){
    csv = vector<shared_ptr<CSVDTO>>(4);
}

Data* Data::Instance()
{
    if(_instance == 0) _instance = new Data;
    return _instance;
}

std::shared_ptr<CSVDTO> Data::getDTO(size_t t){
    return Instance()->csv.at(t);
}

bool Data::loadDTO(string fname, size_t t){
    CSVType type = (CSVType)t;
    std::shared_ptr<CSVDTO> newcsv(new CSVDTO(&fname, type));
    csv.at(t).swap(newcsv);
    return true;
}
