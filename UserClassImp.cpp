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
#include <array>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#ifdef _WIN32
#include <direct.h>
#else
#include <unistd.h>
#endif

// Include the headers for class definition
#include "UserClass.h"

// Provide scope to identifiers inside the standard library
using namespace std;

UserClass::UserClass() : PersonClass(), m_strEmpID("") {}

UserClass::UserClass(string firstName, string lastName, string age, GenderType gender, MaritalType maritalStatus, 
                     EthnicityType ethnicity, string occupation, EducationType educateLevel, string empID)
    : PersonClass(firstName, lastName, age, gender, maritalStatus, ethnicity, occupation, educateLevel), m_strEmpID(empID) {}

void UserClass::enterUserDetails()
/*
Function Name: enterUserDetails
Function Purpose: This function is to get all the inputs required for the user
(Author: David Teixeira)
*/
{
    // Declare Local Variables
    string strInput = "";

    // Clear the screen and display the startup message
    ControlFlowClass controlFlowInst;
    controlFlowInst.ClearScreen();
    controlFlowInst.DisplayStartUpMsg();
    string fEmpDataFile = controlFlowInst.Get_EmployeeData_File();

    // Declare Local Variables
    string strTmpString = "";

    // Get the user's first, last name, and employee ID
    PersonClass::setFirstName();
    PersonClass::setLastName();
    
    // Get the user's employee ID
    while (true) {
        cout << "\n\nPlease enter the employee ID: ";
        if (!(cin >> strInput)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error reading input. Please try again.\n";
            continue;
        }

        if (strInput.empty()) {
            cout << "Employee ID cannot be empty. Please try again.\n";
            continue;
        }

        if (!(Get_EmpID_IfExists(strInput))) {
            cout << "Creating new user. Proceeding to dashboard...\n";
            // Open the file for writing
            ofstream outfile(fEmpDataFile, ios::app);
            if (!outfile.is_open()) {
                throw runtime_error("Error opening file for writing: " + fEmpDataFile);
            }

            // Format and write the new user's information to the file
            outfile << strInput << ", " << PersonClass::getFirstName() << ", " << PersonClass::getLastName() << ",\n";
            outfile.close();
            cout << "New employee added successfully.\n";
            break;
        } else {
            cout << "Employee ID already exist. Please try again.\n";
            continue;
        }
    }
}

void UserClass::setEmpID(const string& initialEmpID = "")
/*
Function Name: setEmpID
Function Purpose: This function is to get the employee ID of the user
(Author: David Teixeira)
*/
{
    // Delcare Local Variables
    string strInput = initialEmpID;
    
    // Check if the user's employee ID is already set
    if (!strInput.empty() && Get_EmpID_IfExists(strInput)) {
        cout << "Login successful. Proceeding to dashboard...\n";
        return;
    }

    // Get the user's employee ID
    while (true) {
        cout << "\n\nPlease enter the employee ID: ";
        if (!(cin >> strInput)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error reading input. Please try again.\n";
            continue;
        }

        if (strInput.empty()) {
            cout << "Employee ID cannot be empty. Please try again.\n";
            continue;
        }

        if (Get_EmpID_IfExists(strInput)) {
            cout << "Login successful. Proceeding to dashboard...\n";
            break;
        } else {
            cout << "Employee ID does not exist. Please try again.\n";
            continue;
        }
    }
}

string getCurrentWorkingDirectory() {
// (Author: David Teixeira)
    char buff[FILENAME_MAX];
    #ifdef _WIN32
    _getcwd(buff, FILENAME_MAX);
    #else
    getcwd(buff, FILENAME_MAX);
    #endif
    string current_working_dir(buff);
    return current_working_dir;
}

// Function to remove unwanted characters (like commas) from a string
void trimSpecialCharacters(string& str) { // (Author: David Teixeira)
    // Remove trailing special characters (e.g., commas)
    str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char c) { 
        return !std::isalnum(c); // Remove if not alphanumeric
    }), str.end());
}

// Function to check if a file can be opened for reading
bool canOpenFileForRead(const string& filePath) { // (Author: David Teixeira)
    ifstream file(filePath);
    return file.is_open();
}

// Function to check if a file can be opened for writing
bool UserClass::Get_EmpID_IfExists(const string& initialEmpID) 
// (Author: David Teixeira)
{
    // Try to open the file for reading
    try {
        ControlFlowClass controlFlowInst;
        string fEmpDataFile = controlFlowInst.Get_EmployeeData_File();
        
        // Check if the file exists and can be opened for reading
        if (!canOpenFileForRead(fEmpDataFile)) {
            throw runtime_error("File does not exist or cannot be opened: " + fEmpDataFile);
        }
        
        // Open the file for reading
        ifstream file(fEmpDataFile);
        string line, employeeID, firstName, lastName;

        // Read the file line by line and check if the input employee ID exists
        while (getline(file, line)) {
            istringstream iss(line);
            if (iss >> employeeID >> firstName >> lastName) {
                trimSpecialCharacters(employeeID);
                if (employeeID == initialEmpID) {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
        return false;
    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
        return false;
    }
}

void UserClass::Set_AddNew_Employee(const string& initialEmpID) 
/*
Function Name: Set_AddNew_Employee
Function Purpose: This function is to add a new employee to the employee data file
(Author: David Teixeira)
*/
{
    // This function should ensure no duplicate ID is created
    try {
        ControlFlowClass controlFlowInst;
        controlFlowInst.ClearScreen();
        controlFlowInst.DisplayStartUpMsg();
        string fEmpDataFile = controlFlowInst.Get_EmployeeData_File();

        // Check for duplicate ID
        if (Get_EmpID_IfExists(initialEmpID)) {
            cout << "Employee ID already exists. Please try a different ID.\n";
            return;
        }

        // Open the file for writing
        ofstream outfile(fEmpDataFile, ios::app);
        if (!outfile.is_open()) {
            throw runtime_error("Error opening file for writing: " + fEmpDataFile);
        }

        UserClass newUser;
        newUser.setEmpID(initialEmpID);
        newUser.enterUserDetails(); 

        // Format and write the new user's information to the file
        outfile << newUser.getEmpID() << ", " << newUser.getFirstName() << ", " << newUser.getLastName() << ",\n";
        outfile.close();
        cout << "New employee added successfully.\n";
    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }
}

string UserClass::getEmpID() const
{
    return m_strEmpID;
}

void UserClass::print() const {
    PersonClass::print(); 
    printEmpID();
}

void UserClass::printEmpID() const
{
    cout << "User employee ID number: " << m_strEmpID << endl;
}
