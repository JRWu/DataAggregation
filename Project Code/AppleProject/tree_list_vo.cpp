#include "tree_list_vo.h"

/**
 * @brief tree_list_vo::tree_list_vo default constructor for tree_list_vo
 */
tree_list_vo::tree_list_vo()
{
    // default constructor
    num_pub_types = 0;
}


/**
 * @brief tree_list_vo::tree_list_vo overloaded constructor for tree_list_vo
 * @param _data is the data pointer to be implemented later
 */
tree_list_vo::tree_list_vo(shared_ptr<CSVData<PublicationDTO> > _data)
{
    _data = _data;
    num_pub_types = 0;  // default 0 publication types
}

/**
 * @brief tree_list_vo::tree_list_vo overloaded constructor for tree_list_vo
 * @param _data is the data pointer to be implemented later
 */
tree_list_vo::tree_list_vo(shared_ptr<CSVData<GrantDTO> > _data)
{
    _data = _data;
    num_grant_types = 0;  // default 0 publication types
}


/**
 * @brief tree_list_vo::get_parent_set returns the parent set of the tree list vo object
 * @return parent_set of the tree_list_vo object
 */
vector<string_data_object> tree_list_vo::get_parent_set()
{
    return parent_set;
}

/**
 * @brief tree_list_vo::get_child_set returns the child set of the tree list vo object
 * @return child_set of the tree_list_vo object
 */
vector<vector<string_data_object> > tree_list_vo::get_child_set()
{
    return child_set;
}

/**
 * @brief tree_list_vo::populate_for_publications populates the tree VO with publication data
 * @param _data shared pointer containing the csv parsed data
 * @param start is the initial date range filter
 * @param end is the final date range filter
 * @return 0 if it's executed successfully
 */
int tree_list_vo::populate_for_publications(shared_ptr<CSVData<PublicationDTO> > _data, int start, int end)
{
    // Create the first empty child set
    vector<string_data_object> t;
    child_set.push_back(t);

    int start_index = 0;
    int date = 0;
    while(start_index < _data->dtos->size())    // Iterates through data to find first valid range
    {
        date = _data->dtos->at(start_index).date;

        if ((start <= date) && (end >= date))
        {
            break;            // Found the index of dto where the first legal date range is found
        }
        start_index += 1;
    }

    string_data_object first_sd;
    first_sd.label = _data->dtos->at(start_index).name; // Add first Member Name
    first_sd.num = 0;                                                        // Default is 0 publications
    child_set.at(0).push_back(first_sd);                          // Add first publication author

    string_data_object first_pub;                                   // Add first publication type
    first_pub.label = _data->dtos->at(start_index).type;
    first_pub.num = 0;                                                    // 0 publications first
    first_pub.value = -1;

    parent_set.push_back(first_pub);                             // 1 Author and 1 Pub inserted

    // start_index now contains the first DTO we begin at.
    for (int i = start_index; i < _data->dtos->size(); i ++)
    {
        date = _data->dtos->at(i).date;            // Get date of starting index
        if ((start <= date) && (end >= date))   // Should pass b/c starting at 1st valid data index
        {
            string author = _data->dtos->at(i).name;    // Temp name
            string pubtype = _data->dtos->at(i).type;   // Temp publication type

            int pub_value = find_label_index(pubtype, parent_set);
            if (pub_value == -1)    // New publication type
            {
                num_pub_types += 1;                      // Increment total publication count

                string_data_object new_pub;
                new_pub.label = pubtype;                // Set label of the new publication type
                new_pub.num = 1;                            // 1st of its pubtype found
                new_pub.value = -1;

                vector<string_data_object> empty_child;
                child_set.push_back(empty_child);

                parent_set.push_back(new_pub);

                string_data_object new_auth;        // Add 1st author of new publicaiton type
                new_auth.label = author;
                new_auth.num = 1;
                new_auth.value = -1;

                int index = find_label_index(pubtype, parent_set);
                child_set.at(index).push_back(new_auth);    // Add author to specific publication
            }

            if (pub_value != -1)    // Publication type exists, look for potential authors
            {
                parent_set.at(pub_value).num += 1;      // Add another entry for publications
                int auth_value = find_label_index(author, child_set.at(pub_value));

                if (auth_value == -1)   // New author is encountered
                {
                    string_data_object new_auth;    // Create new author
                    new_auth.label = author;
                    new_auth.num = 1;
                    new_auth.value = -1;
                    child_set.at(pub_value).push_back(new_auth);
                }
                else        // Author is already found, increment their count for publications
                {
                    vector<string_data_object> *tmp = &child_set.at(pub_value);
                    tmp->at(auth_value).num += 1;
                }
            }
        }
    }

    return 0;   // Exited with success.
}


// tree_list_vo::populate_for_grants populates the tree VO with grant data
// returns 0 if successful
int tree_list_vo::tree_list_vo::populate_for_grants(shared_ptr<CSVData<GrantDTO> > _data, int start, int end)
{
    // Create the first empty child set
    vector<string_data_object> t;
    child_set.push_back(t);
    
    int start_index = 0;
    int date = 0;
    while(start_index < _data->dtos->size())                    // Iterates through data to find first valid range
    {
        date = _data->dtos->at(start_index).date;
        
        if ((start <= date) && (end >= date))
        {
            break;                                              // Found the index of dto where the first legal date range is found
        }
        start_index += 1;
    }
    
    string_data_object first_sd;
    first_sd.label = _data->dtos->at(start_index).name;         // Add first Member Name
    first_sd.num = 0;                                           // Default is 0 grants
    child_set.at(0).push_back(first_sd);                        // Add first grant's principal investigator
    
    string_data_object first_grant;                               // Add first funding type
    first_grant.label = _data->dtos->at(start_index).type;
    first_grant.num = 0;                                          // 0 grants first
    first_grant.value = -1;
    
    parent_set.push_back(first_grant);                            // 1 investigator and 1 grant inserted
    
    // start_index now contains the first DTO we begin at.
    for (int i = start_index; i < _data->dtos->size(); i ++)
    {
        date = _data->dtos->at(i).date;                         // Get date of starting index
        if ((start <= date) && (end >= date))                   // Should pass b/c starting at 1st valid data index
        {
            string author = _data->dtos->at(i).name;              // Temp name
            string granttype = _data->dtos->at(i).type;           // Temp grant type
            
            int grant_value = find_label_index(granttype, parent_set);
            if (grant_value == -1)                                // New grant type
            {
                num_grant_types += 1;                             // Increment total grant count
                
                string_data_object new_grant;
                new_grant.label = granttype;                      // Set label of the new publication type
                new_grant.num = 1;                                // 1st of its pubtype found
                new_grant.value = -1;
                
                vector<string_data_object> empty_child;
                child_set.push_back(empty_child);
                
                parent_set.push_back(new_grant);
                
                string_data_object new_auth;                    // Add 1st author of new publicaiton type
                new_auth.label = author;
                new_auth.num = 1;
                new_auth.value = -1;
                
                int index = find_label_index(granttype, parent_set);
                child_set.at(index).push_back(new_auth);        // Add author to specific publication
            }
            
            if (grant_value != -1)                                // If grant type exists, look for potential investigators
            {
                parent_set.at(grant_value).num += 1;              // Add another entry for grants
                int auth_value = find_label_index(author, child_set.at(grant_value));
                
                if (inv_value == -1)                           // New investigator is encountered
                {
                    string_data_object new_inv;                // Create new investigator
                    new_inv.label = investigator;
                    new_inv.num = 1;
                    new_inv.value = -1;
                    child_set.at(grant_value).push_back(new_inv);
                }
                else                                            // investigator is already found, increment their count for grants
                {
                    vector<string_data_object> *tmp = &child_set.at(grant_value);
                    tmp->at(inv_value).num += 1;
                }
            }
        }
    }
    
    return 0;   // Exited with success.
}

// To implement later once DO _data pointer is known
int tree_list_vo::tree_list_vo::populate_for_teaching(shared_ptr<CSVData<PublicationDTO> > _data, int start, int end)
{
    return 0;
}

// To implement later once DO _data pointer is known
int tree_list_vo::tree_list_vo::populate_for_presentations(shared_ptr<CSVData<PublicationDTO> > _data, int start, int end)
{
    return 0;
}


/**
 * @brief tree_list_vo::find_label_index will return the index of a label stored in
 * the list specified by param set
 * @param label is the label being searched for
 * @param set is the vector that stores string:data objects
 * @return the index at which label is stored if found, -1 otherwise
 */
int tree_list_vo::find_label_index(string label, vector<string_data_object> set)
{
    for (int i = 0; i < set.size(); i ++)
    {
        if( (set.at(i).label).compare(label) == 0)
        {
            return i;
        }
    }
    return -1;
}
