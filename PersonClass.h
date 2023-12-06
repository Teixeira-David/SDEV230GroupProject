// ----------------------------------------------------------------
// Author: David Teixeira 
// Project: Group Final Project
// Course: SDEV-230
// Creation Date: 11/16/2023
// ----------------------------------------------------------------

// Check preprocessor macro for definition
#ifndef H_PersonClass
#define H_PersonClass

// Import the Preprocessor Directives
#include <iostream>
#include <string>

// Provide scope to identifiers inside the standard library
using namespace std;

// Create the constants

// Place the enumeration class for person classification
enum class GenderType{FEMALE, MALE, NON_BINARY, TRANSGENDER, GENDERQUEER, OTHER};
enum class MaritalType{SINGLE, MARRIED, SEPARATED, DIVORCED, WIDOWED, CIVIL_PARTNERSHIP, OTHER};
enum class EducationType{NO_SCHOOLING, SOME_PRIMARY_EDUCATION, PRIMARY_EDUCATION, SOME_SECONDARY_EDUCATION,
                        SECONDARY_EDUCATION, VOCATIONAL_TRAINING, SOME_COLLEGE, COLLEGE_EDUCATION,
                        POST_GRADUATE, ADVANCED_DEGREE, OTHER};
enum class EthnicityType{CAUCASIAN, AFRICAN, LATINO, NATIVE_AMERICAN, PACIFIC_ISLANDER, MIXED_ETHNICITY, OTHER};

// Delcare Classes
class PersonClass
/*
Class Name: PersonClass
Class Purpose: This is the PersonClass class
*/
{
    // Delcare the pulic user functions
    public:
        // Create the default constructor
        PersonClass();

        // Constructor with parameters
        PersonClass(string firstName, string lastName, string age, GenderType gender, MaritalType maritalStatus, 
                    EthnicityType ethnicity, string occupation, EducationType educateLevel);

        // Setter Functions
        void setPersonDetails(string firstName, string lastName, string age, GenderType gender, 
            MaritalType maritalStatus, EthnicityType ethnicity, string occupation, EducationType educateLevel);
        void setFirstName(string& firstName); 
        void setLastName(string& lastName); 
        void setAge(string& age); 
        void setGender(); 
        void setMaritalStatus(); 
        void setEthnicity(); 
        void setOccupation(string& occupation);
        void setEducation(); 

        // Getter Functions
        GenderType getGenderType_Enum() const;
        MaritalType getMaritalType_Enum() const;
        EthnicityType getEthnicityType_Enum() const;
        EducationType getEducationType_Enum() const;
        string getFirstName() const;
        string getLastName() const;
        string getAgeRange() const;
        string getGender() const;
        string getMaritalStatus() const;
        string getEthnicity() const;
        string getOccupation() const;
        string getEducation() const;

        // Functions to print information
        void print() const;
        void printName() const;
        void printGender() const;
        void printAge() const;
        void printMaritalStatus() const;
        void printEthnicity() const;
        void printOccupation() const;
        void printEducationLevel() const;

    // Delcare the private class members 'm_' -> member var indicator
    private:
        // Set the members
        string m_strFirstName;
        string m_strLastName;
        string m_strAgeRange;
        string m_strCustomGender;
        string m_strCustomMaritalStatus;
        string m_strCustomEthnicity;
        string m_strOccupation;
        string m_strCustomEducationLevel;

        // Enumeration Types
        GenderType m_eGenderType;
        MaritalType m_eMaritalStatusType;
        EducationType m_eEducationLevelType;
        EthnicityType m_eEthnicityType;

        // Enum to string
        string genderTypeToString() const;
        string maritalTypeToString() const;
        string educationTypeToString() const;
        string ethnicityTypeToString() const;
};

#endif