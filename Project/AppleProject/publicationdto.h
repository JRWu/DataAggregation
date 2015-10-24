#ifndef PUBLICATIONDTO
#define PUBLICATIONDTO

#include <string>
#include <vector>
#include <memory>

/* Here if we need it
enum PublicationStatus{
    PUBLISHED, INPRESS, SUBMITTED
};


enum PublicationType{
    BOOK_CHAPTERS, BOOKS, BOOKS_EDITED, CASE_REPORTS, CLINICAL_CARE_GUIDELINES,
    COMMENTARIES, CONFERENCE_PROCEEDINGS, EDITORIALS, INVITED_ARTICALS,
    JOURNAL_ARTICALS, LETTERS_TO_EDITOR, MAGAZINE_ENTRIES, MANUALS, MONOGRAPHS,
    MULTIMEDIA, NEWSLETTER_ARTICLES, NEWSPAPER_ARTICLES, PUBLISHED_ABSTRACT,
    SUPERVISED_STUDENT_PUBLICATION, WEBSITE_VIDEOS, WORKING_PAPERS
};


enum AuthorRole{
    PRINCIPAL_AUTHOR, CO_AUTHOR, COLLABORATOR, SENIOR_RESPONSIBAL_AUTHOR, EDITOR,
    REVIEWER
};

*/

class PublicationDTO{
public:
    //Mandatory Fields
    std::string name, domain, journalName, title, ISBN, status, type, role;
    unsigned int date, id;
    std::shared_ptr<std::vector<std::string>> authors;

    //Optional Fields
    std::string volume, issue, pageRange, DOI, website, publisher, personalRenumeration,
    traineeDetails, mostSignificantDetails;
    unsigned int pubmedID, authorNumber;
    int impactFactor;
    bool peerReviewed, international, presentation, mostSignificant, education;

    PublicationDTO();
    ~PublicationDTO();
};

#endif // PUBLICATIONDTO

