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
 * @param _data is PUBLICATION data
 */
tree_list_vo::tree_list_vo(shared_ptr<CSVData<PublicationDTO> > _data)
{
    _data = _data;
    num_pub_types = 0;  // default 0 publication types
}

/**
 * @brief tree_list_vo::tree_list_vo overloaded constructor for tree_list_vo
 * @param _data is GRANT data
 */
tree_list_vo::tree_list_vo(shared_ptr<CSVData<GrantDTO> > _data)
{
    _data = _data;
    num_pub_types = 0;  // default 0 grant types
}

/**
 * @brief tree_list_vo::tree_list_vo overloaded constructor for tree_list_vo
 * @param _data is TEACHING data
 */
tree_list_vo::tree_list_vo(shared_ptr<CSVData<TeachingDTO> > _data)
{
    _data = _data;
    num_pub_types = 0;  // default 0 teaching types
}

/**
 * @brief tree_list_vo::tree_list_vo overloaded constructor for tree_list_vo
 * @param _data is PRESENTATION data
 */
tree_list_vo::tree_list_vo(shared_ptr<CSVData<PresentationDTO> > _data)
{
    _data = _data;
    num_pub_types = 0;  // default 0 presentation types
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






// Functions to populate VO with various CSV data pointers
// Functions to populate VO with various CSV data pointers
// Functions to populate VO with various CSV data pointers
// Functions to populate VO with various CSV data pointers





/**
 * @brief tree_list_vo::populate_for_publications populates the tree VO with publication data
 * @param _data shared pointer containing the csv parsed data
 * @param start is the initial date range filter
 * @param end is the final date range filter
 * @return 0 if it's executed successfully
 * COMPLETED BY JERRY DO NOT MODIFY
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



// Jaisen/Jennifer please update this to populate either Grants or Clinical Funding data
// Remember that Parent set is either Peer Reviewed or Industry Sponsored
// Remember that the Child Set is the Faculty name 1, Faculty name2 etc
// string_data_object num represents the total # of grants/fundings
// string_data_object value represents the monetary value of each grant/fund
// There should be 1 of these VO's created for Grants and 1 for Clinical Funding (2 in total)
int tree_list_vo::tree_list_vo::populate_for_grants(shared_ptr<CSVData<GrantDTO> > _data, int start, int end)
{


    /*
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
    */
    return 0;   // Exited with success.
}

// Eric/Emily please update this to populate either PME, UME, CME or Other data
// Remember that the child_set represents the Academic Year
// Remember that the child_set represents the Faculty 1, Faculty 2 etc...
// There should be 1 of these VO's created for each PME, UME, CME and Other data (4 in total I think)
int tree_list_vo::tree_list_vo::populate_for_teaching(shared_ptr<CSVData<TeachingDTO> > _data, int start, int end)
{
    /*
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
    */
    // Exit success
    return 0;
}

// To implement later once DO _data pointer is known
// Jerry will implement
int tree_list_vo::tree_list_vo::populate_for_presentations(shared_ptr<CSVData<PresentationDTO> > _data, int start, int end)
{
    // Invited
    // Lectures
    // Abstracts
    // Presented
    // Next Presentation
    // type
    // Other

    //Mandatory Fields
    //name, domain, type, role, title, date

    cout << "Testing for first user." << endl;
    cout <<"name"<<_data->dtos->at(0).name << endl;
    cout << "domain" << _data->dtos->at(0).domain << endl;
    cout << "type" << _data->dtos->at(0).type << endl;
    cout << "role" << _data->dtos->at(0).role << endl;
    cout << "title" << _data->dtos->at(0).title << endl;
    cout << "date" << _data->dtos->at(0).date << endl;



    // Adding 1st empty child set
    vector<string_data_object> t;
    child_set.push_back(t);

    int start_index = 0;
    int date = 0;
    while(start_index < _data->dtos->size())
    {
        date = _data->dtos->at(start_index).date;

        if ((start <= date) && (end >= date))
        {
            break;
        }
        start_index += 1;
    }

    string_data_object first_sd;
    first_sd.label = _data->dtos->at(start_index).name; // Add presenter's name
    first_sd.num = 0;
    first_sd.value = -1; // No value field for presentations

    child_set.at(0).push_back(first_sd);

    string_data_object first_pres;
    first_pres.label = _data->dtos->at(start_index).type;
    first_pres.num = 0;
    first_pres.value = -1;

    parent_set.push_back(first_pres);

    for (int i = start_index; i < _data->dtos->size(); i ++)
    {
        date = _data->dtos->at(i).date;
        if ((start <= date) && (end >=date))
        {
            string presenter = _data->dtos->at(i).name;
            string subject = _data->dtos->at(i).type;

            int pres_value = find_label_index(subject, parent_set);
            if (pres_value == -1)
            {
                num_pub_types +=1;

                string_data_object new_pres;
                new_pres.label = subject;
                new_pres.num = 1;
                new_pres.value = -1;

                vector <string_data_object> empty_child;
                child_set.push_back(empty_child);

                parent_set.push_back(new_pres);

                string_data_object new_presenter;
                new_presenter.label = presenter;
                new_presenter.num = 1;
                new_presenter.value = -1;

                int index = find_label_index(subject, parent_set);
                child_set.at(index).push_back(new_presenter);
            }

            if (pres_value != -1)
            {
                parent_set.at(pres_value).num += 1; // Add another presenter
                int presenter_value = find_label_index(presenter, child_set.at(pres_value));

                if (presenter_value == -1)      // Add new presenter
                {
                    string_data_object new_presenter;
                    new_presenter.label = presenter;
                    new_presenter.num = 1;
                    new_presenter.value = -1;
                    child_set.at(pres_value).push_back(new_presenter);
                }
                else
                {
                    vector<string_data_object> * tmp = &child_set.at(pres_value);
                    tmp->at(presenter_value).num +=1;
                }
            }
        }
    }
     return 0;
}






// PRIVATE FUNCTIONS FOR USAGE
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
