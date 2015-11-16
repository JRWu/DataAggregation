#include "grantdto.h"

GrantDTO::GrantDTO(){
    
    // Mandatory fields
    memberName = domain = fundingType = status = role = title = pInvestigator = "";

    startDate=endDate=0;
    
    totalAmount=0;

    cInvestigator = shared_ptr<vector<string>>(new vector<string>);

    //Optional fields
    shortTitle = applicationSummary = grantPurpose = area = grantNum = administeredBy = fundingSource, project = currency = personnelPaid = "";
    
    proratedAmount = receivedAmount = memberShare = HrPerWk = 0;

    // bools or string?
    peerReviewed = industryGrant = monetary = rpt = rnw = edGrant = dupReported = "";

}

GrantDTO::~GrantDTO(){

    cInvestigator.reset();
}

