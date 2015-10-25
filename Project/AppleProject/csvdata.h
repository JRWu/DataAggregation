#ifndef CSVDATA_H
#define CSVDATA_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <QFileDialog>  // For opening file windows
#include <QMessageBox>  // For showing the file name after selection

template <class DTOType> class CSVData
{
public:
    std::shared_ptr<std::vector<std::vector<std::string>>> errorRows;
    //std::vector<DTOType> dtos;

    CSVData();
    ~CSVData();
    void addError(std::vector<std::string>);
};

template <class DTOType> CSVData<DTOType>::CSVData(){
    errorRows = std::shared_ptr<std::vector<std::vector<std::string>>>
                                    (new std::vector<std::vector<std::string>> );
}

template <class DTOType> CSVData<DTOType>::~CSVData(){}

template <class DTOType>
void CSVData<DTOType>::addError(std::vector<std::string> f){
    errorRows->push_back(f);
}

#endif // CSVDATA_H
