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
    UserClass(string firstName, string lastName, string empID);

    // Setter Functions
    void setFirstName();
    void setLastName();
    void setEmpID();
    void enterUserDetails();


    // Getter Functions
    string getFirstName() const;
    string getLastName() const;
    string getEmpID() const;

    // Functions to print information
    void print() const;
    void printName() const;
    void printEmpID() const;

    // Delcare the private class members 'm_' -> member var indicator
private:
    // Set the members
    string m_strFirstName;
    string m_strLastName;
    string m_strEmpID;
};

#endif