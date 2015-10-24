#ifndef CSVDATAASSEMBLER_H
#define CSVDATAASSEMBLER_H

#include "fast-cpp-csv-parser-master/csv.h"
#include "csvdata.h"
#include "publicationdto.h"

class CSVDataAssembler
{
public:
    bool AssembleData(CSVData<PublicationDTO> *data, string fileName);
    //Add other constructors for other DTO types
};

#endif // CSVDATAASSEMBLER_H
