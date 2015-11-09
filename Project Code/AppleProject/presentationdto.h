#ifndef PRESENTATIONDTO_H
#define PRESENTATIONDTO_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class PresentationDTO
{
public:

    //Mandatory Fields
    string name, domain, type, role, title;
    unsigned int date;
    //shared_ptr<vector<string>> authors;

    //Optional Fields
    string activityType, geoScope, host, country, province, city,
    attendeeNum, hours, teachScore, presentation, remarks, citation, personalRenumeration;//authorship, citation;
    //int attendeeNum, hours;
    shared_ptr<vector<string>> authorship;

    //These might not be numbers or bool??
    //string pubmedID, authorNumber, impactFactor,
    //peerReviewed, international, presentation, mostSignificant, education;

    /*unsigned int pubmedID, authorNumber;
    int impactFactor;
    bool presentation;*/

    PresentationDTO();
    ~PresentationDTO();
};

#endif // PRESENTATIONDTO_H
