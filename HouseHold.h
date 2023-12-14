//Header file for class Household.h
#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include <iostream>
#include <string>

using namespace std;

class Household{
    public:
        //setters
        void setHouseholdVars(string add, string rel, string res, string own);
        void setAddress();
        void setRelationship();
        void setResidence();
        void setOwnership();
        void enterHouseholdDetails();

        // Execution memory methods
        Household** allocHouseholds();
        void deallocHouseholds(Household** aHouseholds, int intSize);

        //getters
        string getAddress() const;
        string getRelationship() const;
        string getResidence() const;
        string getOwnership() const;
        int getMaxHouseholdCount() const;

        //printing
        void printAll() const;
        void printAddress() const;
        void printRelationship() const;
        void printResidence() const;
        void printOwnership() const;

        //constructors
        Household();
        Household(string add, string rel, string res, string own);

        // Format for file dump
        string formatForFile() const;

    private:
        // Store memory information
        // Household** m_aHouseholds;
        int m_intMaxHouseholdCount = 1;

        //variables
        string address;
        string relationship;
        string residence;
        string ownership;
};

#endif
