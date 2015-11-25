#ifndef GRAPHCOMBOBOXPOPULATOR_H
#define GRAPHCOMBOBOXPOPULATOR_H

#include <QStringList>
#include <vector>
#include <string>
#include "csvdata.h"

// combo box population functions

// publication tab
/**
 * @brief populateGraphComboName - populates the name combo box for the publication tab
 * @param data - dto loaded from csv
 * @return list of names
 */
QStringList populateGraphComboName(std::shared_ptr<CSVData<PublicationDTO>> tdata);
/**
 * @brief populateGraphComboType - populates the type combo box for the publication tab
 * @param data - dto loaded from the csv
 * @return - list of types
 */
QStringList populateGraphComboType(std::shared_ptr<CSVData<PublicationDTO>> tdata);

// presentation tab
QStringList populateGraphComboName(std::shared_ptr<CSVData<PresentationDTO>> tdata);
QStringList populateGraphComboType(std::shared_ptr<CSVData<PresentationDTO>> tdata);
// grants tab
QStringList populateGraphComboName(std::shared_ptr<CSVData<GrantDTO>> tdata);
QStringList populateGraphComboFunding(std::shared_ptr<CSVData<GrantDTO>> tdata);
// teaching tab
QStringList populateGraphComboName(std::shared_ptr<CSVData<TeachingDTO>> data);
QStringList populateGraphComboProgram(std::shared_ptr<CSVData<TeachingDTO>> tdata);


#endif // GRAPHCOMBOBOXPOPULATOR_H
