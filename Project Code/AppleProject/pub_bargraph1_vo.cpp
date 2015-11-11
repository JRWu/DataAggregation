#include "pub_bargraph1_vo.h"

using namespace std;

/*
 * Note I use a two pass system hear, you can do it in one pass if you wish, though you will
 * likely have to deal with sorting both lists will keeping the 2d array in a consistant ordering
 */
Pub_BarGraph1_VO::Pub_BarGraph1_VO(std::shared_ptr<CSVData<PublicationDTO> > data, int start, int end)
{
    cout << start << " " << end << endl;
    name = data->dtos->at(0).name;  // Gets first name as a default. Later we will add a combo box to select a neame and pass that as a parameter

    //Loop through all the dtos
    for(int i = 0; i < (int) data->dtos->size(); i++){
        PublicationDTO dto = data->dtos->at(i);
        //Check if this dto is for the faculity memeber we are graphing
        if(dto.name == name){
            //Make sure the date is in the correct range
            if((start <= dto.date)&&(dto.date <= end)){
                vector<string>::iterator index;
                //Check to see if the type of publication is already in the list of all types of publications for this faculty memebr
                index = find(pubTypes.begin(), pubTypes.end(), dto.type);
                //If not add it to the list
                if(index == pubTypes.end()) pubTypes.push_back(dto.type);


                //Check to see if the current year is already in the list of all the years the fauculty member has been active
                index = find(years.begin(), years.end(), to_string(dto.date));
                //If not add it to the list.
                if(index == years.end()) years.push_back(to_string(dto.date));
            }
        }
    }

    //Sort both list so that years are in order and publication types are consistant in their ordering from graph to graph
    sort(pubTypes.begin(), pubTypes.end());
    sort(years.begin(), years.end());

    //Initialize a 2d array of (types x years)
    for(int i = 0; i < (int)pubTypes.size(); i++){
        vector<int> temp;
        for(int j = 0; j < (int)years.size(); j++){
            temp.push_back(0);
        }
        values.push_back(temp);
    }

    cout << "pass 2" << endl;

    //Loop though all the dtos again
    for(int i = 0; i < (int) data->dtos->size(); i++){
        PublicationDTO dto = data->dtos->at(i);
        //Check if this dto is for the faculity memeber we are graphing
        if(dto.name == name){
            //Make sure the date is in the correct range
            if((start <= dto.date)&&(dto.date <= end)){
                vector<string>::iterator index;
                //Get the index of the publication in the publication type array
                index = find(pubTypes.begin(), pubTypes.end(), dto.type);
                int i = distance(pubTypes.begin(),index);
                //Get the index of the year in the year array
                index = find(years.begin(), years.end(), to_string(dto.date));
                int j = distance(years.begin(),index);
                //increment the value at (i,j)
                values.at(i).at(j) += 1;
            }
        }
    }
    cout << "pass 3" << endl;
}

