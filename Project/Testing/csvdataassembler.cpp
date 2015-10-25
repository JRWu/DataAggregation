#include "csvdataassembler.h"
#include <iostream>
using namespace std;

bool AssembleData(shared_ptr<CSVData<PublicationDTO>> data, string fileName)
{
    string h[] = {"Status Date","Member Name","Primary Domain","Publication Status",
                  "Type","Role","Journal Name | Published In | Book Title | etc.",
                  "Title","Author(s)",

                  "Pubmed Article ID","Peer Reviewed?","Author #","Volume","Issue",
                  "Page Range","DOI","Website","Journal Impact Factor",
                  "International","Publisher","Is Presentation?",
                  "Personal Remuneration","Trainee Details",
                  "Is Most Significant Publication?",
                  "Most Significant Contribution Details","Education Publication",
                  "ISBNISSN"
                       };
    int nMan = 9;

    io::CSVReader<27, io::trim_chars<' ','\t'>, io::double_quote_escape<',','\"'>, io::empty_line_comment >
            in(fileName);

    in.read_header(io::ignore_extra_column|io::ignore_missing_column,
                   h[0],h[1],h[2],h[3],h[4],h[5],h[6],h[7],h[8],h[9],h[10],h[11],
                   h[12],h[13],h[14],h[15],h[16],h[17],h[18],h[19],h[20],h[21],
                   h[22],h[23],h[24],h[25],h[26]
                   );

    //check that all mandatory headers are present.
    for(int i = 0; i < nMan; i++){
        if(!in.has_column(h[i])) return false;
    }

    //Read all lines of the CSV, verify them, and the catch errors or build DTOs
    vector<string> f(27);
    while(in.read_row(f[0],f[1],f[2],f[3],f[4],f[5],f[6],f[7],f[8],f[9],f[10],
                      f[11],f[12],f[13],f[14],f[15],f[16],f[17],f[18],f[19],
                      f[20],f[21],f[22],f[23],f[24],f[25],f[26])){


        if(validatePublication(&f) == 0){
            PublicationDTO dto;
            assembleDTO(&dto, f);
            data->addDTO(dto);
        }
        else{
            data->addError(f);
        }

        //Clear all rows
        for(int i = 0; i < 26; i++){
            f[i] = "";
        }
    }

    return true;
}

