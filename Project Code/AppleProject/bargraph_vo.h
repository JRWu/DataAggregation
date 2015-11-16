#ifndef BARGRAPH_H
#define BARGRAPH_H

#include <string>
#include <memory>
#include <vector>
#include "csvdata.h"

template <class DTOType> class BarGraph_VO
{
public:
    std::string name;
    std::vector<std::string> field1;
    std::vector<std::string> field2;
    std::vector<std::vector<double>> values;
    BarGraph_VO();
    BarGraph_VO(std::shared_ptr<CSVData<DTOType> > data, string name, string start = "0", string end = "3000", int type = 1);
};

template <class DTOType> BarGraph_VO<DTOType>::BarGraph_VO(std::shared_ptr<CSVData<DTOType>> data,
                                                           string fname, string start, string end, int type){

    name = fname;

    //Loop through all the dtos
    int n = (int) data->dtos->size();
    for(int i = 0; i < n; i++){
        DTOType dto = data->dtos->at(i);
        //Check if this dto is for the faculity memeber we are graphing
        if(dto.getName() == name){
            //Make sure the date is in the correct range
            string date = dto.getBarField1(type);
            if((start <= date)&&(date <= end)){
                string f2 = dto.getBarField2(type);
                vector<string>::iterator index;
                //Check to see if the field is already in the list of all fields for this faculty memebr
                index = find(field2.begin(), field2.end(), f2);
                //If not add it to the list
                if(index == field2.end()) field2.push_back(f2);


                //Check to see if the current year is already in the list of all the years the fauculty member has been active
                index = find(field1.begin(), field1.end(), date);
                //If not add it to the list.
                if(index == field1.end()) field1.push_back(date);
            }
        }
    }

    //Sort both list so that years are in order and publication types are consistant in their ordering from graph to graph
    sort(field1.begin(), field1.end());
    sort(field2.begin(), field2.end());

    //Initialize a 2d array of (types x years)
    for(int i = 0; i < (int)field2.size(); i++){
        vector<double> temp;
        for(int j = 0; j < (int)field1.size(); j++){
            temp.push_back(0.0);
        }
        values.push_back(temp);
    }

    //Loop though all the dtos again
    for(int i = 0; i < n; i++){
        DTOType dto = data->dtos->at(i);
        //Check if this dto is for the faculity memeber we are graphing
        if(dto.getName() == name){
            string date = dto.getBarField1(type);
            //Make sure the date is in the correct range
            if((start <= date)&&(date <= end)){
                string f2 = dto.getBarField2(type);
                vector<string>::iterator index;
                //Get the index of the publication in the publication type array
                index = find(field2.begin(), field2.end(), f2);
                int i = distance(field2.begin(),index);
                //Get the index of the year in the year array
                index = find(field1.begin(), field1.end(), date);
                int j = distance(field1.begin(),index);
                //increment the value at (i,j)
                values.at(i).at(j) += dto.getBarValue(type);
            }
        }
    }
}

template <class DTOType> BarGraph_VO<DTOType>::BarGraph_VO(){}

#endif // BARGRAPH_H
