#include "Utility/stringfunctions.h"

//String trimming
//From /http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring

//Trim the whitespace from left of sting
void trimLeft(std::string *s){
    std::size_t startpos = s->find_first_not_of(" \t\n");
    if( std::string::npos != startpos )
    {
        *s = s->substr( startpos );
    }
}

//Trim the whitepsace from right of string
void trimRight(std::string *s){
    std::size_t endpos = s->find_last_not_of(" \t\n");
    if( std::string::npos != endpos )
    {
        *s = s->substr( 0, endpos+1 );
    }
}

//Trim the whitespace from both left and right of string
void trimString(std::string *s){
    trimRight(s);
    trimLeft(s);
}

//End Borrowed functions
