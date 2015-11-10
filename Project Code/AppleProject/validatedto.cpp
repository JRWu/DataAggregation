#include "validatedto.h"

using namespace std;

//http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
void trimLeft(string *s){
    size_t startpos = s->find_first_not_of(" \t");
    if( string::npos != startpos )
    {
        *s = s->substr( startpos );
    }
}

void trimRight(string *s){
    size_t endpos = s->find_last_not_of(" \t");
    if( string::npos != endpos )
    {
        *s = s->substr( 0, endpos+1 );
    }
}

void trimString(string *s){
    trimRight(s);
    trimLeft(s);
}

bool validateString(string s){
    if(s.length() == 0) return false;
    if(s[0] != '*') return true;
    else{
        string whitespaces (" \t\f\v\n\r");
        size_t found = s.find_last_not_of(whitespaces);
        return(found != 0);
    }
}

//end borrowed functions

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
    return true;
}

bool validateDate(string *s){
    return makeDate(s);
}

bool validateAuthorName(string s){
    string alpha = u8"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
                   "ùûüÿàâæçéèêëïîôœÙÛÜŸÀÂÆÇÉÈÊËÏÎÔŒ";
    for(int j = 0; j < (int)s.length(); j++){
        if(alpha.find(s[j]) == string::npos){
            if((s[j] != '-')||(s[j] == ' ')){
                if(((j+1)==(int)s.length())||
                        (alpha.find(s[j+1]) == string::npos)){
                    return false;
                }
            }
        }
    }
    return true;
}

bool makeAuthors(string *str){
    //return true;
    string s = *str;
    if(s.length() == 0) return false;
    if(s.back() == '.') s = s.substr(0, s.length() - 1);

    vector<string> elm;
    stringstream ss(s);
    string item;

    //Split around ,
    while(getline(ss, item, ',')) elm.push_back(item);
    for(int i = 0; i < (int)elm.size(); i++){
        //Make sure no comma deliniated entry is whitespace
        trimString(&elm[i]);
        if(elm[i].length() == 0) return false;
        if(!validateAuthorName(elm[i])) return false;
    }

    *str = "";
    for(int i = 0; i < (int)elm.size(); i++){
        *str = *str + elm[i];
    }

    return true;
}

bool validateAuthors(string *s){
    return makeAuthors(s);
}

/* Checks the 9 mandatory fields for a publication DTO.
 * The check is made in reverse order for ease of unpacking
 * the encoded int to display which entries are invalid.
 */
int validatePublication(std::vector<string> *fields){
    int result = 0;

    if(!validateAuthors(&(*fields)[8])) result+=1;
    result <<= 1;

    //Check the 7 mandatory fields
    for(int i = 7; i > 0; i--){
        if(!validateString((*fields)[i])) result+=1;
        result <<= 1;
    }

    if(!validateDate(&(*fields)[0])) result+=1;
    return result;
}

/* Checks the 7 mandatory fields for a presentation DTO.
 * The check is made in reverse order for ease of unpacking
 * the encoded int to display which entries are invalid.
 */
int validatePresentation(std::vector<string> *fields){
    int result = 0;

    if(!validateAuthors(&(*fields)[8])) result+=1;
    result <<= 1;

    //Check the 9 mandatory fields
    for(int i = 7; i > 0; i--){
        if(!validateString((*fields)[i])) result+=1;
        result <<= 1;
    }

    if(!validateDate(&(*fields)[0])) result+=1;
    return result;
}

/* Checks the 13 mandatory fields for a grant DTO.
 * The check is made in reverse order for ease of unpacking
 * the encoded int to display which entries are invalid.
 * Jennifer/Jaisen, did you mean to call this validateGrant? I renamed it to silence errors
 */
int validateGrant(std::vector<string> *fields){
    int result = 0;
    
    if(!validateAuthors(&(*fields)[12])) result+=1;
    result <<= 1;
    
    //Check the 13 mandatory fields
    for(int i = 12; i > 0; i--){
        if(!validateString((*fields)[i])) result+=1;
        result <<= 1;
    }
    
    if(!validateDate(&(*fields)[0])) result+=1;
    return result;
}


int validateTeaching(std::vector<std::string> * fields)
{
    return 0; // DUMMY DATA MUST RETURN RESULT
}
