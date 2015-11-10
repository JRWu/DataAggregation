#ifndef TEACHINGDTO_H
#define TEACHINGDTO_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class TeachingDTO
{
public:
    //mandatory:
    string name, domain, program, type, scope;

    float hoursSession, numberSession, totalHours;

    unsigned int startDate, endDate;

    //optional:
    string institution, faculty, department, division, location, facultyComments, students, lecture, development, stipend, comment;

    TeachingDTO();
    ~TeachingDTO();
};

#endif // TEACHINGDTO_H
