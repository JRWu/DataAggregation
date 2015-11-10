#include "teachingdto.h"

TeachingDTO::TeachingDTO() {
    //mandatory:
    name = domain = program = type = program = type = scope = "";

    startDate = endDate = 0;

    hoursSession = numberSession = 0;

    totalHours = 0;

    //optional:
    institution = faculty = department = division = location = facultyComments = students = lecture = development = stipend = comment = "";
}

TeachingDTO::~TeachingDTO() {
}
