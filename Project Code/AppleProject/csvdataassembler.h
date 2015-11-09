#ifndef CSVDATAASSEMBLER_H
#define CSVDATAASSEMBLER_H

#include "fast-cpp-csv-parser-master/csv.h"
#include "csvdata.h"
#include "publicationdto.h"
#include "validatedto.h"
#include "dtoassembler.h"

bool AssembleData(std::shared_ptr<CSVData<PublicationDTO>> data, string fileName);
    //Add other overloads for other DTO types (unless someone wants to edit csv.h)



#endif // CSVDATAASSEMBLER_H
