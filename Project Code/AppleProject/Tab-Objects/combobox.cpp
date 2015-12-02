#include "combobox.h"

using namespace std;

ComboBox::ComboBox(QComboBox *cmb, size_t t, TabSubject *s):
    TabObserver(s), TabSubject()
{
    csvtype = t;
    valueGetter = getFilterValue(FILTERYEAR); //Add parameter later
    this->cmb = cmb;
}

void ComboBox::update(){
    vector<string> filterValues;

    //If the subject is not null get the state
    if(this->subject){
        filterValues = subject->getState();

        //If filterValues is empty then this should be empty
        if(filterValues.size() == 0){
            this->state = vector<string>();
            cmb->clear();
            return;
        }
    }

    //Otherwise there might be values to populate the box with
    //Find the list of values
    vector<string> values;
    getValues(&filterValues, &values);

    //If no values are found state, clear combobox
    if(values.size() == 0){
        this->state = vector<string>();
        cmb->clear();
        return;
    }

    //Otherwise make the new combo box (preserve selection if possible)
    populateComboBox(&values);
}

void ComboBox::getValues(vector<string> *fv, vector<string> *v){
    DTOFilter filter(fv);
    //Add parameter for type
    vector<FilterAdapter> *dtos =
            Data::Instance()->getDTO(csvtype)->getFilterDTOs();

    for(size_t i = 0; i < dtos->size(); i++){
        FilterAdapter dto = dtos->at(i);
        //Make sure the dto is inside our filter
        if(filter.filter(&dto)){
            //Add the value if it is not already in the list
            string value = this->valueGetter->getValue(&dto);
            vector<string>::iterator i;
            i = std::find(v->begin(), v->end(), value);
            if(i == v->end()) v->push_back(value);
        }
    }

    //Sort the values;
    std::sort(v->begin(), v->end());
    this->notify();
}

void ComboBox::populateComboBox(vector<string> *v){
    string selection =  cmb->currentText().toStdString();

    //set the new by the previous selectio if possible
    vector<string>::iterator i = std::find(v->begin(), v->end(), selection);
    size_t newIndex = (i == v->end())?0:(i - v->begin());

    //Load the list of new values
    QStringList values;
    for(size_t j = 0; j < v->size(); j++){
        values << QString::fromStdString(v->at(j));
    }

    //Add the new values and update the index
    cmb->clear();
    cmb->insertItems(0, values);
    cmb->setCurrentIndex(newIndex);
}

vector<string> ComboBox::getState(){
    vector<string> result;
    result.insert(result.begin(), state.begin(), state.end());
    result.push_back(cmb->currentText().toStdString());
    return result;
}
