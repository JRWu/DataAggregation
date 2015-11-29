#ifndef DTOFILTER_H
#define DTOFILTER_H

/* The filter object will be seeded with data taken from the UI and then
 * used to filter only those dtos which meet it's criteria: correct name,
 * correct type, correct date range.
 *
 * isValid should be called after construction to ensure that the filter is
 * valid: currently that start date <= end date
 */

#include <string>
#include <vector>

#include "DTO/filteradapter.h"

class FilterAdapter;

class DTOFilter
{
    std::string name, syear, eyear, type;
public:
    DTOFilter(std::string n, std::string sy, std::string ey, std::string t);
    bool filter(FilterAdapter *b);
    bool isValid();
};

#endif // DTOFILTER_H
