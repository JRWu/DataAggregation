#ifndef CSVFIELDVALIDATORFACTORY
#define CSVFIELDVALIDATORFACTORY

#include "CSV-Data/csvfieldvalidator.h"

/* Takes in the type of validator you want and returns
 * the singleton class of that validation type.
 *
 */
CSVFieldValidator *getCSVValidator(ValidatorType t);

#endif // CSVFIELDVALIDATORFACTORY

