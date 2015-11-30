#ifndef DATA_H
#define DATA_H

/* Singleton class that will hold up to 4 sets of csv data, for use in
 * the program
 */

#include <vector>
#include <string>
#include <memory>

#include "DTO/csvdto.h" //CSVType

enum CSVType: unsigned int;

class Data
{
public:
    static Data *Instance();

    std::shared_ptr<CSVDTO> getDTO(std::size_t t);

    //Attempts to load a new csv of type t from the given file
    //Will throw errors that need to be caught and displayed to the user
    //File not found, missing columns, csv format error, TODO duplicate columns
    bool loadDTO(std::string fname, std::size_t t);

protected:
    Data();
private:
    static Data* _instance;
    std::vector<std::shared_ptr<CSVDTO>> csv;
};

#endif // DATA_H
