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
        void setOwnerhsip();

        //getters
        string getAddress() const;
        string getRelationship() const;
        string getResidence() const;
        string getOwnership() const;

        //printing
        void printAll() const;
        void printAddress() const;
        void printRelationship() const;
        void printResidence() const;
        void printOwnership() const;

        //constructors
        Household();
        Household(string add, string rel, string res, string own);

    private:
        //variables
        string address;
        string relationship;
        string residence;
        string ownership;
};

#endif
