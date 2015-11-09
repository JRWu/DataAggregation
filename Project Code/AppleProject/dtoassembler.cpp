#include "dtoassembler.h"

void assembleDTO(PublicationDTO *dto, vector<string> f){
    //Mandatory Fields
    dto->date = atoi(f[0].c_str());
    dto->name = f[1];
    dto->domain = f[2];
    dto->status = f[3];
    dto->type = f[4];
    dto->role = f[5];
    dto->journalName = f[6];
    dto->title = f[7];

    //Split up the authors list
    stringstream ss(f[8]);
    string item;
    //Split around ,
    while(getline(ss, item, ',')) dto->authors->push_back(item);


    //Optional Fields
    dto->pubmedID = f[9];
    dto->peerReviewed = f[10];
    dto->authorNumber = f[11];
    dto->volume = f[12];
    dto->issue = f[13];
    dto->pageRange = f[14];
    dto->DOI = f[15];
    dto->website = f[16];
    dto->impactFactor = f[17];
    dto->international = f[18];
    dto->publisher = f[19];
    dto->presentation = f[20];
    dto->personalRenumeration = f[21];
    dto->traineeDetails = f[22];
    dto->mostSignificant = f[23];
    dto->mostSignificantDetails = f[24];
    dto->education = f[25];
    dto->ISBN = f[26];
}

void assembleDTO(PresentationDTO *dto, vector<string> f){

    //Mandatory Fields
    dto->date = atoi(f[0].c_str());
    dto->name = f[1];
    dto->domain = f[2];
    dto->type = f[3];
    dto->role = f[4];
    dto->title = f[5];

    //Optional Fields
    dto->activityType = f[6];
    dto->geoScope = f[7];
    dto->host = f[8];
    dto->country = f[9];
    dto->province = f[10];
    dto->city = f[11];
    dto->attendeeNum = f[12];
    dto->hours = f[13];
    dto->teachScore = f[14];
    dto->presentation = f[15];
    dto->remarks = f[16];

    //Split up the authors list
    stringstream ss(f[17]);
    string item;
    //Split around ,
    while(getline(ss, item, ',')) dto->authorship->push_back(item);

    dto->citation = f[18];
    dto->personalRenumeration = f[19];
}
