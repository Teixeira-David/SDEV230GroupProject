// ----------------------------------------------------------------
// Author: Matthew McKinley Jr.
// Project: Group Final Project
// Course: SDEV-230
// Creation Date: 12/08/2023
// ----------------------------------------------------------------

// Import the Preprocessor Directives
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>

// Include the headers for class definition
#include "UserClass.h"

// Provide scope to identifiers inside the standard library
using namespace std;

UserClass::UserClass()
{
    m_strFirstName = "";
    m_strLastName = "";
    m_strEmpID = "";
}

UserClass::UserClass(string firstName, string lastName, string empID)
{
    m_strFirstName = firstName;
    m_strLastName = lastName;
    m_strEmpID = empID;
}

void UserClass::enterUserDetails()
/*
Function Name: enterUserDetails
Function Purpose: This function is to get all the inputs required for the user
*/
{
    // Call the existing setter methods for each attribute
    setFirstName();
    setLastName();
    setEmpID();
}

void UserClass::setFirstName()
/*
Function Name: setFirstName
Function Purpose: This function is to get the first name of the user
*/
{
    while (true) {
        // Delcare Local Variables
        string strInput = "";

        // Get the user input
        cout << "\n\nPlease enter user first name: ";
        if (!(cin >> strInput)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error reading input. Please try again. \n";
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
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nPlease enter the user first name: ";
        }
    }
}

void UserClass::setLastName()
/*
Function Name: setLastName
Function Purpose: This function is to get the last name of the user
*/
{
    while (true) {
        // Delcare Local Variables
        string strInput = "";

        // Get the user input
        cout << "\n\nPlease enter the user last name: ";
        if (!(cin >> strInput)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error reading input. Please try again. \n";
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
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nPlease enter the user last name: ";
        }
    }
}

void UserClass::setEmpID()
/*
Function Name: setEmpID
Function Purpose: This function is to get the employee ID of the user
*/
{
    while (true) {
        // Delcare Local Variables
        string strInput = "";

        // Get the user input
        cout << "\n\nPlease enter the employee ID: ";
        if (!(cin >> strInput)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error reading input. Please try again. \n";
            continue;
        }

        try {
            // Check if the input is empty
            if (strInput.empty()) {
                throw runtime_error("employee ID cannot be empty.");
            }

            // Set the param to input if valid
            m_strEmpID = strInput;
            break;

            // End Catch    
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\nPlease enter the employee ID: ";
        }
    }
}

string UserClass::getFirstName() const
{
    return m_strFirstName;
}

string UserClass::getLastName() const
{
    return m_strLastName;
}

string UserClass::getEmpID() const
{
    return m_strEmpID;
}

void UserClass::print() const
{
    printName();
    printEmpID();
}

void UserClass::printName() const
{
    cout << "Name of user: " << m_strFirstName << " " << m_strLastName << endl;
}

void UserClass::printEmpID() const
{
    cout << "User employee ID number: " << m_strEmpID << endl;
}