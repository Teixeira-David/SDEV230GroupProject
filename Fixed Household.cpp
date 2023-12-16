//Implementation file for class Household.h
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

#include "Household.h"

using namespace std;

//constructors
//default constructor
Household::Household()
    : address(""), relationship(""), residence(""), ownership("") {}

//constructor with parameters
Household::Household(string add, string rel, string res, string own) {
    address = add;
    relationship = rel;
    residence = res;
    ownership = own;
}


void Household::enterHouseholdDetails()
/*
Function Name: enterHouseholdDetails
Function Purpose: This function is to get all the inputs required for each household
*/
{
    // Call the existing setter methods for each attribute
    setAddress();
    setRelationship();
    setResidence();
    setOwnership();
}

Household** Household::allocHouseholds()
/*
Function Name: allocHouseholds
Function Purpose: This function is to allocate memory for each new household entry and return the Household array
object to user.
*/
{
    while (true) {
        // Create the null pointer
        Household** m_aHouseholds = nullptr;
        try {
            // Create the pointer array set to the maximum number of people in the household
            m_aHouseholds = new Household * [m_intMaxHouseholdCount];

            // Allocate memory for the Household objects
            for (int i = 0; i < m_intMaxHouseholdCount; i++) {
                m_aHouseholds[i] = new Household();
                // m_aHouseholds[i]->enterHouseholdDetails();
            }
            // Return the array of pointers. This return object must be paired with the destroy function 
            return m_aHouseholds;
        }
        catch (const std::bad_alloc& e) {
            // Handle memory allocation failure
            cout << "Memory allocation failed: " << e.what() << endl;
            // Deallocate memory allocated so far
            for (int i = 0; i < m_intMaxHouseholdCount; i++) {
                delete m_aHouseholds[i];
            }
            delete[] m_aHouseholds;
            return nullptr;
        }
        catch (const std::exception& e) {
            // Handle other exceptions
            cout << "An error occurred: " << e.what() << endl;
            // Deallocate memory allocated so far
            for (int i = 0; i < m_intMaxHouseholdCount; i++) {
                delete m_aHouseholds[i];
            }
            delete[] m_aHouseholds;
            return nullptr;
        }
    }
}

void Household::deallocHouseholds(Household** aHouseholds, int intSize)
/*
Function Name: deallocHouseholds
Function Purpose: This function is to de-allocate memory for each new household entry and return the household array
object to user.
*/
{
    if (aHouseholds != nullptr) {
        for (int i = 0; i < intSize; i++) {
            delete aHouseholds[i];
        }
        delete[] aHouseholds;
    }
}


//setters
void Household::setHouseholdVars(string add, string rel, string res, string own) {
    address = add;
    relationship = rel;
    residence = res;
    ownership = own;
}

void Household::setAddress() {
    string input = "";

    cout << "Enter household address: ";
    // cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Nick added this line it basically clears any leftover characters before making the newline
    getline(cin, input); // Needs to get the full line, not just until the first white space
    address = input;
}

void Household::setRelationship() {
    string input = "";

    cout << "Enter relationship of household owner: ";
    // cin >> input;
    getline(cin, input); // Needs to get the full line, not just until the first white space
    relationship = input;
}

void Household::setResidence() {
    string input = "";

    cout << "Enter residence type (Apartment, Condo or House): ";
    // cin >> input;
    getline(cin, input); // Needs to get the full line, not just until the first white space
    residence = input;
}

void Household::setOwnership() {
    string input = "";

    cout << "Enter owner of the household: ";
    // cin >> input;
    getline(cin, input); // Needs to get the full line, not just until the first white space
    ownership = input;
}



//getters
string Household::getAddress() const {
    return address;
}

string Household::getRelationship() const {
    return relationship;
}

string Household::getResidence() const {
    return residence;
}

string Household::getOwnership() const {
    return ownership;
}

// Method Purpose: Get the member
int Household::getMaxHouseholdCount() const
{
    return m_intMaxHouseholdCount;
}

//printing
void Household::printAll() const {
    cout << "Address of household: " << address << endl;
    cout << "Relationship status: " << relationship << endl;
    cout << "Residence type: " << residence << endl;
    cout << "Owner of household " << ownership << endl;
}

void Household::printAddress() const {
    cout << "Address of household: " << address << endl;
}

void Household::printRelationship() const {
    cout << "Relationship status: " << relationship << endl;
}

void Household::printResidence() const {
    cout << "Residence type: " << residence << endl;
}

void Household::printOwnership() const {
    cout << "Owner of household" << ownership << endl;
}

// Method to format for file
string Household::formatForFile() const
{
    // Declare Local Variables
    stringstream ss;

    // Concatenate member variables into a string
    ss << getAddress() << ", "
        << getRelationship() << ", "
        << getResidence() << ", "
        << getOwnership();

    // Return the concatenated string
    return ss.str();
}
