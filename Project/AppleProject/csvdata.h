#ifndef CSVDATA_H
#define CSVDATA_H

#include <vector>
#include <string>

using namespace std;

template <class DTOType> class CSVData
{
public:
    vector<DTOType> dtos;
    vector<vector<string>> errorRows;

    CSVData();
    ~CSVData();
};

template <class DTOType> CSVData<DTOType>::CSVData(){}

template <class DTOType> CSVData<DTOType>::~CSVData(){}

#endif // CSVDATA_H
