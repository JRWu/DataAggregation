#include "pres_bargraph1_vo.h"


// Essentially a carbon-copy of Vince's pub_bargraph1_vo.cpp because the
// format of the presentation DTO's is identical to the Publication DTO's
Pres_BarGraph1_VO::Pres_BarGraph1_VO(std::shared_ptr<CSVData<PresentationDTO>> data, int start, int end)
{
    cout << start << " " << end << endl;
    presenter = data->dtos->at(0).name;  // Gets first name as a default. Later we will add a combo box to select a name and pass that as a parameter

    //Loop through all the dtos
    for(int i = 0; i < (int) data->dtos->size(); i++){
        PresentationDTO dto = data->dtos->at(i);
        //Check if this dto is for the presenter we are graphing
        if(dto.name == presenter){
            //Make sure the date is in the correct range
            if((start <= dto.date)&&(dto.date <= end)){
                vector<string>::iterator index;
                //Check to see if the type of presentations is already in the list of all types of presentations for this faculty member
                index = find(presTypes.begin(), presTypes.end(), dto.type);
                //If not add it to the list
                if(index == presTypes.end()) presTypes.push_back(dto.type);


                //Check to see if the current year is already in the list of all the years the presenter has been active
                index = find(years.begin(), years.end(), to_string(dto.date));
                //If not add it to the list.
                if(index == years.end()) years.push_back(to_string(dto.date));
            }
        }
    }

    //Sort both list so that years are in order and presentation types are consistant in their ordering from graph to graph
    sort(presTypes.begin(), presTypes.end());
    sort(years.begin(), years.end());

    //Initialize a 2d array of (types x years)
    for(int i = 0; i < (int)presTypes.size(); i++){
        vector<int> temp;
        for(int j = 0; j < (int)years.size(); j++){
            temp.push_back(0);
        }
        values.push_back(temp);
    }

    cout << "pass 2" << endl;

    //Loop though all the dtos again
    for(int i = 0; i < (int) data->dtos->size(); i++){
        PresentationDTO dto = data->dtos->at(i);
        //Check if this dto is for the faculity memeber we are graphing
        if(dto.name == presenter){
            //Make sure the date is in the correct range
            if((start <= dto.date)&&(dto.date <= end)){
                vector<string>::iterator index;
                //Get the index of the presentation in the presentation type array
                index = find(presTypes.begin(), presTypes.end(), dto.type);
                int i = distance(presTypes.begin(),index);
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
