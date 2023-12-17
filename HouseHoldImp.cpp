// ----------------------------------------------------------------
// Author: Wyatt Kessie 
// Project: Group Final Project
// Course: SDEV-230
// ----------------------------------------------------------------

//Implementation file for class Household.h
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <vector>

#include "Household.h"

// Make sure to include the file header for census data
// #include "CensusData.h"
#include "PersonClass.h"

using namespace std;

//constructors
//default constructor
Household::Household() 
    : address(""), 
        relationship(""), 
        residence(""), 
        ownership(""),
        m_eRelationshipType(RelationshipType::OTHER),
        m_eResidenceType(ResidenceType::OTHER),
        m_eOwnerType(OwnershipType::OTHER) {}

//constructor with parameters
Household::Household(string add, string rel, string res, string own, RelationshipType relationshipType,
    ResidenceType residenceType, OwnershipType ownershipType)
    : address(add), 
        relationship(rel), 
        residence(res), 
        ownership(own),
        m_eRelationshipType(relationshipType),
        m_eResidenceType(residenceType),
        m_eOwnerType(ownershipType) {}


void Household::enterHouseholdDetails(const vector<PersonClass>& persons) 
/*
Function Name: enterHouseholdDetails
Function Purpose: This function is to get all the inputs required for each household
*/
{
    // Call the existing setter methods for each attribute
    selectOwner(persons);
    setOwnership();

    // Get the current ownership type
    string ownershipType = ownerTypeToString();

    // Check if the ownership type is "Sole Ownership" or "Joint Ownership"
    if (ownershipType != "Sole Ownership" && ownershipType != "Joint Ownership") {
        // If not, then call the setRelationship method
        setRelationship();
    }

    // Call the existing setter methods for each attribute
    setAddress();
    setResidence();
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
            m_aHouseholds = new Household*[m_intMaxHouseholdCount];

            // Allocate memory for the Household objects
            for (int i = 0; i < m_intMaxHouseholdCount; i++) {
                m_aHouseholds[i] = new Household();
                // m_aHouseholds[i]->enterHouseholdDetails();
            }
            // Return the array of pointers. This return object must be paired with the destroy function 
            return m_aHouseholds;
        } catch (const std::bad_alloc& e) {
            // Handle memory allocation failure
            cout << "Memory allocation failed: " << e.what() << endl;
            // Deallocate memory allocated so far
            for (int i = 0; i < m_intMaxHouseholdCount; i++) {
                delete m_aHouseholds[i];
            }
            delete[] m_aHouseholds;
            return nullptr;
        } catch (const std::exception& e) {
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
    // Deallocate memory allocated so far
    if (aHouseholds != nullptr) {
        for (int i = 0; i < intSize; i++) {
            delete aHouseholds[i];
        }
        delete[] aHouseholds;
    }
}


//setters
void Household::setHouseholdVars(string add, string rel, string res, string own){
    address = add;
    relationship = rel;
    residence = res;
    ownership = own;
}

void Household::setAddress(){
    // string input = "";

    // cout << "Enter household address: ";
    // // cin >> input;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // getline(cin, input); // Needs to get the full line, not just until the first white space
    // address = input;

    while (true) {
        // Delcare Local Variables
        string strInput = "";

        // Get the user input
        cout << "\n\nPlease enter the street address of the household: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, strInput);

        try {
            // Check if the input is empty
            if (strInput.empty()) {
                throw runtime_error("Stree address cannot be empty.");
            }

            // Set the param to input if valid
            address = strInput;
            break;
        
        // End Catch    
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nPlease enter the street address of the household: ";
        }
    }
}

void Household::setRelationship(){
    // string input = "";

    // cout << "Enter relationship of household owner: ";
    // // cin >> input;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // getline(cin, input); // Needs to get the full line, not just until the first white space
    // relationship = input;

    while (true) {
        try {
            // Declare Local Variables
            int choice;

            // Display the choices
            cout << "\n\nSelect the relationship type to owner:\n\n";
            cout << "1. Spouse\n";
            cout << "2. Dependent\n";
            cout << "3. Parent\n";
            cout << "4. Sibling\n";
            cout << "5. Tenant\n";
            cout << "6. Caregiver\n";
            cout << "7. Employee\n";
            cout << "8. Friend\n";
            cout << "9. Other\n";
            cout << "\n\nEnter your choice: ";

            // Get the input choice
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 9) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid selection. Please enter a number between 1 and 9.");
            }

            // Declare the switch statement for enum type
            switch (choice) {
                case 1: m_eRelationshipType = RelationshipType::SPOUSE; break;
                case 2: m_eRelationshipType = RelationshipType::DEPENDENT; break;
                case 3: m_eRelationshipType = RelationshipType::PARENT; break;
                case 4: m_eRelationshipType = RelationshipType::SIBLING; break;
                case 5: m_eRelationshipType = RelationshipType::TENANT; break;
                case 6: m_eRelationshipType = RelationshipType::CAREGIVER; break;
                case 7: m_eRelationshipType = RelationshipType::EMPLOYEE; break;
                case 8: m_eRelationshipType = RelationshipType::FRIEND; break;
                case 9: 
                    m_eRelationshipType = RelationshipType::OTHER;
                    cout << "Enter custom relationship: ";
                    cin >> ws; // Consume any leading whitespace
                    getline(cin, m_strCustomRelationshipType); 
                    if (m_strCustomRelationshipType.empty()) {
                        throw runtime_error("Custom relationship type cannot be empty.");
                    }
                    break;
                default:
                    throw runtime_error("Invalid selection.");
            }
            break;

        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nPlease enter the relationship type to owner: ";
        }
    }
}

void Household::setResidence(){
    // string input = "";
    // cout << "Enter residence type (Apartment, Condo or House): ";
    // // cin >> input;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // getline(cin, input); // Needs to get the full line, not just until the first white space
    // residence = input;

    while (true) {
        try {
            // Declare Local Variables
            int choice;

            // Display the choices
            cout << "\n\nSelect the residence type:\n\n";
            cout << "1. Single Fmaily\n";
            cout << "2. Multi Family\n";
            cout << "3. Apartment\n";
            cout << "4. Condo\n";
            cout << "5. Townhouse\n";
            cout << "6. Mobile\n";
            cout << "7. Dormintory\n";
            cout << "8. Nursing Home\n";
            cout << "9. Shelter\n";
            cout << "10. Other\n";
            cout << "\n\nEnter your choice: ";

            // Get the input choice
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 10) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid selection. Please enter a number between 1 and 9.");
            }

            // Declare the switch statement for enum type
            switch (choice) {
                case 1: m_eResidenceType = ResidenceType::SINGLE_FAMILY; break;
                case 2: m_eResidenceType = ResidenceType::MULTI_FAMILY; break;
                case 3: m_eResidenceType = ResidenceType::APARTMENT; break;
                case 4: m_eResidenceType = ResidenceType::CONDO; break;
                case 5: m_eResidenceType = ResidenceType::TOWNHOUSE; break;
                case 6: m_eResidenceType = ResidenceType::MOBILE; break;
                case 7: m_eResidenceType = ResidenceType::DORMITORY; break;
                case 8: m_eResidenceType = ResidenceType::NURSING_HOME; break;
                case 9: m_eResidenceType = ResidenceType::SHELTER; break;
                case 10: 
                    m_eResidenceType = ResidenceType::OTHER;
                    cout << "Enter custom residence: ";
                    cin >> ws; // Consume any leading whitespace
                    getline(cin, m_strCustomResidenceType); 
                    if (m_strCustomResidenceType.empty()) {
                        throw runtime_error("Custom residence type cannot be empty.");
                    }
                    break;
                default:
                    throw runtime_error("Invalid selection.");
            }
            break;

        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nPlease enter the residence type to owner: ";
        }
    }
}    

void Household::setOwnership() {
    // string input = "";

    // cout << "Enter owner of the household: ";
    // // cin >> input;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // getline(cin, input); // Needs to get the full line, not just until the first white space
    // ownership = input;
    while (true) {
        try {
            // Declare Local Variables
            int choice;

            // Display the choices
            cout << "\n\nSelect the ownership type for " << ownership << ":\n\n";
            cout << "1. Sole Ownership\n";
            cout << "2. Joint Ownership\n";
            cout << "3. Tenant Ownership\n";
            cout << "4. Community Ownership\n";
            cout << "5. Corporate Ownership\n";
            cout << "6. LLC Ownership\n";
            cout << "7. Trust Ownership\n";
            cout << "8. Governement Ownership\n";
            cout << "9. Non-Profit Ownership\n";
            cout << "10. Religious Ownership\n";
            cout << "11. Educational Ownership\n";
            cout << "12. Estate Ownership\n";
            cout << "13. Foreign Ownership\n";
            cout << "14. Other\n";
            cout << "\n\nEnter your choice: ";

            // Get the input choice
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 14) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid selection. Please enter a number between 1 and 14.");
            }

            // Declare the switch statement for enum type
            switch (choice) {
                case 1: m_eOwnerType = OwnershipType::SOLE_OWNERSHIP; break;
                case 2: m_eOwnerType = OwnershipType::JOINT_OWNERSHIP; break;
                case 3: m_eOwnerType = OwnershipType::TENANCY; break;
                case 4: m_eOwnerType = OwnershipType::COMMUNITY_OWNERSHIP; break;
                case 5: m_eOwnerType = OwnershipType::CORPORATE_OWNERSHIP; break;
                case 6: m_eOwnerType = OwnershipType::LLC_OWNERSHIP; break;
                case 7: m_eOwnerType = OwnershipType::TRUST_OWNERSHIP; break;
                case 8: m_eOwnerType = OwnershipType::GOVERNMENT_OWNERSHIP; break;
                case 9: m_eOwnerType = OwnershipType::NON_PROFIT_OWNERSHIP; break;
                case 10: m_eOwnerType = OwnershipType::RELIGIOUS_OWNERSHIP; break;
                case 11: m_eOwnerType = OwnershipType::EDUCATIONAL_OWNERSHIP; break;
                case 12: m_eOwnerType = OwnershipType::ESTATE_OWNERSHIP; break;
                case 13: m_eOwnerType = OwnershipType::FOREIGN_OWNERSHIP; break;
                case 14: 
                    m_eOwnerType = OwnershipType::OTHER;
                    cout << "Enter custom residence: ";
                    cin >> ws; // Consume any leading whitespace
                    getline(cin, m_strCustomOwnerType); 
                    if (m_strCustomOwnerType.empty()) {
                        throw runtime_error("Custom residence type cannot be empty.");
                    }
                    break;
                default:
                    throw runtime_error("Invalid selection.");
            }
            break;

        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nPlease enter the residence type to owner: ";
        }
    }    
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

// Method Purpose: Get the member
int Household::getMaxHouseholdCount() const 
{
    return m_intMaxHouseholdCount;
}

//printing
void Household::printAll() const {
    cout << "Address of household: "  << address << endl;
    cout << "Relationship status: " << relationship << endl;
    cout << "Residence type: " << residence << endl;
    cout << "Owner of household" << ownership << endl;
}

void Household::printAddress() const{
    cout << "Address of household: "  << address << endl;
}

void Household::printRelationship() const{
    cout << "Relationship status: " << relationship << endl;
}

void Household::printResidence() const{
    cout << "Residence type: " << residence << endl;
}

void Household::printOwnership() const{
    cout << "Owner of household" << ownership << endl; 
}

// Method to format for file
string Household::formatForFile() const 
{
    // Declare Local Variables
    stringstream ss;

    // Get ownership type as a string
    string ownershipType = ownerTypeToString();

    // Check if the ownership type is "Sole Ownership" or "Joint Ownership"
    bool skipRelationship = (ownershipType == "Sole Ownership" || ownershipType == "Joint Ownership");

    // Concatenate member variables into a string
    ss << ownershipType << ", ";
    
    // Check if the relationship should be skipped
    if (!skipRelationship) {
        ss << relationshipTypeToString() << ", ";
    }

    // Concatenate the rest of the member variables
    ss << getAddress() << ", "
       << residenceTypeToString();

    // Return the concatenated string
    return ss.str();
}

void Household::selectOwner(const vector<PersonClass>& persons) 
/*
Function Name: selectOwner
Function Purpose: This function gets the owner of the household from the user
*/
{
    // Check if the persons vector is empty
    if (persons.empty()) {
        throw runtime_error("No persons have been added to the household.");
    }

    // Declare Local Variables
    int ownerChoice;

    // Display the choices
    cout << "Select the owner of the household:\n";
    for (size_t i = 0; i < persons.size(); ++i) {
        cout << i + 1 << ". " << persons[i].Get_First_Last_Name() << "\n";
    }

    // Get the input choice
    cout << "\nEnter the number of the owner: ";
    cin >> ownerChoice;

    // Check if the input is valid
    if (cin.fail() || ownerChoice < 1 || static_cast<size_t>(ownerChoice) > persons.size()) {
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input
        throw runtime_error("Invalid selection. Please enter a valid number.");
    }

    // Adjust ownerChoice to match vector index and set the ownership
    ownership = persons[ownerChoice - 1].Get_First_Last_Name();
}

string Household::relationshipTypeToString() const 
/*
Function Name: relationshipTypeToString
Function Purpose: This function converts the enum type to string
*/
{
    switch (m_eRelationshipType) {
        case RelationshipType::SPOUSE: return "Spouse";
        case RelationshipType::DEPENDENT: return "Dependent";
        case RelationshipType::PARENT: return "Parent";
        case RelationshipType::SIBLING: return "Sibling";
        case RelationshipType::TENANT: return "Tenant";
        case RelationshipType::CAREGIVER: return "Caregiver";
        case RelationshipType::EMPLOYEE: return "Employee";
        case RelationshipType::FRIEND: return "Friend";
        case RelationshipType::OTHER: return "Other: " + m_strCustomRelationshipType;
        default: return "Unknown relationship type";
    }
}

string Household::residenceTypeToString() const 
/*
Function Name: residenceTypeToString
Function Purpose: This function converts the enum type to string
*/
{
    switch (m_eResidenceType) {
        case ResidenceType::SINGLE_FAMILY: return "Single Fmaily";
        case ResidenceType::MULTI_FAMILY: return "Multi Family";
        case ResidenceType::APARTMENT: return "Apartment";
        case ResidenceType::CONDO: return "Condo";
        case ResidenceType::TOWNHOUSE: return "Townhouse";
        case ResidenceType::MOBILE: return "Mobile";
        case ResidenceType::DORMITORY: return "Dormintory";
        case ResidenceType::NURSING_HOME: return "Nursing Home";
        case ResidenceType::SHELTER: return "Nursing Home";
        case ResidenceType::OTHER: return "Other: " + m_strCustomResidenceType;
        default: return "Unknown residence type";
    }
}

string Household::ownerTypeToString() const 
/*
Function Name: ownerTypeToString
Function Purpose: This function converts the enum type to string
*/
{
    switch (m_eOwnerType) {
        case OwnershipType::SOLE_OWNERSHIP: return "Sole Ownership";
        case OwnershipType::JOINT_OWNERSHIP: return "Joint Ownership";
        case OwnershipType::TENANCY: return "Tenant Ownership";
        case OwnershipType::COMMUNITY_OWNERSHIP: return "Community Ownership";
        case OwnershipType::CORPORATE_OWNERSHIP: return "Corporate Ownership";
        case OwnershipType::LLC_OWNERSHIP: return "LLC Ownership";
        case OwnershipType::TRUST_OWNERSHIP: return "Trust Ownership";
        case OwnershipType::GOVERNMENT_OWNERSHIP: return "Governement Ownership";
        case OwnershipType::NON_PROFIT_OWNERSHIP: return "Non-Profit Ownership";
        case OwnershipType::RELIGIOUS_OWNERSHIP: return "Religious Ownership";
        case OwnershipType::EDUCATIONAL_OWNERSHIP: return "Educational Ownership";
        case OwnershipType::ESTATE_OWNERSHIP: return "Estate Ownership";
        case OwnershipType::FOREIGN_OWNERSHIP: return "Foreign Ownership";
        case OwnershipType::OTHER: return "Other: " + m_strCustomOwnerType;
        default: return "Unknown Ethnicity";
    }
}