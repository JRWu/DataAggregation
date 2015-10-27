#ifndef TREE_LIST_VO_H
#define TREE_LIST_VO_H

#include <iostream>
#include <vector>
#include "analyze_csv.h"
#include <QTreeWidget>

using namespace std;


// Holds the author and their respective publications*
struct author_number
{
    string author="";
    int num=0;
};



class tree_list_vo
{
    int num_pub_types;
    vector<string> publication_types;       // Contains publication titles
    vector< vector<author_number> > author_name_set;   // Contains author:number set
    vector<int> publication_type_sums;

public:
    tree_list_vo(); // Default constructor
    tree_list_vo(shared_ptr<CSVData<PublicationDTO>> _data); // For publications

    vector<string> get_publication_types(void);
    vector<vector<author_number>> get_author_name_set(void);
    vector<int> get_publication_type_sums(void);

    int populate_publication_set(shared_ptr<CSVData<PublicationDTO>> _data, int start, int end);
    void populate_pub_tree(QTreeWidget t);

private:
    int find_pub_type(string typ, vector<string> p_types); // Iterates vector<string> types for string typ
    int find_author(string name, vector<author_number> a_n_set);
};

#endif // TREE_LIST_VO_H
