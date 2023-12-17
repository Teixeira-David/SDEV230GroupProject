// ----------------------------------------------------------------
// Author: David Teixeira 
// Project: Group Final Project
// Course: SDEV-230
// Creation Date: 11/24/2023
// ----------------------------------------------------------------

// Import the Preprocessor Directives
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <array>
#include <sstream>

// Include the headers for class definition
#include "PersonClass.h"

// Provide scope to identifiers inside the standard library
using namespace std;

// Class method implementations 
// Defualt Constructor
PersonClass::PersonClass() 
    : m_aPersons(nullptr),
      m_intMaxPersonCount(0),
      m_strFirstName(""),
      m_strLastName(""),
      m_strAgeRange(""),
      m_strCustomGender(""),
      m_strCustomMaritalStatus(""),
      m_strCustomEthnicity(""),
      m_strOccupation(""),
      m_strCustomEducationLevel(""),
      m_eGenderType(GenderType::OTHER),
      m_eMaritalStatusType(MaritalType::OTHER),
      m_eEducationLevelType(EducationType::OTHER),
      m_eEthnicityType(EthnicityType::OTHER) {}

// Constructor with parameters
PersonClass::PersonClass(string firstName, string lastName, string age, GenderType gender, MaritalType maritalStatus, 
                         EthnicityType ethnicity, string occupation, EducationType educateLevel)
    : m_aPersons(nullptr),
      m_intMaxPersonCount(0),
      m_strFirstName(firstName),
      m_strLastName(lastName),
      m_strAgeRange(age),
      m_strCustomGender(""),
      m_strCustomMaritalStatus(""),
      m_strCustomEthnicity(""),
      m_strOccupation(occupation),
      m_strCustomEducationLevel(""),
      m_eGenderType(gender),
      m_eMaritalStatusType(maritalStatus),
      m_eEducationLevelType(educateLevel),
      m_eEthnicityType(ethnicity) {}


void PersonClass::enterPersonDetails() 
/*
Function Name: enterPersonDetails
Function Purpose: This function is to get all the inputs required for each person
*/
{
    // Call the existing setter methods for each attribute
    setFirstName();
    setLastName();
    setAge();
    setGender();
    setMaritalStatus();
    setEthnicity();
    setOccupation();
    setEducation();
}
    
PersonClass** PersonClass::allocPersons() 
/*
Function Name: allocPersons
Function Purpose: This function is to allocate memory for each new household entry and return the Person array 
object to user.
*/
{
    while (true) {
        // Get the max person count for the household
        cout << "\n\nEnter the number of people in the household: ";
        if (!(cin >> m_intMaxPersonCount) || m_intMaxPersonCount < 0) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number.\n";
            continue;
        }
        // Create the null pointer
        PersonClass** m_aPersons = nullptr;
        try {
            // Create the pointer array set to the maximum number of people in the household
            m_aPersons = new PersonClass*[m_intMaxPersonCount];

            // Allocate memory for the PersonClass objects
            for (int i = 0; i < m_intMaxPersonCount; i++) {
                m_aPersons[i] = new PersonClass();
                // m_aPersons[i]->enterPersonDetails();
            }
            // Return the array of pointers. This return object must be paired with the destroy function 
            return m_aPersons;
        } catch (const std::bad_alloc& e) {
            // Handle memory allocation failure
            cout << "Memory allocation failed: " << e.what() << endl;
            // Deallocate memory allocated so far
            for (int i = 0; i < m_intMaxPersonCount; i++) {
                delete m_aPersons[i];
            }
            delete[] m_aPersons;
            return nullptr;
        } catch (const std::exception& e) {
            // Handle other exceptions
            cout << "An error occurred: " << e.what() << endl;
            // Deallocate memory allocated so far
            for (int i = 0; i < m_intMaxPersonCount; i++) {
                delete m_aPersons[i];
            }
            delete[] m_aPersons;
            return nullptr;
        }
    }
}

void PersonClass::deallocPersons(PersonClass** aPersons, int intSize) 
/*
Function Name: deallocPersons
Function Purpose: This function is to de-allocate memory for each new household entry and return the Person array 
object to user.
*/
{
    if (aPersons != nullptr) {
        for (int i = 0; i < intSize; i++) {
            delete aPersons[i];
        }
        delete[] aPersons;
    }
}

void PersonClass::setFirstName()
/*
Function Name: setFirstName
Function Purpose: This function is to gets the first name of the person
*/
{
    while (true) {
        // Delcare Local Variables
        string strInput = "";

        // Get the user input
        cout << "\n\nPlease enter the first name: ";
        if (!(cin >> strInput)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error reading input. Please try again. \n";
            continue;
        }

        // Check if input contains any digits
        if (any_of(strInput.begin(), strInput.end(), ::isdigit)) {
            cout << "Input should not contain numbers. Please try again.\n";
            continue;
        }

        try {
            // Check if the input is empty
            if (strInput.empty()) {
                throw runtime_error("First name cannot be empty.");
            }

            // Set the param to input if valid
            m_strFirstName = strInput;
            break;
        
        // End Catch    
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nPlease enter the first name: ";
        }
    }
}

void PersonClass::setLastName()
/*
Function Name: setLastName
Function Purpose: This function is to gets the last name of the person
*/
{
    while (true) {
        // Delcare Local Variables
        string strInput = "";

        // Get the user input
        cout << "\n\nPlease enter the last name: ";
        if (!(cin >> strInput)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error reading input. Please try again. \n";
            continue;
        }

        // Check if input contains any digits
        if (any_of(strInput.begin(), strInput.end(), ::isdigit)) {
            cout << "Input should not contain numbers. Please try again.\n";
            continue;
        }

        try {
            // Check if the input is empty
            if (strInput.empty()) {
                throw runtime_error("Last name cannot be empty.");
            }

            // Set the param to input if valid
            m_strLastName = strInput;
            break;
        
        // End Catch    
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nPlease enter the last name: ";
        }
    }
}

void PersonClass::setAge()
/*
Function Name: setAge
Function Purpose: This function is to sets the age of the person
*/
{
    // Delcare Local Variables
    array<string, 18> ageRanges = {
        "Under 5 Years Old", "5 to 9 Years Old", "10 to 14 Years Old", 
        "15 to 19 Years Old", "20 to 24 Years Old", "25 to 29 Years Old", 
        "30 to 34 Years Old", "35 to 39 Years Old", "40 to 44 Years Old", 
        "45 to 49 Years Old", "50 to 54 Years Old", "55 to 59 Years Old", 
        "60 to 64 Years Old", "65 to 69 Years Old", "70 to 74 Years Old", 
        "75 to 79 Years Old", "80 to 84 Years Old", "85 and over"};

    // Loop to handle user input until a valid choice is made
    while (true) {
        try {
            // Display the age range choices to the user
            cout << "\n\nSelect the age range:\n\n";
            for (size_t i = 0; i < ageRanges.size(); ++i) {
                cout << (i + 1) << ".) " << ageRanges[i] << "\n";
            }

            // Prompt the user to enter their choice
            cout << "\n\nEnter your choice (1-" << ageRanges.size() << "): ";
            int choice;
            cin >> choice;

            // Check for input failure (non-integer input)
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid input. Please enter a number.");
            }

            // Check if the choice is outside the valid range
            if (choice < 1 || choice > static_cast<int>(ageRanges.size())) {
                throw runtime_error("Invalid selection. Please enter a number within the valid range.");
            }

            // Set the age range based on the user's choice
            m_strAgeRange = ageRanges[static_cast<size_t>(choice - 1)];
            cout << "Selected age range: " << m_strAgeRange << "\n";
            break;  

        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nPlease enter the age of household member: ";
        }   
    }
}

void PersonClass::setGender() 
/*
Function Name: setGender
Function Purpose: This function is to sets the gender of the person.
*/
{
    while (true) {
        try {
            // Declare Local Variables
            int choice;

            // Display the choices
            cout << "\n\nSelect the gender:\n\n";
            cout << "1. Female\n";
            cout << "2. Male\n";
            cout << "3. Non-Binary\n";
            cout << "4. Transgender\n";
            cout << "5. Genderqueer\n";
            cout << "6. Other\n";
            cout << "\n\nEnter your choice: ";

            // Get the input choice
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 6) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid selection. Please enter a number between 1 and 6.");
            }

            // Declare the switch statement for enum type
            switch (choice) {
                case 1: m_eGenderType = GenderType::FEMALE; break;
                case 2: m_eGenderType = GenderType::MALE; break;
                case 3: m_eGenderType = GenderType::NON_BINARY; break;
                case 4: m_eGenderType = GenderType::TRANSGENDER; break;
                case 5: m_eGenderType = GenderType::GENDERQUEER; break;
                case 6: 
                    m_eGenderType = GenderType::OTHER;
                    cout << "Enter custom gender: ";                    
                    cin >> ws;
                    getline(cin, m_strCustomGender);
                    if (m_strCustomGender.empty()) {
                        throw runtime_error("Custom gender cannot be empty.");
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
            cout << "\n\nPlease enter the custom gender of household member: ";
        }
    }
}

void PersonClass::setMaritalStatus() 
/*
Function Name: setMaritalStatus
Function Purpose: This function is to sets the marital status of the person.
*/
{
    while (true) {
        try {
            // Declare Local Variables
            int choice;

            // Display the choices
            cout << "\n\nSelect the marital status:\n\n";
            cout << "1. Single\n";
            cout << "2. Married\n";
            cout << "3. Separated\n";
            cout << "4. Divorced\n";
            cout << "5. Widowed\n";
            cout << "6. Civil Partnership\n";
            cout << "7. Other\n";
            cout << "\n\nEnter your choice: ";

            // Get the input choice
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 7) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid selection. Please enter a number between 1 and 7.");
            }

            // Declare the switch statement for enum type
            switch (choice) {
                case 1: m_eMaritalStatusType = MaritalType::SINGLE; break;
                case 2: m_eMaritalStatusType = MaritalType::MARRIED; break;
                case 3: m_eMaritalStatusType = MaritalType::SEPARATED; break;
                case 4: m_eMaritalStatusType = MaritalType::DIVORCED; break;
                case 5: m_eMaritalStatusType = MaritalType::WIDOWED; break;
                case 6: m_eMaritalStatusType = MaritalType::CIVIL_PARTNERSHIP; break;
                case 7: 
                    m_eMaritalStatusType = MaritalType::OTHER;
                    cout << "Enter custom marital status: ";
                    cin >> ws; // Consume any leading whitespace
                    getline(cin, m_strCustomMaritalStatus); 
                    if (m_strCustomMaritalStatus.empty()) {
                        throw runtime_error("Custom marital status cannot be empty.");
                    }
                    break;
                default:
                    throw runtime_error("Invalid selection.");
            }
            break; // Exit loop on successful input

        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nPlease enter the custom marital status of household member: ";
        }
    }
}

void PersonClass::setOccupation()
/*
Function Name: setOccupation
Function Purpose: This function is to gets the occupation of the person
*/
{
    while (true) {
        // Declare Local Variables
        string strInput = "";

        // Clear any errors and ignore any characters remaining in the input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Get the user input
        cout << "\n\nPlease enter the occupation of household member: ";
        getline(cin, strInput);

        // Check if input contains any digits
        if (any_of(strInput.begin(), strInput.end(), ::isdigit)) {
            cout << "Input should not contain numbers. Please try again.\n";
            continue;
        }

        try {
            // Check if the input is empty
            if (strInput.empty()) {
                throw runtime_error("Occupation cannot be empty.");
            }

            // Set the member variable to input if valid
            m_strOccupation = strInput;
            break;

        // End Catch    
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nPlease enter the occupation of household member: ";
        }
    }
}

void PersonClass::setEthnicity() 
/*
Function Name: setEthnicity
Function Purpose: This function is to sets the ethnicity of the person.
*/
{
    while (true) {
        try {
            // Declare Local Variables
            int choice;

            // Display the choices
            cout << "\n\nSelect the ethnicity:\n\n";
            cout << "1. Caucasian\n";
            cout << "2. African\n";
            cout << "3. Latino\n";
            cout << "4. Native American\n";
            cout << "5. Pacific Islander\n";
            cout << "6. Mixed Ethnicity\n";
            cout << "7. Other\n";
            cout << "\n\nEnter your choice: ";

            // Get the input choice
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 7) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid selection. Please enter a number between 1 and 7.");
            }

            // Declare the switch statement for enum type
            switch (choice) {
                case 1: m_eEthnicityType = EthnicityType::CAUCASIAN; break;
                case 2: m_eEthnicityType = EthnicityType::AFRICAN; break;
                case 3: m_eEthnicityType = EthnicityType::LATINO; break;
                case 4: m_eEthnicityType = EthnicityType::NATIVE_AMERICAN; break;
                case 5: m_eEthnicityType = EthnicityType::PACIFIC_ISLANDER; break;
                case 6: m_eEthnicityType = EthnicityType::MIXED_ETHNICITY; break;
                case 7: 
                    m_eEthnicityType = EthnicityType::OTHER;
                    cout << "Enter custom ethnicity: ";
                    cin >> ws;
                    getline(cin, m_strCustomEthnicity); 
                    if (m_strCustomEthnicity.empty()) {
                        throw runtime_error("Custom ethnicity cannot be empty.");
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
            cout << "\n\nPlease enter the custom ethnicity of household member: ";
        }
    }
}

void PersonClass::setEducation() {
/*
Function Name: setEducation
Function Purpose: This function is to sets the education level of the person.
*/    
    while (true) {
        try {
            // Declare Local Variables
            int choice;

            // Display the choices
            cout << "\n\nSelect the education level:\n\n";
            cout << "1. No Schooling\n";
            cout << "2. Some Primary Education\n";
            cout << "3. Primary Education\n";
            cout << "4. Some Secondary Education\n";
            cout << "5. Secondary Education\n";
            cout << "6. Vocational Training\n";
            cout << "7. Some College\n";
            cout << "8. College Education\n";
            cout << "9. Post Graduate\n";
            cout << "10. Advanced Degree\n";
            cout << "11. Other\n";
            cout << "\n\nEnter your choice: ";
            
            // Get the input choice
            cin >> choice;            
            if (cin.fail() || choice < 1 || choice > 11) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid selection. Please enter a number between 1 and 11.");
            }

            switch (choice) {
                case 1: m_eEducationLevelType = EducationType::NO_SCHOOLING; break;
                case 2: m_eEducationLevelType = EducationType::SOME_PRIMARY_EDUCATION; break;
                case 3: m_eEducationLevelType = EducationType::PRIMARY_EDUCATION; break;
                case 4: m_eEducationLevelType = EducationType::SOME_SECONDARY_EDUCATION; break;
                case 5: m_eEducationLevelType = EducationType::SECONDARY_EDUCATION; break;
                case 6: m_eEducationLevelType = EducationType::VOCATIONAL_TRAINING; break;
                case 7: m_eEducationLevelType = EducationType::SOME_COLLEGE; break;
                case 8: m_eEducationLevelType = EducationType::COLLEGE_EDUCATION; break;
                case 9: m_eEducationLevelType = EducationType::POST_GRADUATE; break;
                case 10: m_eEducationLevelType = EducationType::ADVANCED_DEGREE; break;
                case 11: 
                    m_eEducationLevelType = EducationType::OTHER;
                    cout << "Enter custom education level: ";
                    cin >> ws;
                    getline(cin, m_strCustomEducationLevel); 
                    if (m_strCustomEducationLevel.empty()) {
                        throw runtime_error("Custom education level cannot be empty.");
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
            cout << "\n\nPlease enter the custom education level of household member: ";
        }
    }
}    

// Method Purpose: Get the GenderType
GenderType PersonClass::getGenderType_Enum() const 
{
    return m_eGenderType;
}

// Method Purpose: Get the MaritalType
MaritalType PersonClass::getMaritalType_Enum() const 
{
    return m_eMaritalStatusType;
}

// Method Purpose: Get the EducationType
EducationType PersonClass::getEducationType_Enum() const 
{
    return m_eEducationLevelType;
}

// Method Purpose: Get the EthnicityType
EthnicityType PersonClass::getEthnicityType_Enum() const 
{
    return m_eEthnicityType;
}

// Method Purpose: Get the first name
string PersonClass::getFirstName() const 
{
    return m_strFirstName;
}

// Method Purpose: Get the last name
string PersonClass::getLastName() const 
{
    return m_strLastName;
}

// Method Purpose: Get the age range
string PersonClass::getAgeRange() const 
{
    return m_strAgeRange;
}

// Method Purpose: Get the custom gender
string PersonClass::getGender() const 
{
    return m_strCustomGender;
}

// Method Purpose: Get the custom marital status
string PersonClass::getMaritalStatus() const 
{
    return m_strCustomMaritalStatus;
}

// Method Purpose: Get the custom ethnicity
string PersonClass::getEthnicity() const 
{
    return m_strCustomEthnicity;
}

// Method Purpose: Get the occupation
string PersonClass::getOccupation() const 
{
    return m_strOccupation;
}

// Method Purpose: Get the custom education
string PersonClass::getEducation() const 
{
    return m_strCustomEducationLevel;
}

// Method Purpose: Get the custom education
int PersonClass::getMaxPersonCount() const 
{
    return m_intMaxPersonCount;
}

string PersonClass::Get_First_Last_Name() const
{
    // Return the concatenated string
    stringstream m_strFullName;
    m_strFullName << getFirstName() << " " << getLastName();
    return m_strFullName.str();
}

string PersonClass::genderTypeToString() const 
/*
Function Name: genderTypeToString
Function Purpose: This function converts the enum type to string
*/
{
    switch (m_eGenderType) {
        case GenderType::FEMALE: return "Female";
        case GenderType::MALE: return "Male";
        case GenderType::NON_BINARY: return "Non-Binary";
        case GenderType::TRANSGENDER: return "Transgender";
        case GenderType::OTHER: return "Other: " + m_strCustomGender;
        default: return "Unknown Gender";
    }
}

string PersonClass::maritalTypeToString() const 
/*
Function Name: maritalTypeToString
Function Purpose: This function converts the enum type to string
*/
{
    switch (m_eMaritalStatusType) {
        case MaritalType::SINGLE: return "Single";
        case MaritalType::MARRIED: return "Married";
        case MaritalType::SEPARATED: return "Separated";
        case MaritalType::DIVORCED: return "Divorced";
        case MaritalType::CIVIL_PARTNERSHIP: return "Civil Partnership";
        case MaritalType::OTHER: return "Other: " + m_strCustomMaritalStatus;
        default: return "Unknown Marital Status";
    }
}

string PersonClass::educationTypeToString() const 
/*
Function Name: educationTypeToString
Function Purpose: This function converts the enum type to string
*/
{
    switch (m_eEducationLevelType) {
        case EducationType::NO_SCHOOLING: return "No Schooling";
        case EducationType::SOME_PRIMARY_EDUCATION: return "Some Primary Education";
        case EducationType::PRIMARY_EDUCATION: return "Primary Education";
        case EducationType::SOME_SECONDARY_EDUCATION: return "Some Secondary Education";
        case EducationType::SECONDARY_EDUCATION: return "Secondary Education";
        case EducationType::VOCATIONAL_TRAINING: return "Vocational Training";
        case EducationType::SOME_COLLEGE: return "Some College";
        case EducationType::COLLEGE_EDUCATION: return "College Education";
        case EducationType::POST_GRADUATE: return "Post Graduate";
        case EducationType::ADVANCED_DEGREE: return "Advanced Degree";
        case EducationType::OTHER: return "Other: " + m_strCustomEducationLevel;
        default: return "Unknown Education Level";
    }
}

string PersonClass::ethnicityTypeToString() const 
/*
Function Name: genderTypeToString
Function Purpose: This function converts the enum type to string
*/
{
    switch (m_eEthnicityType) {
        case EthnicityType::CAUCASIAN: return "Caucasian";
        case EthnicityType::AFRICAN: return "African";
        case EthnicityType::LATINO: return "Latino";
        case EthnicityType::NATIVE_AMERICAN: return "Native American";
        case EthnicityType::PACIFIC_ISLANDER: return "Pacific Islander";
        case EthnicityType::MIXED_ETHNICITY: return "Mixed Ethnicity";
        case EthnicityType::OTHER: return "Other: " + m_strCustomEthnicity;
        default: return "Unknown Ethnicity";
    }
}

// Method Purpose: Display the whole set of members
void PersonClass::print() const
{
    cout << "Name: " << m_strFirstName << " " << m_strLastName << endl;
    cout << "Age: " << m_strAgeRange << endl;
    cout << "Gender: " << genderTypeToString() << endl;
    cout << "Marital Status: " << maritalTypeToString() << endl;
    cout << "Ethnicity: " << ethnicityTypeToString() << endl;
    cout << "Occupation: " << m_strOccupation << endl;
    cout << "Education Level: " << educationTypeToString() << endl;
}

// Method Purpose: Display the fName and lName
void PersonClass::printName() const
{
    cout << "Name: " << m_strFirstName << " " << m_strLastName << endl;
}

// Method Purpose: Display the Gender
void PersonClass::printGender() const
{
    cout << "Gender: " << genderTypeToString() << endl;
}

// Method Purpose: Display the Age
void PersonClass::printAge() const
{
    cout << "Age: " << m_strAgeRange << endl;
}

// Method Purpose: Display the Marital Status
void PersonClass::printMaritalStatus() const
{
    cout << "Marital Status: " << maritalTypeToString() << endl;
}

// Method Purpose: Display the Ethnicity
void PersonClass::printEthnicity() const
{
    cout << "Ethnicity: " << ethnicityTypeToString() << endl;
}

// Method Purpose: Display the Occupation
void PersonClass::printOccupation() const
{
    cout << "Occupation: " << m_strOccupation << endl;
}

// Method Purpose: Display the Education Level
void PersonClass::printEducationLevel() const
{
    cout << "Education Level: " << educationTypeToString() << endl;
}

// Method to format for file
string PersonClass::formatForFile() const 
{
    // Declare Local Variables
    stringstream ss;

    // Format person data
    ss << getFirstName() << ", "
        << getLastName() << ", "
        << getAgeRange() << ", "
        << genderTypeToString() << ", "
        << maritalTypeToString() << ", "
        << ethnicityTypeToString() << ", "
        << getOccupation() << ", "
        << educationTypeToString() << ", ";

    // Return the concatenated string
    return ss.str();   
}