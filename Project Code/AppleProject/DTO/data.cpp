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

std::shared_ptr<CSVDTO> Data::getDTO(size_t i){
    return Instance()->csv.at(i);
}

bool Data::loadDTO(string fname, CSVType t){
    std::shared_ptr<CSVDTO> newcsv(new CSVDTO(fname, t));
    csv.at(t).swap(newcsv);
    return true;
}
