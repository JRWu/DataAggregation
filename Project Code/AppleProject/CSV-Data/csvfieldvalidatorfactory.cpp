#include "CSV-Data/csvfieldvalidatorfactory.h"

CSVFieldValidator *getCSVValidator(ValidatorType t)
{
    switch(t){
        case STRINGVALIDATOR: return StringValidator::Instance();
        case DATEVALIDATOR: return DateValidator::Instance();
        case NAMELISTVALIDATOR: return NameListValidator::Instance();
        case MONEYVALIDATOR: return MoneyValidator::Instance();
    }

    return new CSVFieldValidator();
}
