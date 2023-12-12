//Implementation file for class Household.h
#include <iostream>
#include <string>

#include "Household.h"

using namespace std;

//constructors
//default constructor
Household::Household(){
    address = "N/A";
    relationship = "N/A";
    residence = "N/A";
    ownership = "N/A";
}

//constructor with parameters
Household::Household(string add, string rel, string res, string own){
    address = add;
    relationship = rel;
    residence = res;
    ownership = own;
}


//setters
Household::setHouseholdVars(string add, string rel, string res, string own){
    address = add;
    relationship = rel;
    residence = res;
    ownership = own;
}

Household::setAddress(){
    string input = "";

    cout << "Enter household address: ";
    cin >> input;
    address = input;
}

Household::setRelationship(){
    string input = "";

    cout << "Enter relationship of household owner: ";
    cin >> input;
    relationship = input;
}

Household::setResidence(){
    string input = "";

    cout << "Enter residence type (Apartment, Condo or House): ";
    cin >> input;
    residence = input;
}

Household::setOwnership(){
    string input = "";

    cout << "Enter owner of the household: ";
    cin >> input;
    ownership = input;
}



//getters
string Household::getAddress() const{
    return address;
}

string Household::getRelationship() const{
    return relationship;
}

string Household::getResidence() const{
    return residence;
}

string Household::getOwnership() const{
    return ownership;
}


//printing
void printAll() const{
    cout << "Address of household: "  << address;
    cout << "Relationship status: " << relationship;
    cout << "Residence type: " << residence;
    cout << "Owner of household" << ownership;
}

void printAddress() const{
    cout << "Address of household: "  << address;
}

void printRelationship() const{
    cout << "Relationship status: " << relationship;
}

void printResidence() const{
    cout << "Residence type: " << residence;
}

void printOwnership() const{
    cout << "Owner of household" << ownership;
}

