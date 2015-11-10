#include "grantdto.h"

GrantDTO::GrantDTO(){

memberName=domain=title=PRINCIPAL_INVESTIGATOR=COINVESTIGATOR=
        fundingType=peerReviewed=industryGrant=
        role="";

    startDate=endDate=0;
    totalAmount=0.00;

    grant = shared_ptr<vector<string>>( new vector<string> );

    //optional
    proratedAmount=receivedAmount=memberShare=HrPerWk=0;

    monetary=rpt=rnw=edGrant=DupReported="";

}

GrantDTO::~GrantDTO(){

    grant.reset();
}

