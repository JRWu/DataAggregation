#ifndef CSVLINEVALIDATORFACTORY_H
#define CSVLINEVALIDATORFACTORY_H

//Factory patter for retrieving the different types of line validation strategies

#include "DTO/csvdto.h"
#include "CSV-Data/csvlinevalidator.h"

//Forward declaration
enum CSVType: unsigned int;

CSVLineValidator *getCSVLineValidator(CSVType t);

#endif // CSVLINEVALIDATORFACTORY_H
