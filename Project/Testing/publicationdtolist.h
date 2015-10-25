#ifndef PUBLICATIONDTOLIST_H
#define PUBLICATIONDTOLIST_H

#include <memory>
#include <publicationdto.h>

class publicationDTOList
{
public:
    shared_ptr< vector<PublicationDTO> > valid, error;
    publicationDTOList();
    ~publicationDTOList();
};

#endif // PUBLICATIONDTOLIST_H
