// ----------------------------------------------------------------
// Author: Matthew McKinley Jr. 
// Project: Group Final Project
// Course: SDEV-230
// Creation Date: 12/08/2023
// ----------------------------------------------------------------

// Check preprocessor macro for definition
#ifndef H_UserClass
#define H_UserClass

// Import the Preprocessor Directives
#include <iostream>
#include <string>

// Import header file for base class
#include "PersonClass.h"
#include "ControlFlowClass.h"

// Provide scope to identifiers inside the standard library
using namespace std;

// Create the constants

// Delcare Classes
class UserClass : public PersonClass
/*
Class Name: UserClass
Class Purpose: This is the UserClass class
*/
{
// Delcare the public user functions
public:
    // Create the default constructor
    UserClass();

    // Constructor with parameters
    UserClass(string firstName, string lastName, string age, GenderType gender, MaritalType maritalStatus, 
              EthnicityType ethnicity, string occupation, EducationType educateLevel, string empID);

    // Setter Functions
    void setEmpID(const string& initialEmpID);
    void Set_AddNew_Employee(const string& initialEmpID);
    void enterUserDetails();

    // Getter Functions
    bool Get_EmpID_IfExists(const string& initialEmpID);
    string getEmpID() const;

    // Functions to print information
    void print() const;
    void printEmpID() const;

    // Delcare the private class members 'm_' -> member var indicator
private:
    // Set the members
    string m_strEmpID;
};

#endif