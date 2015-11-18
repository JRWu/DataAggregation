#ifndef GRAPHCOMBOBOXPOPULATOR_H
#define GRAPHCOMBOBOXPOPULATOR_H

#include <QStringList>
#include <vector>
#include <string>
#include "csvdata.h"

// combo box population functions

// publication tab
QStringList PopulateGraphComboName(std::shared_ptr<CSVData<PublicationDTO>> tdata);
QStringList PopulateGraphComboType(std::shared_ptr<CSVData<PublicationDTO>> tdata);
// presentation tab
QStringList PopulateGraphComboName(std::shared_ptr<CSVData<PresentationDTO>> tdata);
QStringList PopulateGraphComboType(std::shared_ptr<CSVData<PresentationDTO>> tdata);
// grants tab
QStringList PopulateGraphComboName(std::shared_ptr<CSVData<GrantDTO>> tdata);
QStringList PopulateGraphComboFunding(std::shared_ptr<CSVData<GrantDTO>> tdata);
// teaching tab
QStringList PopulateGraphComboProgram(std::shared_ptr<CSVData<TeachingDTO>> tdata);


#endif // GRAPHCOMBOBOXPOPULATOR_H
