#include "pub_bargraph1_vo.h"

using namespace std;

Pub_BarGraph1_VO::Pub_BarGraph1_VO(std::shared_ptr<CSVData<PublicationDTO> > data)
{
    name = data->dtos->at(0).name;
    cout << name << endl;
    for(int i = 0; i < (int) data->dtos->size(); i++){
        PublicationDTO dto = data->dtos->at(i);
        if(dto.name == name){
            vector<string>::iterator index;
            index = find(pubTypes.begin(), pubTypes.end(), dto.type);
            if(index == pubTypes.end()) pubTypes.push_back(dto.type);
            index = find(years.begin(), years.end(), to_string(dto.date));
            if(index == years.end()) years.push_back(to_string(dto.date));
        }
    }

    sort(pubTypes.begin(), pubTypes.end());
    sort(years.begin(), years.end());

    for(int i = 0; i < (int)pubTypes.size(); i++){
        vector<int> temp;
        for(int j = 0; j < (int)years.size(); j++){
            temp.push_back(0);
        }
        values.push_back(temp);
        cout <<  values.size() << endl;
    }
    cout << "pass 2" << endl;
    for(int i = 0; i < (int) data->dtos->size(); i++){
        PublicationDTO dto = data->dtos->at(i);
        if(dto.name == name){
            vector<string>::iterator index;
            index = find(pubTypes.begin(), pubTypes.end(), dto.type);
            int i = distance(pubTypes.begin(),index);
            index = find(years.begin(), years.end(), to_string(dto.date));
            int j = distance(years.begin(),index);
            cout << i << " " << j << endl;
            values.at(i).at(j) += 1;
        }
    }
    cout << "pass 3" << endl;
}

