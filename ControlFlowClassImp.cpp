// ----------------------------------------------------------------
// Author: David Teixeira 
// Project: Group Final Project
// Course: SDEV-230
// Creation Date: 12/10/2023
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
#include <functional>

// Determine which preprocessor directive to use
#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#else
    #include <unistd.h>
    #include <limits.h>
#endif

// Include the headers for class definition
#include "ControlFlowClass.h"
#include "PersonClass.h"
#include "UserClass.h"
#include "CensusData.h"
#include "Household.h"
#include "Economics.h"
#include "GeographicClass.h"

// Provide scope to identifiers inside the standard library
using namespace std;

// Class method implementations 
// Defualt Constructor
ControlFlowClass::ControlFlowClass() {
         m_aCensusData = vector<CensusData>();
}

void ControlFlowClass::ClearScreen() 
/*
Function Name: ClearScreen
Function Purpose: This function clears the command line
*/
{
    // Check if the compiler is of win32 or other
    #ifdef _WIN32 
        system("cls");
    #else
        system("clear");
    #endif
}

void ControlFlowClass::DisplayStartUpMsg() 
/*
Function Name: DisplayStartUpMsg
Function Purpose: This function displays the start message
*/
{
    cout << "\n\n---------------------------------------------------------------------------------------";
    cout << "\n\t\t\t Welcome to CensusHub " << endl;
    cout << "---------------------------------------------------------------------------------------";
    cout << "\nWelcome to the CensusReport Application, a comprehensive tool designed to \n";
    cout << "meticulously gather and record essential demographic data. As you navigate through this \n";
    cout << "application, you will be guided to input a variety of human demographic information. We \n";
    cout << "kindly request your attention to detail and accuracy in every entry.\n\n";
    cout << "This software is engineered to facilitate a seamless data entry process, ensuring that \n";
    cout << "each piece of information contributes to a valuable census database. From basic personal \n";
    cout << "details to more intricate demographic aspects, your inputs play a crucial role in shaping \n";
    cout << "an accurate and meaningful demographic portrait.\n\n";
    cout << "Please take a moment to review your responses thoroughly before finalizing each \n";
    cout << "submission. Your careful consideration ensures the integrity and reliability of the data, \n";
    cout << "which is pivotal for insightful analysis and informed decision-making.\n\n";
    cout << "We appreciate your participation and diligence in contributing to this vital census \n";
    cout << "endeavor. Let's get started!\n";
    cout << "---------------------------------------------------------------------------------------\n";
}

void ControlFlowClass::DisplayLoginMsg() 
{
    cout << "\n---------------------------------------------------------------------------------------\n";
    cout << "\n\t\t\tWelcome to CensusHub User Login Page\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "Please choose one of the following options to proceed:\n\n";
    cout << "1. Log In: Use your existing Employee ID to access the application.\n";
    cout << "   Select this option if you already have an account. No password required.\n";
    cout << "2. Create New User: Set up a new account with a unique Employee ID.\n";
    cout << "   Choose this option if you are a new user or need to create an additional account.\n";
    cout << "3. Exit: Exit the program.\n";
    cout << "\nEnter '1' to Log In or '2' to Create New User. Otherwise, enter '3' to close the"; 
    cout << "\napplication.\n";
    cout << "---------------------------------------------------------------------------------------\n\n";
}

void ControlFlowClass::Display_DashBoardMenu() {
    cout << "\n---------------------------------------------------------------------------------------\n";
    cout << "\n\t\t\t     Main Dashboard of CensusHub\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "Welcome to the main dashboard of the CensusHub Application. Here, you can perform a\n";
    cout << "variety of tasks related to household census data collection and management.\n";
    cout << "Please select from the following options to proceed:\n\n";
    cout << "1. Request Add New Household: Register a new household and provide its detailed\n";
    cout << "information.\n";
    cout << "2. Generate Census Report: Create and view comprehensive reports based on collected\n";
    cout << "census data.\n";
    cout << "3. Exit the Program: Safely exit the CensusHub Application.\n";
    cout << "\nChoose an option by entering the corresponding number. Your input is vital for\n"; 
    cout << "effective census data management.\n";
    cout << "---------------------------------------------------------------------------------------\n\n";
}

void ControlFlowClass::Display_HouseHolds_Msg() 
{
    cout << "\n---------------------------------------------------------------------------------------\n";
    cout << "Welcome to the Household Information Collection Module of the CensusHub Application.\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "To complete this section, you will need to provide the following household information:\n\n";
    cout << "1. Address: The full address of the household, including street name, number, city, and ZIP code.\n";
    cout << "2. Relationship to Head of Household: Your relationship to the person who owns or rents the residence.\n";
    cout << "3. Type of Residence: The kind of residence you live in, such as a house, apartment, mobile home, etc.\n";
    cout << "4. Ownership Status: Whether the residence is owned, rented, or occupied under other arrangements.\n";
    cout << "\nPlease make sure to have this information at hand before proceeding with the data entry.\n";
    cout << "Providing accurate and complete information is crucial for the effectiveness of the census.\n";
    cout << "---------------------------------------------------------------------------------------\n\n";
}

void ControlFlowClass::Display_Persons_Msg() 
{
    cout << "\n---------------------------------------------------------------------------------------\n";
    cout << "\n\tWelcome to the Data Collection Module of the CensusHub Application.\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "To complete this section, you will need to provide the following information:\n\n";
    cout << "1. Full Name: Your complete legal name.\n";
    cout << "2. Age or Date of Birth: Either your age or your date of birth in a DD/MM/YYYY format.\n";
    cout << "3. Gender: Your gender identity. Options include Female, Male, Non-Binary, etc.\n";
    cout << "4. Marital Status: Your current marital status. Options include Single, Married, etc.\n";
    cout << "5. Ethnicity: Your ethnic background. Options include Caucasian, African, Latino, etc.\n";
    cout << "6. Occupation: Your current job or profession.\n";
    cout << "7. Education Level: Your highest completed level of education.\n";
    cout << "\nPlease ensure that you have this information available before proceeding.\n";
    cout << "Accuracy is important in providing reliable and insightful census data.\n";
    cout << "---------------------------------------------------------------------------------------\n\n";
}

void ControlFlowClass::Display_Economics_Msg() 
{
    cout << "\n---------------------------------------------------------------------------------------\n";
    cout << "\n\tEconomic Status Information Collection\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "In this section, we will be gathering vital economic information about your household.\n";
    cout << "Please be prepared to provide the following details:\n\n";
    cout << "1. Gross Income: The total income of the household before taxes and other deductions.\n";
    cout << "   Please have the annual gross income figures available for accuracy.\n";
    cout << "2. Employment Status: The current employment status of each household member.\n";
    cout << "   This includes categories such as employed, unemployed, retired, student, etc.\n";
    cout << "\nAccurate and complete economic information is crucial for a comprehensive understanding\n";
    cout << "of the household's economic standing and contributes significantly to the census analysis.\n";
    cout << "---------------------------------------------------------------------------------------\n\n";
}

void ControlFlowClass::Display_Geographics_Msg() 
{
    cout << "\n---------------------------------------------------------------------------------------\n";
    cout << "\n\tGeographic Information Collection\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "In this section, we will collect essential geographic information about your household.\n";
    cout << "Please be prepared to provide the following details:\n\n";
    cout << "1. State: The state in which your household is located.\n";
    cout << "   If outside the United States, please provide the relevant province, region, or territory.\n";
    cout << "2. Urbanization: The type of area your household is situated in.\n";
    cout << "   Options include 'Rural', 'Suburban', or 'Urban'.\n";
    cout << "\nAccurate geographic data helps in understanding the diverse living conditions and regional\n";
    cout << "differences across the population. Your information is valuable for comprehensive analysis.\n";
    cout << "---------------------------------------------------------------------------------------\n\n";
}

void ControlFlowClass::Display_UserDemos_Msg() 
{
    cout << "\n---------------------------------------------------------------------------------------\n";
    cout << "\n\tAdmin User Management Panel\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "As an admin, you have the ability to manage user access to the CensusHub Application.\n";
    cout << "Please select from the following options:\n\n";
    cout << "1. Add User: Register a new user for application access.\n";
    cout << "2. Edit User: Modify the details or permissions of an existing user.\n";
    cout << "3. Remove User: Delete a user's access to the application.\n";
    cout << "\nEnter the corresponding number to proceed with your choice, or enter 'Exit' to return to the main menu.\n";
    cout << "---------------------------------------------------------------------------------------\n\n";
}

void ControlFlowClass::DisplayCensusDataMsg() const
{
    cout << "\n---------------------------------------------------------------------------------------\n";
    cout << "\n\t\t\tCensusHub - Census Data Overview\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "Below is the overview of the collected census data. The information is presented \n";
    cout << "in a structured format to provide a clear and comprehensive view of the household demographics.\n\n";
    cout << "Each household's data includes:\n";
    cout << " - Household Owner Information: Name, Age, Gender, etc.\n";
    cout << " - Address and Ownership Details\n";
    cout << " - Details of Other Household Members\n";
    cout << " - Employment and Geographic Information\n\n";
    cout << "Please review the displayed data for accuracy and completeness.\n";
    cout << "Use the provided options for further actions or queries.\n";
    cout << "---------------------------------------------------------------------------------------\n";
}

string ControlFlowClass::Get_EmployeeData_File() const
{
    return m_fEmployeeDataFile;
}

void ControlFlowClass::LoginMenu() 
/*
Function Name: LoginMenu
Function Purpose: This function is to display the and get the user login authorization menu
*/
{

    while (true) {
        try {
            // Delcare Local Variables
            int choice;
            string strInput = "";

            // Display the choices
            ClearScreen();
            DisplayLoginMsg();
            cout << "Enter your choice: ";

            // Get the input choice
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid selection. Please enter a number between 1 and 3.");
            }

            // Create the instantiate object
            UserClass newUser;

            // Get the choice
            switch (choice) {
                case 1: newUser.setEmpID(strInput); break;
                case 2: newUser.enterUserDetails(); break;
                case 3: ExitProgram(); break; 
                default: 
                    throw runtime_error("Invalid selection.");
            }
            break;

        // End Catch
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }   
    }

    // Go to the main dashboard
    Main_Dashboard();
}

void ControlFlowClass::Main_Dashboard() 
/*
Function Name: Main_Dashboard
Function Purpose: This function is to display the menu options for the dashboard
*/
{
    // Loop through the menu options
    while (true) {
        try {
            // Delcare Local Variables
            int choice;

            // Display the choices
            ClearScreen();
            Display_DashBoardMenu();
            cout << "Enter your choice: ";

            // Get the input choice
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid selection. Please enter a number between 1 and 3.");
            }

            // Get the choice
            switch (choice) {
                case 1: Set_All_Requirements(); break;
                case 2: Generate_CensusReport(); break;
                case 3: ExitProgram(); break; 
                default: 
                    throw runtime_error("Invalid selection.");
            }
            break;

        // End Catch
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }   
    }
}

void ControlFlowClass::Set_All_Requirements() 
/*
Function Name: Set_All_Requirements
Function Purpose: This function is to set all the requirements for the census report entry
*/
{
    // Declare Local Variables
    bool addMore = true;

    // Loop throught the gathering of census data
    while (addMore) {
        // Clear out any existing data
        m_aCensusData.clear();

        // Create a single CensusData object
        CensusData censusData;

        // Assuming each Set_..._Info method sets the respective part of censusData
        Set_Persons_Info(censusData);
        Set_Households_Info(censusData);
        Set_Economics_Info(censusData);
        Set_Geographics_Info(censusData);

        // Add the fully populated censusData to m_aCensusData
        m_aCensusData.push_back(censusData);

        // Write to file 
        WriteCensusDataToFile(censusData.Get_CensusData_File());

        // Ask user if they want to add another household
        cout << "Do you want to add another household? (y/n): ";
        char response;
        cin >> response;

        // Check if the response is not yes
        if (response != 'y' && response != 'Y') {
            addMore = false;
        }
        // Return to the main dashboard
        Main_Dashboard();
    }
}

void ControlFlowClass::Set_Persons_Info(CensusData& censusData) 
/*
Function Name: Set_Persons_Info
Function Purpose: This function is to get the persons information
*/
{
    // Display the message
    ClearScreen();
    Display_Persons_Msg();

    // Get the inputs from the user
    PersonClass personObj;
    PersonClass** persons = personObj.allocPersons();

    // Check if persons is not null
    if (persons != nullptr) {
        // Loop through each person and get their details
        for (int i = 0; i < personObj.getMaxPersonCount(); i++) {
            persons[i]->enterPersonDetails();
            censusData.addPerson(*persons[i]);
        }
        // Deallocate memory when done
        personObj.deallocPersons(persons, personObj.getMaxPersonCount());
    }
}


void ControlFlowClass::Set_Households_Info(CensusData& censusData) 
/*
Function Name: Get_Household_Info
Function Purpose: This function is to get the household information
*/
{
    // Display the message
    ClearScreen();
    Display_HouseHolds_Msg();

    // Get the inputs from the user
    Household householdObj;
    Household** households = householdObj.allocHouseholds();

    // Assuming you have a vector of PersonClass objects called m_aPersonsData in your CensusData class
    const vector<PersonClass>& persons = censusData.getPersonsData(); 

    // Check if households is not null
    if (households != nullptr) {
        // Loop through each household and get their details
        for (int i = 0; i < householdObj.getMaxHouseholdCount(); i++) {
            households[i]->enterHouseholdDetails(persons);

          // Set the last person's data in censusData
            if (i == householdObj.getMaxHouseholdCount() - 1) {
                censusData.setHousehold(*households[i]);
            }
        }

        // Deallocate memory when done
        householdObj.deallocHouseholds(households, householdObj.getMaxHouseholdCount());
    }
}

void ControlFlowClass::Set_Economics_Info(CensusData& censusData) 
/*
Function Name: Set_Economics_Info
Function Purpose: This function is to get the econmics information
*/
{
    // Display the message
    ClearScreen();
    Display_Economics_Msg();

    // Get the inputs from the user
    Economics economicObj;
    Economics** economics = economicObj.allocEconomics();

    // Check if households is not null
    if (economics != nullptr) {
        // Loop through each household and get their details
        for (int i = 0; i < economicObj.getMaxEconomicCount(); i++) {
            economics[i]->enterEconomicsDetails();

          // Set the last person's data in censusData
            if (i == economicObj.getMaxEconomicCount() - 1) {
                censusData.setEconomics(*economics[i]);
            }
        }

        // Deallocate memory when done
        economicObj.deallocEconomics(economics, economicObj.getMaxEconomicCount());
    }
}

void ControlFlowClass::Set_Geographics_Info(CensusData& censusData) 
/*
Function Name: Set_Geographics_Info
Function Purpose: This function is to get the econmics information
*/
{
    // Display the message
    ClearScreen();
    Display_Geographics_Msg();

    // Get the inputs from the user
    geographicClass geographicObj;
    geographicClass** geographic = geographicObj.allocGeographics();

    // Check if households is not null
    if (geographic != nullptr) {
        // Loop through each household and get their details
        for (int i = 0; i < geographicObj.getMaxGeographicCount(); i++) {
            geographic[i]->enterGeographicDetails();
            
          // Set the last person's data in censusData
            if (i == geographicObj.getMaxGeographicCount() - 1) {
                censusData.setGeographic(*geographic[i]);
            }
        }

        // Deallocate memory when done
        geographicObj.deallocGeographics(geographic, geographicObj.getMaxGeographicCount());
    }
}

string ControlFlowClass::FormatCensusDataForFile() const 
/*
Function Name: FormatCensusDataForFile
Function Purpose: This function is format the data with no trailing whitespace and aggregates the data
    by comma. Preps for file dump.
*/
{
    // Declare Local Variables
    stringstream ss;

    // Iterate over all CensusData objects and format them for file output
    for (const auto& censusData : m_aCensusData) {
        string dataLine = censusData.formatForFile();

        // Trim right whitespace (including tabs and new lines)
        dataLine.erase(find_if(dataLine.rbegin(), dataLine.rend(), [](unsigned char ch) {
            return !isspace(ch);
        }).base(), dataLine.end());

        // Add a comma to the end of the line
        ss << dataLine;
        if (&censusData != &m_aCensusData.back()) {
            ss << "\n";
        }
    }
    // Return the formatted string
    return ss.str();
}

void ControlFlowClass::WriteCensusDataToFile(const string& filename) const 
/*
Function Name: WriteCensusDataToFile
Function Purpose: This function is dumps data to file.
*/
{
    // Open the file for writing
    ofstream fileStream(filename, ios::out | ios::trunc);
    if (!fileStream) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // Format the data for file output
    string formattedData = FormatCensusDataForFile();
    fileStream << formattedData;

    // Close the file
    fileStream.close();
}

vector<vector<string>> ControlFlowClass::readFileContents(const string& filename) const
/*
Function Name: readFileContents
Function Purpose: This function reads the data from the file
*/
{
    // Declare Local Variables
    vector<vector<string>> parsedData;
    ifstream fileStream(filename);

    // Check if the file is open
    if (!fileStream) {
        cerr << "Error opening file: " << filename << endl;
        return parsedData;
    }

    // Read and parse each line of the file
    string line;
    while (getline(fileStream, line)) {
        stringstream ss(line);
        vector<string> household;
        string item;

        // Parse the line by comma
        while (getline(ss, item, ',')) {
            household.push_back(item);
        }
        
        // Add the parsed line (household) to the parsedData
        parsedData.push_back(household);
    }
    // Return the parsed data
    return parsedData;
}

vector<vector<string>> ControlFlowClass::parseData(const vector<string>& lines) const
/*
Function Name: parseData
Function Purpose: This function parse the data from the file
*/
{
    // Declare Local Variables
    vector<vector<string>> parsedData;
    for (const auto& line : lines) {
        stringstream ss(line);
        string item;
        vector<string> household;

        // Parse the line by comma
        while (getline(ss, item, ',')) {
            household.push_back(item);
        }
        
        // Add the parsed data to the vector
        parsedData.push_back(household);
    }
    return parsedData;
}

void ControlFlowClass::displayTable(const vector<vector<string>>& data) const
/*
Function Name: displayTable
Function Purpose: This function displays the data to a table
*/
{
    // Display the message
    DisplayCensusDataMsg();

    // Declare Local Variables
    const size_t ownerDataSize = 13;
    const size_t otherMeberSize = 9;

    // Display the data
    for (const auto& household : data) {
        if (household.empty()) continue;

        // Print Household Owner Information
        cout << "\nHousehold Owner Information:\n";
        cout << "----------------------------------------\n";
        // Concatenate first and last names if available
        string fullName = (household.size() > 1) ? (household[0] + " " + household[1]) : (household.size() > 0 ? household[0] : "-");
        cout << "Name: " << fullName << endl;        
        cout << "Age: " << (household.size() > 2 ? household[2] : "-") << endl;
        cout << "Gender: " << (household.size() > 3 ? household[3] : "-") << endl;
        cout << "Marital Status: " << (household.size() > 4 ? household[4] : "-") << endl;
        cout << "Ethnicity: " << (household.size() > 5 ? household[5] : "-") << endl;
        cout << "Occupation: " << (household.size() > 6 ? household[6] : "-") << endl;
        cout << "Education Level: " << (household.size() > 7 ? household[7] : "-") << endl;
        cout << "Address: " << (household.size() > ownerDataSize - 6 ? household[household.size() - 6] : "-") << endl;
        cout << "Ownership Status: " << (household.size() > ownerDataSize - 5 ? household[household.size() - 5] : "-") << endl;
        cout << "Gross Income: " << (household.size() > ownerDataSize - 4 ? household[household.size() - 4] : "-") << endl;
        cout << "Employment Status: " << (household.size() > ownerDataSize - 3 ? household[household.size() - 3] : "-") << endl;
        cout << "Geographic Location: " << (household.size() > ownerDataSize - 2 ? household[household.size() - 2] : "-") << endl;
        cout << "Urban Location: " << (household.size() > ownerDataSize - 1 ? household[household.size() - 1] : "-") << endl;
        cout << endl;

        // Check for other members
        if (household.size() > ownerDataSize) {
            cout << "\tOther Household Members:\n";
            cout << "\t----------------------------------------\n";
            // Start at 9 and increment by personDataSize for each person
            for (size_t i = otherMeberSize; i <= household.size() - otherMeberSize; i += otherMeberSize) {
                // Concatenate names for other household members
                string memberName = (i + 1 < household.size()) ? (household[i] + " " + household[i + 1]) : (i < household.size() ? household[i] : "-");
                cout << "\tName: " << memberName << endl;
                cout << "\tAge: " << (i + 2 < household.size() ? household[i + 2] : "-") << endl;
                cout << "\tGender: " << (i + 3 < household.size() ? household[i + 3] : "-") << endl;
                cout << "\tMarital Status: " << (i + 4 < household.size() ? household[i + 4] : "-") << endl;
                cout << "\tEthnicity: " << (i + 5 < household.size() ? household[i + 5] : "-") << endl;
                cout << "\tOccupation: " << (i + 6 < household.size() ? household[i + 6] : "-") << endl;
                cout << "\tEducation Level: " << (i + 7 < household.size() ? household[i + 7] : "-") << endl;                
                cout << endl;
            }
        }
    }
}

void ControlFlowClass::displayCensusData(const string& filename) const
/*
Function Name: displayCensusData
Function Purpose: This function displays the data 
*/
{
    // Declare Local Variables
    auto data = readFileContents(filename);

    // Display the data;
    displayTable(data);  
}

string ControlFlowClass::getCurrentWorkingDirectory() const 
/*
Function Name: getCurrentWorkingDirectory
Function Purpose: This function is to get the current working directory
*/
{
    // Declare Local Variables
    char buffer[FILENAME_MAX];

    #ifdef _WIN32
        if (_getcwd(buffer, sizeof(buffer)) != -1) {
            // On Windows, use _getcwd to get the current working directory
            // Check if _getcwd succeeds (returns -1 on failure)
            return string(buffer);
        }
    #else
        if (getcwd(buffer, sizeof(buffer)) != nullptr) {
            // On Unix-like systems, use getcwd to get the current working directory
            // Check if getcwd succeeds (returns nullptr on failure)
            return string(buffer);
        }
    #endif

    // Return an empty string if the cwd could not be determined
    return string();
}

void ControlFlowClass::Generate_CensusReport() 
/*
Function Name: Generate_CensusReport
Function Purpose: This function is to get the econmics information
*/
{
    // Display the message
    ClearScreen();

    // Create a single CensusData object
    CensusData censusData;

    try {
        // Delcare Local Variables
        string fName = censusData.Get_CensusData_File();

        // Get the cwd
        string cwd = getCurrentWorkingDirectory();

        // Ensure there's a trailing slash (or backslash on Windows)
        #if defined(_WIN32) || defined(_WIN64)
            char separator = '\\';
        #else
            char separator = '/';
        #endif

        // Check if the cwd is empty
        if (cwd.back() != separator) {
            cwd += separator;
        }

        // Concatenate the file name with the cwd
        string fullPath = cwd + fName;

        // Use fullPath to display the data
        displayCensusData(fullPath);
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Ask user if they want to return to dashboard
    cout << "Do you want to return to the dashboard? (y/n): ";
    char response;
    cin >> response;

    // Check if the response is not yes
    if (response != 'y' && response != 'Y') {
        LoginMenu();
    }
    // Return to the main dashboard
    Main_Dashboard();      
}

void ControlFlowClass::ExitProgram() 
/*
Function Name: exitProgram
Function Purpose: This function is to exit the program
*/
{
    exit(0);
}
