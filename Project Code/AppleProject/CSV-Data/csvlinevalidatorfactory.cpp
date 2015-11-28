#include "csvlinevalidatorfactory.h"

CSVLineValidator *getCSVLineValidator(CSVType t){
    if(t == PUBLICATION) return PublicationLineValidator::Instance();
    else if(t == GRANTS) return GrantLineValidator::Instance();
    else if(t == PRESENTATION) return PresentationLineValidator::Instance();
    else return TeachingLineValidator::Instance();
}

