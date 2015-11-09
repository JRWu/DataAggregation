#ifndef CSVDATAASSEMBLER_H
#define CSVDATAASSEMBLER_H

#include "fast-cpp-csv-parser-master/csv.h"
#include "csvdata.h"
#include "publicationdto.h"
#include "grantdto.h"
#include "presentationdto.h"
#include "validatedto.h"
#include "dtoassembler.h"

bool AssembleData(std::shared_ptr<CSVData<PublicationDTO>> data, string fileName);
    //Add other overloads for other DTO types (unless someone wants to edit csv.h)
bool AssembleData(std::shared_ptr<CSVData<GrantDTO>> data, string fileName);
bool AssembleData(std::shared_ptr<CSVData<PresentationDTO>> data, string fileName);


#endif // CSVDATAASSEMBLER_H
