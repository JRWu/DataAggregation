#ifndef GRANT_BARGRAPH1_VO
#define GRANT_BARGRAPH1_VO
// Dummy class for Jennifer/Jaisen to populate with data
// You guys need to create the grant_bargraph1_vo.cpp in order to match this file
//
class Grant_BarGraph1_VO
{
public:
    Grant_BarGraph1_VO();
    Grant_BarGraph1_VO(std::shared_ptr<CSVData<GrantDTO> >, int, int);

    ~Grant_BarGraph1_VO();
};

#endif // GRANT_BARGRAPH1_VO

