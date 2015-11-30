#ifndef CSVDTO_H
#define CSVDTO_H

#include <vector>
#include <string>

#include "CSV-Data/csvfield.h"
#include "CSV-Parser/csvparser.h"
#include "CSV-Data/csvfieldvalidatorfactory.h"
#include "CSV-Data/csvlinevalidatorfactory.h"
#include "CSV-Data/csvlinevalidator.h"
#include "DTO/bargraphadapter.h"
#include "DTO/treelistadapter.h"
#include "DTO/filteradapter.h"

#define NPUBHEADER 27
#define NPUBMANDATORY 9
#define NGRAHEADER 32
#define NGRAMANDATORY 13
#define NPREHEADER 20
#define NPREMANDATORY 6
#define NTEAHEADER 21
#define NTEAMANDATORY 10


enum CSVType: unsigned int{
    PUBLICATION, PRESENTATION, GRANTS, TEACHING
};

//forward declaration
class FilterAdapter;
class BarGraphAdapter;
class TreeListAdapter;

class CSVDTO
{
    //Header for this csv
    std::vector<std::string> header;
    //Validated lines in the CSV File
    std::vector<std::vector<CSVField>> validLines;
    //Error lines in the CSV File
    std::vector<std::vector<CSVField>> errorLines;

    //Adapters
    std::vector<FilterAdapter> filterDTOs;
    std::vector<BarGraphAdapter> barGraphDTOs;
    std::vector<TreeListAdapter> treeListDTOs;


    //Line validation strategy
    CSVLineValidator *lineValidator = 0;
    CSVType t; //Type of csv
    std::size_t nMan; //Number of mandatory headers
    std::string fileName; //file name

    void setReadProperties(std::vector<CSVField> *f, CSVType t);

public:
    //Creates a new data set of the chosen type from the given file
    CSVDTO(std::string *fname, CSVType ty);

    //Returns the list of filterDTOS for use in filtering
    std::vector<FilterAdapter> *getFilterDTOs();
    //Returns the list of bargraphDTOs for use in constructing bargraphs
    std::vector<BarGraphAdapter> *getBarGraphDTOs();
    //Returns the list of tree list dtos for use in making the tree list
    std::vector<TreeListAdapter> *getTreeListDTOs();

    //Returns the file name for this DTO
    std::string getFile();
};

#endif // CSVDTO_H
