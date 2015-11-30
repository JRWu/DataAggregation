#include "csvdto.h"

using namespace std;

CSVDTO::CSVDTO(std::string *fname, CSVType ty)
{
    t = ty;

    //Reading line vector with validators set by the type
    std::vector<CSVField> f;

    //SAve the file name for use in saving the validated csv
    fileName = (*fname);

    //Set the properties of the parser based on the type of csv
    setReadProperties(&f, t);

    //Makes a new csv parser parsing file fname, using the given header
    //and number of mandatory fields
    CSVParser parser = CSVParser(fileName, &header, nMan);

    //Keeps track of the line of the csv we are on
    int nLines = 2;

    //Until there are no more lines to parse.
    while(parser.hasNext()){
        //Read the new line of the csv
        parser.readLine(&f);

        vector<CSVField> line;
        //Add the line of the CSV to the dto
        line.push_back(CSVField(getCSVValidator(STRINGVALIDATOR), "Line " + to_string(++nLines)));

        //Validate the fields individually while adding the read data to the dto
        bool valid = true;
        for(size_t j = 0; (j < f.size()); j++ ){
            if(j < nMan) valid &= f.at(j).validate();
            line.push_back(f.at(j));
        }

        //Validate the line as a whole (ie start year <= end year) etc
        if(valid) valid &= lineValidator->validate(&line);

        //Add dto to correct list based on validity
        if(valid) validLines.push_back(line);
        else errorLines.push_back(line);
    }
}

std::vector<FilterAdapter> *CSVDTO::getFilterDTOs(){
    if(filterDTOs.size() < validLines.size()){
        for(size_t i = 0; i < validLines.size(); i++){
            vector<CSVField> *line = &(validLines.at(i));
            filterDTOs.push_back(FilterAdapter(line, t));
        }
    }

    return &filterDTOs;
}

std::vector<BarGraphAdapter> *CSVDTO::getBarGraphDTOs(){
    if(barGraphDTOs.size() < validLines.size()){
        for(size_t i = 0; i < validLines.size(); i++){
            vector<CSVField> *line = &(validLines.at(i));
            barGraphDTOs.push_back(BarGraphAdapter(line, t));
        }
    }

    return &barGraphDTOs;
}

std::vector<TreeListAdapter> *CSVDTO::getTreeListDTOs(){
    if(treeListDTOs.size() < validLines.size()){
        for(size_t i = 0; i < validLines.size(); i++){
            vector<CSVField> *line = &(validLines.at(i));
            treeListDTOs.push_back(TreeListAdapter(line, t));
        }
    }

    return &treeListDTOs;
}

/*Sets up the properties of the csvdto and the csv reader based on
 *the given csv type. The number of mandatory fields, the name of
 * the fields, and the validation strategy for each field need to be
 * set.
 */
void CSVDTO::setReadProperties(std::vector<CSVField> *f, CSVType t){
    lineValidator = getCSVLineValidator(t);
    if(t == PUBLICATION){
        nMan = NPUBMANDATORY;
        string head[] = {"Status Date","Member Name","Primary Domain",
            "Publication Status","Type","Role",
            "Journal Name | Published In | Book Title | etc.","Title","Author(s)",

            "Pubmed Article ID","Peer Reviewed?","Author #","Volume","Issue",
            "Page Range","DOI","Website","Journal Impact Factor","International",
            "Publisher","Is Presentation?","Personal Remuneration",
            "Trainee Details","Is Most Significant Publication?",
            "Most Significant Contribution Details","Education Publication",
            "ISBNISSN"
            };

        header = std::vector<std::string>(head, head + NPUBHEADER);

        f->push_back(CSVField(getCSVValidator(DATEVALIDATOR)));
        for(size_t i = 0; i < 7; i++){
            f->push_back(CSVField(getCSVValidator(STRINGVALIDATOR)));
        }
        f->push_back(CSVField(getCSVValidator(NAMELISTVALIDATOR)));

        for(size_t i = f->size(); i < NPUBHEADER; i++){
            f->push_back(CSVField(getCSVValidator(STRINGVALIDATOR)));
        }
    }
    else if(t == GRANTS){
        nMan = NGRAMANDATORY;

        string head[] = {"Start Date","End Date","Member Name","Primary Domain",
            "Funding Type","Status", "Peer Reviewed?","Industry Grant?", "Role",
            "Title", "Principal Investigator", "Total Amount", "Co-Investigators",

            "Short Title", "Application Summary", "Grant Purpose", "Area",
            "Grand and/or Account #", "Prorated Amount", "Administered By",
            "Funding Source", "Project", "Currency", "Received Amount",
            "Member Share", "Monetary", "Reportable", "Hours Per Week",
            "Personnel Paid", "Rnw", "Education Grant", "Duplicate Reported"
                 };

        header = std::vector<std::string>(head, head + NGRAHEADER);

        f->push_back(CSVField(getCSVValidator(DATEVALIDATOR)));
        f->push_back(CSVField(getCSVValidator(DATEVALIDATOR)));
        for(size_t i = 0; i < 9; i++){
            f->push_back(CSVField(getCSVValidator(STRINGVALIDATOR)));
        }
        f->push_back(CSVField(getCSVValidator(MONEYVALIDATOR)));
        f->push_back(CSVField(getCSVValidator(NAMELISTVALIDATOR)));

        for(size_t i = f->size(); i < NGRAHEADER; i++){
            f->push_back(CSVField(getCSVValidator(STRINGVALIDATOR)));
        }
    }
    else if(t == PRESENTATION){
        nMan = NPREMANDATORY;

        string head[] = {"Date","Member Name","Primary Domain","Type","Role", "Title",

                  "Activity Type","Geographical Scope","Host","Country","Province",
                  "City","Number of Attendees","Hours","Teaching Effectiveness Score",
                  "Education Presentation","Remarks","Authorship",
                  "Rest of Citation","Personal Remuneration"
                 };

        header = std::vector<std::string>(head, head + NPREHEADER);

        f->push_back(CSVField(getCSVValidator(DATEVALIDATOR)));
        for(size_t i = 0; i < 5; i++){
            f->push_back(CSVField(getCSVValidator(STRINGVALIDATOR)));
        }

        for(size_t i = f->size(); i < NPREHEADER; i++){
            f->push_back(CSVField(getCSVValidator(STRINGVALIDATOR)));
        }
    }
    else{
        nMan = NTEAMANDATORY;

        string head[] = {"Start Date","End Date","Member Name","Primary Domain","Program",
                      "Type of Course / Activity","Geographical Scope",
                      "Hours per Teaching Session or Week",
                      "Number of Teaching Sessions or Weeks","Total Hours",

                      "Number Of Trainees",

                      "Institution / Organization","Faculty","Department","Division",
                      "Location","Faculty Member Additional Comments","Student Name(s)",
                      "Initial Lecture","Faculty Development","Stipend Received","Comment"
                 };

        header = std::vector<std::string>(head, head + NTEAMANDATORY);

        f->push_back(CSVField(getCSVValidator(DATEVALIDATOR)));
        f->push_back(CSVField(getCSVValidator(DATEVALIDATOR)));
        for(size_t i = 0; i < 5; i++){
            f->push_back(CSVField(getCSVValidator(STRINGVALIDATOR)));
        }
        f->push_back(CSVField(getCSVValidator(MONEYVALIDATOR)));
        f->push_back(CSVField(getCSVValidator(MONEYVALIDATOR)));
        f->push_back(CSVField(getCSVValidator(MONEYVALIDATOR)));

        for(size_t i = f->size(); i < NGRAHEADER; i++){
            f->push_back(CSVField(getCSVValidator(STRINGVALIDATOR)));
        }
    }
}


string CSVDTO::getFile(){
    string s = this->fileName;
    size_t i = s.find_last_of("/");
    return s.substr( i + 1,s.length());
}
