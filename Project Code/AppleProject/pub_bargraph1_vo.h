#ifndef PUB_BARGRAPH1_VO_H
#define PUB_BARGRAPH1_VO_H

#include <string>
#include <memory>
#include <vector>
#include <csvdata.h>
#include <algorithm>
#include "publicationdto.h"

class Pub_BarGraph1_VO
{
public:
    std::string name;
    std::vector<std::string> years;
    std::vector<std::string> pubTypes;
    std::vector<std::vector<int>> values;
    Pub_BarGraph1_VO(std::shared_ptr<CSVData<PublicationDTO>> data, int start, int end);
};

#endif // PUB_BARGRAPH1_VO_H
