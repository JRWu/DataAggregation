#include "validatepublication.h"

bool verifyPublicationDTO(shared_ptr<PublicationDTO> dto){
    //Verifiy mandatory strings are not empty
    if((dto->name == "")||(dto->domain == "")||(dto->journalName == "")
            ||(dto->title == "")||(dto->ISBN == "")||(dto->status == "")
            ||(dto->type == "")||(dto->role == ""))
        return false;

    //Make sure the date is in a "normal" range
    if((dto->date < 1800)||(dto->date > 2200)) return false;

    //Make sure the author list is not empty
    if(dto->authors->size() == 0) return false;

    //Make sure none of the author names are empty
    for(vector<string>::iterator it = dto->authors->begin() ;
        it != dto->authors->end(); ++it)
        if(*it == "") return false;

    return true;
}

