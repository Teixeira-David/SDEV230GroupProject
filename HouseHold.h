// ----------------------------------------------------------------
// Author: Wyatt Kessie
// Project: Group Final Project
// Course: SDEV-230
// ----------------------------------------------------------------

//Header file for class Household.h
#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include <iostream>
#include <string>
#include <vector>

// Make sure to include the file header for census data
// #include "CensusData.h" 
#include "PersonClass.h"

using namespace std;

// Place the enumeration class for household classification
// add to make sure we have options for relationships to owner 
enum class RelationshipType{SPOUSE, DEPENDENT, PARENT, SIBLING, 
                TENANT, CAREGIVER, EMPLOYEE, FRIEND, OTHER}; 

// add to make sure we have options for residence type 
enum class ResidenceType{SINGLE_FAMILY, MULTI_FAMILY, APARTMENT, CONDO, 
                TOWNHOUSE, MOBILE, DORMITORY, NURSING_HOME, SHELTER, OTHER}; 
 
// add to make sure we have options for ownership type 
enum class OwnershipType{SOLE_OWNERSHIP, JOINT_OWNERSHIP, TENANCY, COMMUNITY_OWNERSHIP, CORPORATE_OWNERSHIP, 
                LLC_OWNERSHIP, TRUST_OWNERSHIP, GOVERNMENT_OWNERSHIP, NON_PROFIT_OWNERSHIP, RELIGIOUS_OWNERSHIP,
                EDUCATIONAL_OWNERSHIP, ESTATE_OWNERSHIP, FOREIGN_OWNERSHIP, OTHER}; 

class Household{
    public:
        // Constructors
        Household(); // 
        Household(string add, string rel, string res, string own, RelationshipType relationshipType,
            ResidenceType residenceType, OwnershipType ownershipType); // 

        void setHouseholdVars(string add, string rel, string res, string own);
        void setAddress();
        void setRelationship();
        void setResidence(); // 
        void setOwnership(); // 
        void enterHouseholdDetails(const vector<PersonClass>& persons); // 
        void selectOwner(const vector<PersonClass>& persons); // 

        // Execution memory methods
        Household** allocHouseholds(); //
        void deallocHouseholds(Household** aHouseholds, int intSize); // 

        //getters
        string getAddress() const;
        string getRelationship() const;
        string getResidence() const;
        string getOwnership() const;
        string getOwnershipType() const; // 
        int getMaxHouseholdCount() const; // 

        //printing
        void printAll() const;
        void printAddress() const;
        void printRelationship() const;
        void printResidence() const;
        void printOwnership() const;

        //constructors
        // Household();
        // Household(string add, string rel, string res, string own);

        // Format for file dump
        string formatForFile() const; // 

        // Enum to string
        string relationshipTypeToString() const; // 
        string residenceTypeToString() const; // 
        string ownerTypeToString() const; // 

    private:
        // Store memory information
        // Household** m_aHouseholds;
        int m_intMaxHouseholdCount = 1; // 

        //variables
        string address;
        string relationship;
        string residence;
        string ownership;
        string m_strCustomRelationshipType; // 
        string m_strCustomResidenceType; // 
        string m_strCustomOwnerType; // 

        // Enumeration Types
        RelationshipType m_eRelationshipType;
        ResidenceType m_eResidenceType;
        OwnershipType m_eOwnerType;
};

#endif