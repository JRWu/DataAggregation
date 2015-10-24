#include "validatedto.h"
#include <iostream>
using namespace std;

bool validateString(string s){
    if(s.length() == 0) return false;
    if(s[0] != '*') return true;
    else{
        string whitespaces (" \t\f\v\n\r");
        size_t found = s.find_last_not_of(whitespaces);
        return(found != 0);
    }
}

bool isLeapYear(int y){
    if((y%4) == 0){
       if((y%100) == 0){
           if((y%400) == 0){
               return true;
           }
           return false;
       }
       return true;
    }
    return false;
}

bool makeDate(string *s){
    cout << *s << endl;
    if(s->length() == 0) return false;

    vector<string> elm;
    stringstream ss(*s);
    string item;

    //Split around /
    while(getline(ss, item, '/')) elm.push_back(item);

    //More than three tokens
    if(elm.size() > 3) return false;

    //Check that only numerical data remains.
    vector<int> ielm(elm.size());
    for(int i = 0; i < (int)elm.size(); i++){
        for(int j = 0; j < (int)elm[i].length(); j++){
            if(!isdigit(elm[i][j])) return false;
        }
        ielm.push_back(atoi(elm[i].c_str()));
    }

    //Sort the array
    sort(ielm.begin(), ielm.end());

    //Check if the year is in the correct range.
    if((ielm.back() < 1900)||(ielm.back() > 2100)) return false;

    //Check that DD/MM/YYYY is valid
    if(ielm.size() == 3){
        int m[] = {31,isLeapYear(ielm.back())?29:28,31,30,31,30,31,31,30,31,30,31};
        if((ielm[1] > m[ielm[0]])&&(ielm[0] > m[ielm[1]])) return false;
    }
    //Check that MM/YYYY is valid
    if(ielm.size() == 2){
        if(ielm[0] > 12) return false;
    }

    *s = to_string(ielm.back());
    cout << *s << endl;
    return true;
}

bool validateDate(string *s){
    return makeDate(s);
}

/* Checks the 9 mandatory fields for a publication DTO.
 * The check is made in reverse order for ease of unpacking
 * the encoded int to display which entries are invalid.
 */
int validatePublication(std::vector<string> *fields){
    int result = 0;

    //Check the 9 mandatory fields
    for(int i = 8; i > 0; i--){
        if(!validateString((*fields)[i])) result+=1;
        result <<= 2;
    }
    if(!validateDate(&(*fields)[0])) result+=1;
    return result;
}
