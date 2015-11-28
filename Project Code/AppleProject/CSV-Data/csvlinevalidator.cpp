#include "csvlinevalidator.h"

using namespace std;

bool CSVLineValidator::validate(std::vector<CSVField> *line){
    return true;
}

CSVLineValidator* PublicationLineValidator::_instance = 0;

CSVLineValidator* PublicationLineValidator::Instance(){
    if(_instance == 0) _instance = new PublicationLineValidator();
    return _instance;
}

bool PublicationLineValidator::validate(vector<CSVField> *line){
    return true;
}


CSVLineValidator* GrantLineValidator::_instance = 0;

CSVLineValidator* GrantLineValidator::Instance(){
    if(_instance == 0) _instance = new GrantLineValidator();
    return _instance;
}

bool GrantLineValidator::validate(vector<CSVField> *line){
    int startY = stoi(line->at(1).getValue());
    int endY = stoi(line->at(2).getValue());
    return (startY <= endY);
}


CSVLineValidator* PresentationLineValidator::_instance = 0;

CSVLineValidator* PresentationLineValidator::Instance(){
    if(_instance == 0) _instance = new PresentationLineValidator();
    return _instance;
}

bool PresentationLineValidator::validate(vector<CSVField> *line){
    return true;
}

CSVLineValidator* TeachingLineValidator::_instance = 0;

CSVLineValidator* TeachingLineValidator::Instance(){
    if(_instance == 0) _instance = new TeachingLineValidator();
    return _instance;
}

bool TeachingLineValidator::validate(vector<CSVField> *line){
    int startY = stoi(line->at(1).getValue());
    int endY = stoi(line->at(2).getValue());

    double hpers = stod(line->at(8).getValue());
    double ns = stod(line->at(9).getValue());
    double totalh = stod(line->at(10).getValue());

    return ((startY <= endY)&&(totalh == (hpers*ns)));
}
