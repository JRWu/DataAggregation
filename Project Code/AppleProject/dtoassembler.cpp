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

void assembleDTO(GrantDTO *dto, vector<string> f){
    //Mandatory Fields
    dto->name = f[0];
    dto->domain = f[1];
    dto->startDate = atoi(f[2].c_str());
    dto->endDate = atoi(f[3].c_str());
    dto->fType = f[4];
    dto->status = f[5];
    dto->peerReviewed = f[6];
    dto->industryGrant = f[7];
    dto->role = f[8];
    dto->title = f[9];
    dto->principal_investigator = f[10];
    dto->totalAmount = f[11];
    dto->title = f[12];
    
    //Optional Fields
    dto->shortTitle = f[13];
    dto->applicationSummary = f[14];
    dto->generalPurpose = f[15];
    dto->area = f[16];
    dto->grantNum = f[17];
    dto->proratedAmount = f[18];
    dto->administeredBy = f[19];
    dto->fundingSource = f[20];
    dto->project = f[21];
    dto->currency = f[22];
    dto->receivedAmount = f[23];
    dto->memberShare = f[24];
    dto->monetary = f[25];
    dto->rpt = f[26];
    dto->HrPerWk = f[27];
    dto->personnelPaid = f[28];
    dto->Rnw = f[29];
    dto->edGrant = f[30];
    dto->DupReported = f[31];
}
