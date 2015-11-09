#include "grantdto.h"


int nextid = 0;

//Default Constructor
GrantDTO::GrantDTO()
{
    //Mandatory Fields
    Membername = domain = title = principal_investigator = coinvestigator = "";
    startDate = endDate = 0;
    
    //Optional Fields
    shortTitle = applicationSummary = generalPurpose = area = grantNum = administeredBy = fundingSource = project = personnelPaid = "";
    
    proratedAmount = receivedAmount = memberShare = HrPerWk = 0.0;
    
    /* Commented out bc not sure if they're numbers or bool
    peerReviewed = industryGrant = monetary = rpt = rnw = edGrant = DupReported = ""
     */
    
    id = ++nextid;
}

GrantDTO::~GrantDTO()
{
    authors.reset();
}
