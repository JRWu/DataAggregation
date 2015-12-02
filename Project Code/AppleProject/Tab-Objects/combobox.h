#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QComboBox>
#include <vector>
#include <string>
#include <algorithm>

#include "Tab-Objects/tabobserver.h"
#include "Tab-Objects/tabsubject.h"
#include "Tab-Objects/dtofilter.h"
#include "Tab-Objects/filtervalue.h"
#include "DTO/filteradapter.h"
#include "DTO/data.h"

enum FilterValueType: unsigned int;

class ComboBox: public TabObserver, public TabSubject
{
    QComboBox *cmb;
    FilterValue *valueGetter;
    std::size_t csvtype;
public:
    ComboBox(QComboBox *cmb, std::size_t t, TabSubject *s = 0);
    void update();
    std::vector<std::string> getState();
private:
    //Returns the list of filtered values from the csv based on the filter values
    void getValues(std::vector<std::string> *fv, std::vector<std::string> *v);
    //Populates the new combo box with the list of values (tries to preseve selection)
    void populateComboBox(std::vector<std::string> *v);
};

#endif // YEARCOMBOBOX_H
