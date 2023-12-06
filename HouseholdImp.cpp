#include <iostream>
#include <string>
#include "Household.h"

Household::Household(){
    address = "N/A";
    relationship = "N/A";
    residence = "N/A";
    ownership = "N/A";
}

void Household::setHouseholdInfo(string strAddress, string strRelationship, string strResidenceType, string strOwnershipStatus){
    address = strAddress;
    relationship = strRelationship;
    residence = strResidenceType;
    ownership = strOwnershipStatus;
}

void Household::printHouseholdInfo() const{
    cout << "Street Address: " << address;
    cout << "Relationship: " << relationship;
    cout << "Residence: " << residence;
    cout << "Ownership: " << ownership;
}


