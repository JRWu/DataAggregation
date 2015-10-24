#include "csvdataassembler.h"

using namespace std;

bool CSVDataAssembler::AssembleData(CSVData<PublicationDTO> *data, string fileName)
{
    string h[] = {"Status Date","Member Name","Primary Domain","Publication Status",
                  "Type","Role","Journal Name | Published In | Book Title | etc.",
                  "Author(s)","Title",

                  "Pubmed Article ID","Peer Reviewed?","Author #","Volume","Issue",
                  "Page Range","DOI","Website","Journal Impact Factor",
                  "International","Publisher","Is Presentation?",
                  "Personal Remuneration","Trainee Details",
                  "Is Most Significant Publication?",
                  "Most Significant Contribution Details","Education Publication",
                  "ISBNISSN"
                       };

    int nMan = 9;

    io::CSVReader<26> in(fileName);
    in.read_header(io::ignore_extra_column|io::ignore_missing_column,
                   h[0],h[1],h[2],h[3],h[4],h[5],h[6],h[7],h[8],h[9],h[10],h[11],
                   h[12],h[13],h[14],h[15],h[16],h[17],h[18],h[19],h[20],h[21],
                   h[22],h[23],h[24],h[25]
                   );

    for(int i = 0; i < nMan; i++){
        if(!in.has_column(h[i])) return false;
    }

    return true;
}

