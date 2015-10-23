#include "publicationdto.h"

/* Here if we need it
string PUBLICATION_STATUS[] = {"Published", "In-Press/Accepted", "Submitted"};

string PUBLICATION_TYPE[] = {"Book Chapters", "Books", "Books Edited",
                             "Case Reports", "Clinical Care Guidlines",
                             "Commentaries", "Conference Proceedings", "Editorials",
                             "Invited Articals", "Journal Articals",
                             "Letters to Editor", "Magazine Enteries", "Manuals",
                             "Monographs", "Multimedia", "Newsletter Articles",
                             "Newspaper Articles", "Published Abstract",
                             "Supervised Student Publications", "Working Papers"};


string AUTHOR_ROLE[] = {"Principal Author", "Co-Author", "Collaborator",
                             "Senior Responsible Author", "Editor", "Reviewer"};

*/

int nextid = 0;

//Default Constructor
PublicationDTO::PublicationDTO()
{
    //Mandatory Fields
    name = domain = journalName = title = ISBN = status = type = role = "";
    date = 0;
    //authors = shared_ptr<vector<string>>( new vector<string> );

    //Optional Fields
    volume = issue = pageRange = DOI = website = publisher = personalRenumeration =
    traineeDetails = mostSignificantDetails = "";
    pubmedID = authorNumber = 0;
    impactFactor = 0;
    peerReviewed = international = presentation = mostSignificant = education = false;

    id = ++nextid;
}

PublicationDTO::~PublicationDTO()
{
    //authors.reset();
}
