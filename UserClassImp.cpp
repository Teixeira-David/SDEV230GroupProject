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
*/
{
    // Declare Local Variables
    string strTmpString = "";

    PersonClass::enterPersonDetails();
    setEmpID(strTmpString);
}

void UserClass::setEmpID(const string& initialEmpID = "")
/*
Function Name: setEmpID
Function Purpose: This function is to get the employee ID of the user
*/
{
    // Delcare Local Variables
    string strInput = initialEmpID;
    
    // Get the user's employee ID
    while (true) {
        if (strInput.empty()) {
            cout << "\n\nPlease enter the employee ID: ";
            if (!(cin >> strInput)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error reading input. Please try again.\n";
                continue;
            }
        }

        // Validate the user's employee ID
        try {
            if (strInput.empty()) {
                throw runtime_error("Employee ID cannot be empty.");
            }
            
            if (Get_EmpID_IfExists(strInput)) {
                cout << "Login successful. Proceeding to dashboard...\n";
                // Code to proceed to the dashboard goes here
                break;
            } else {
                cout << "This Employee ID does not exist. Would you like to create a new Employee ID? (y/n): ";
                char response;
                cin >> response;
                if (response == 'y' || response == 'Y') {
                    Set_AddNew_Employee(strInput); // This function should ensure no duplicate ID is created
                    break;
                } else {
                    strInput.clear(); 
                }
            }
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            strInput.clear(); // Reset strInput for new input
        }
    }
}

string getCurrentWorkingDirectory() {
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
void trimSpecialCharacters(string& str) {
    // Remove trailing special characters (e.g., commas)
    str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char c) { 
        return !std::isalnum(c); // Remove if not alphanumeric
    }), str.end());
}

// Function to check if a file can be opened for reading
bool canOpenFileForRead(const string& filePath) {
    ifstream file(filePath);
    return file.is_open();
}

bool UserClass::Get_EmpID_IfExists(const string& initialEmpID) 
{
    try {
        ControlFlowClass controlFlowInst;
        string fEmpDataFile = controlFlowInst.Get_EmployeeData_File();
        
        if (!canOpenFileForRead(fEmpDataFile)) {
            throw runtime_error("File does not exist or cannot be opened: " + fEmpDataFile);
        }
        
        ifstream file(fEmpDataFile);
        string line, employeeID, firstName, lastName;

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
Function Author: David Teixeira
*/
{
    // This function should ensure no duplicate ID is created
    try {
        ControlFlowClass controlFlowInst;
        string fEmpDataFile = controlFlowInst.Get_EmployeeData_File();

        // Check if the file exists and can be opened for reading
        if (!canOpenFileForRead(fEmpDataFile)) {
            throw runtime_error("File does not exist or cannot be opened: " + fEmpDataFile);
        }

        // Open the file for writing
        ofstream outfile(fEmpDataFile, ios::app);
        if (!outfile.is_open()) {
            throw runtime_error("Error opening file for writing: " + fEmpDataFile);
        }

        // Get the user's first and last name
        UserClass newUser;
        newUser.setEmpID(initialEmpID);
        newUser.setFirstName(); // Ensure these methods are handling user input
        newUser.setLastName();

        // Write the new user's information to the file
        outfile << initialEmpID << " " << newUser.getFirstName() << " " << newUser.getLastName() << endl;
        outfile.close();
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
