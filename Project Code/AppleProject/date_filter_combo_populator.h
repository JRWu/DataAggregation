#ifndef DATEFILTERCOMBOPOPULATOR_H
#define DATEFILTERCOMBOPOPULATOR_H

#include <QStringList>
#include <memory>

#include "csvdata.h"
#include "grantdto.h"
#include "publicationdto.h"
#include "teachingdto.h"
#include "presentationdto.h"

QStringList PopulateDateCombos(std::shared_ptr<CSVData<GrantDTO>> data);
QStringList PopulateDateCombos(std::shared_ptr<CSVData<TeachingDTO>> data);
QStringList PopulateDateCombos(std::shared_ptr<CSVData<PresentationDTO>> data);
QStringList PopulateDateCombos(std::shared_ptr<CSVData<PublicationDTO>> data);

#endif // DATEFILTERCOMBOPOPULATOR_H
