#ifndef CSVDATA_H
#define CSVDATA_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>

template <class DTOType> class CSVData
{
public:
    std::shared_ptr<std::vector<std::vector<std::string>>> errorRows;
    std::shared_ptr<std::vector<DTOType>> dtos;

    CSVData();
    ~CSVData();
    void addError(std::vector<std::string>);
    void addDTO(DTOType dto);
};

template <class DTOType> CSVData<DTOType>::CSVData(){
    errorRows = std::shared_ptr<std::vector<std::vector<std::string>>>
                                    (new std::vector<std::vector<std::string>> );
    dtos = std::shared_ptr<std::vector<DTOType>>(new std::vector<DTOType>);
}

template <class DTOType> CSVData<DTOType>::~CSVData(){}

template <class DTOType>
void CSVData<DTOType>::addError(std::vector<std::string> f){
    errorRows->push_back(f);
}

template <class DTOType>
void CSVData<DTOType>::addDTO(DTOType dto){
    dtos->push_back(dto);
}

#endif // CSVDATA_H
