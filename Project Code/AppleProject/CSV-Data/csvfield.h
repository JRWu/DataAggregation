#ifndef CSVFIELD_H
#define CSVFIELD_H

/* Holds the string field of a row in the CSV. Has a defined validator
 * that validates the data depending on what type of data we
 * expect to be in the field
 */

#include <string>
#include <memory>

#include "CSV-Data/csvfieldvalidator.h"
#include "Utility/stringfunctions.h"

class CSVField
{
    std::string value; //The values of the field (possibly with an '*' removed)
    CSVFieldValidator *validator = 0; //The validation strategy for this field
    bool asterisk = false; //True if the field has a leading asterisk, false otherwise

public:
    CSVField(CSVFieldValidator *v){
        validator = v;
    }

    CSVField(CSVFieldValidator *v, std::string s){
        validator = v;
        this->setField(s);
    }

    //Returns true if the field is valid, false otherwise
    //Also reformats the string if valid
    bool validate(){
        return validator->validate( (&value) );
    }

    //Returns the field value (modified by asterisk)
    std::string getField(){
        std::string result = asterisk?"* ":"";
        return result + value;
    }

    //Sets the field of the object. Behavior depends on the possibilty
    //of a leading '*'
    void setField(std::string s){
        if(s[0] == '*'){
            asterisk = true;
            value = s.substr(1,s.length());
            trimLeft(&value);
        }
        else{
            asterisk = false;
            value = s;
        }

    }

    //Returns the value of the field (ie with no asterisk)
    std::string getValue(){
        return value;
    }
};

#endif // CSVFIELD_H
