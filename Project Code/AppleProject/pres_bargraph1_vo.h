#ifndef PRES_BARGRAPH1_VO_H
#define PRES_BARGRAPH1_VO_H

#include <string>
#include <memory>
#include <vector>
#include <csvdata.h>
#include <algorithm>
#include "presentationdto.h"

class Pres_BarGraph1_VO
{

public:
    std::string presenter;
    std::vector<std::string> years;
    std::vector<std::string> presTypes;
    std::vector<std::vector<int>> values;
    Pres_BarGraph1_VO(std::shared_ptr<CSVData<PresentationDTO>> data, int start, int end);
};

#endif // PRES_BARGRAPH_1_VO_H
