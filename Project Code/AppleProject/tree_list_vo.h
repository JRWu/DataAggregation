#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include "analyze_csv.h"
#include <QTreeWidget>

using namespace std;

// Holds information of subnode + information associated
struct string_data_object
{
    string label="";    // Represents, Author |Peer/Industry |Academic Year |Faculty Nam
    double num=0;   // Represents count
    double value=0; // Represents sum (if present)
};

class tree_list_vo
{
public:
    // Public Functions
    tree_list_vo(); // Constructor
    tree_list_vo(shared_ptr<CSVData<PublicationDTO> > _data); // Overloaded constructor

    vector<string_data_object> get_parent_set(void);
    vector<vector<string_data_object> > get_child_set(void);

    // These functions all populate the data slightly differently based on what is being passed
    int populate_for_publications(shared_ptr<CSVData<PublicationDTO>> _data, int start, int end);
    int populate_for_grants(shared_ptr<CSVData<PublicationDTO>> _data, int start, int end);
    int populate_for_teaching(shared_ptr<CSVData<PublicationDTO>> _data, int start, int end);
    int populate_for_presentations(shared_ptr<CSVData<PublicationDTO>> _data, int start, int end);

private:
    // Private Attributess
    int num_pub_types;
    vector<string_data_object> parent_set;    // Has label + sum per each child_set
    vector<vector<string_data_object> > child_set;

    //Private Functions
    int find_label_index(string label, vector<string_data_object> set);

};

#endif // TREE_H
