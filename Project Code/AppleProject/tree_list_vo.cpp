#include "tree_list_vo.h"

tree_list_vo::tree_list_vo()
{
}

// Constructor for setting the pointer of the data tree
tree_list_vo::tree_list_vo(shared_ptr<CSVData<PublicationDTO> > _data)
{
    _data = _data;
    num_pub_types = 0;
}

int tree_list_vo::populate_publication_set(shared_ptr<CSVData<PublicationDTO> > _data, int start, int end)
{
    // Consider this as a new object
    // Assume 2 int values passed
    int range_begin = start;
    int range_ends = end;

    // Pass vector with the date range, check somewhere before we add
    vector<author_number> t;
    author_name_set.push_back(t);       // add empty vector
    publication_type_sums.push_back(0); // add 0 counts for first

    // Loop through and find first index of valid date
    int x = 0;
    int date = 0;
    while (x < _data->dtos->size())
    {
        date = _data->dtos->at(x).date;
        cout << date;

        if ((range_begin <= date) && (range_ends >= date))
        {
            // Found first index that's vaild
            cout << " yes" << endl;
            break;  // Value is saved in "x"
        }
        cout << " ";

        x += 1;
    }
    // X is the first range

    // Need to loop till the first valid before adding
    author_number new_auth;
    new_auth.author = _data->dtos->at(x).name;  // add first author
    new_auth.num = 1;   // No publications of this type yet
    author_name_set.at(0).push_back(new_auth);
    publication_types.push_back(_data->dtos->at(x).type);   // Add 1st publication type


    for (int i = x; i < _data->dtos->size(); i ++)  // Iterate through DTO's    (237)
    {
        date = _data->dtos->at(i).date; // check for the date
        if ((range_begin <= date) && (range_ends >= date))  // check for date
        {


            // ADd iff statement to filter for certain dates***
            string author = _data->dtos->at(i).name;    // Temp name
            string pubtype = _data->dtos->at(i).type;   // Temp publication type

            int t_pub = find_pub_type(pubtype,publication_types);
            if (t_pub == -1)    // New publication type         // 12 of these
            {
                num_pub_types ++;
                publication_types.push_back(pubtype); // Add publication type
                vector<author_number> t;
                author_name_set.push_back(t);    // add empty vector
                publication_type_sums.push_back(1);

                author_number new_auth;                         // Add first author of new pub type
                new_auth.author = author;
                new_auth.num = 1;   // No publications of this type yet

                int index = find_pub_type(pubtype, publication_types);

                author_name_set.at(index).push_back(new_auth);  // Bug here need to have index
            }
            if(t_pub != -1)                // Publication type exists, look for authors
            {
                publication_type_sums.at(t_pub) ++; // Increment total publications
                int t_auth =find_author(author,author_name_set.at(t_pub));
                if(t_auth == -1 )   // New Author
                {
                    author_number tmp_auth;
                    tmp_auth.author = author;
                    tmp_auth.num = 1;
                    author_name_set.at(t_pub).push_back(tmp_auth);

                }
                else
                {
                    vector<author_number> *tmp = &author_name_set.at(t_pub);
                    tmp->at(t_auth).num += 1;
                }
            }

        }   // End of if statement to check for years

    }

    return 0;
}



vector<string> tree_list_vo::get_publication_types(void)
{
    return publication_types;
}

vector<vector<author_number>> tree_list_vo::get_author_name_set(void)
{
    return author_name_set;
}

vector<int>  tree_list_vo::get_publication_type_sums(void)
{
    return publication_type_sums;
}


// Gets index of vector type
// returns index of vector type
// returns -1 otherwise
int tree_list_vo::find_pub_type(string typ, vector<string> p_types)
{
    for (int i = 0; i < p_types.size(); i ++)
    {
        if ( p_types.at(i).compare(typ) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Gets index of author
int tree_list_vo::find_author(string name, vector<author_number> a_n_set)
{
    for (int i = 0; i < a_n_set.size(); i++)
    {
        if ( (a_n_set.at(i).author).compare(name) == 0  )
        {
            return i;
        }
    }
    return -1;
}
