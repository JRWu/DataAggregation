#ifndef CSVDATA_H
#define CSVDATA_H

#include <vector>
#include <string>

template <class DTOType> class CSVData
{
public:
    std::vector<DTOType> dtos;
    std::vector<std::vector<std::string>> errorRows;

    CSVData();
    ~CSVData();
};

template <class DTOType> CSVData<DTOType>::CSVData(){}

template <class DTOType> CSVData<DTOType>::~CSVData(){}

#endif // CSVDATA_H
