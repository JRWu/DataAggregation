#ifndef grantdto_h
#define grantdto_h

#include <string>
#include <vector>
#include <memory>

using namespace std;

/* Here if we need it
 
 enum FundingType{
 GRANTS, CLINICAL_TRIALS
 };
 
 
 enum Status{
 APPLIED, FUNDED, DECLINED, REJECTED, NOT_FUNDED
 };
 
 
 enum Role{
 COAPPLICANT, COINVESTIGATOR, COLLABORATOR, COPRINCIPAL_INVESTIGATOR, PRINCIPAL_APPLICANT, PRINCIPAL_INVESTIGATOR, PRINCIPAL_SITE_INVESTIGATOR, SITE_INVESTIGATOR
 };
 
 enum Currency{
 CAD,USD
 
 */

class GrantDTO{
public:

    //Mandatory Fields
    string memberName, domain, fundingType, status, role, title, pInvestigator;
    
    unsigned int startDate, endDate;
    
    float totalAmount;

    shared_ptr<vector<string>> cInvestigator;
    

    //Optional Fields
    string shortTitle, applicationSummary, grantPurpose, area, grantNum, administeredBy, fundingSource, project, currency, personnelPaid;

    float proratedAmount, receivedAmount, memberShare, HrPerWk;

    //These might not be numbers or bool??
    string peerReviewed, industryGrant, monetary, rpt, rnw, edGrant, dupReported;
    GrantDTO();
    ~GrantDTO();
};

#endif // PUBLICATIONDTO

