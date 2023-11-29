// ----------------------------------------------------------------
// Author: David Teixeira 
// Project: Group Final Project
// Course: SDEV-230
// Creation Date: 11/16/2023
// ----------------------------------------------------------------

// Import the Preprocessor Directives
#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include <iomanip>
#include <set>

// Provide scope to identifiers inside the standard library
using namespace std;

// Create the constants

// Delcare Classes
class PersonClass : public
/*
Class Name: PersonClass
Class Purpose: This is the PersonClass class
*/
{
    // Delcare the pulic user functions
    public:
        // Create the default constructor
        PersonClass() {}

        // Constructor with parameters
        PersonClass(string firstName, string lastName, int age, string gender, string maritalStatus, string ethnicity, string occupation, string educateLevel)
            : strFirstName(firstName), strLastName(lastName), intAge(age), strGender(gender), strMaritalStatus(maritalStatus), strEthnicity(ethnicity), 
            strOccupation(occupation), strEducationLevel(educateLevel) {}

        void Get_Person_Name()
        /*
        Function Name: Get_Person_Name
        Function Purpose: This function is to gets the name of the person
        */
        {
            // Delcare Local Variables
            string strInput = "";

            // Get the user input
            for (int i = 0; i < 2; i++) {                
                while (true) { 
                    cout << "\n\nPlease enter the " << aNamesList[i] << " name of household member: ";
                    // Check if the input is valid
                    if (!(cin >> strInput)) {
                        cout << "Invalid input. Please an String: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        *aNameInputList[i] = strInput;
                        break;
                    }
                }
            }
        }

        void Get_Person_Age()
        /*
        Function Name: Get_Person_Age
        Function Purpose: This function is to gets the age of the person
        */
        {
            // Delcare Local Variables
            int intInput = 0;

            // Get the user input
            while (true) { 
                cout << "\n\nPlease enter the age of the household member: ";
                // Check if the input is valid
                if (!(cin >> intInput)) {
                    cout << "Invalid input. Please an String: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    intAge = intInput;
                    break;
                }
            }            
        }

        void Get_Person_Gender()
        /*
        Function Name: Get_Person_Gender
        Function Purpose: This function is to gets the gender of the person
        */
        {
            // Delcare Local Variables
            string strInput = "";

            // Get the user input                                      
            while (true) { 
                cout << "\n\nPlease enter the gender of the household member:";
                // Check if the input is valid
                if (!(cin >> strInput)) {
                    cout << "Invalid input. Please an String: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    strGender = strInput;
                    break;
                }
            }        
        }

        void Get_Person_MaritalStatus()
        /*
        Function Name: Get_Person_MaritalStatus
        Function Purpose: This function is to gets the marital status of the person
        */
        {
            // Delcare Local Variables
            string strInput = "";

            // Get the user input                          
            while (true) { 
                cout << "\n\nPlease enter the marital status of the household member:";
                // Check if the input is valid
                if (!(cin >> strInput)) {
                    cout << "Invalid input. Please an String: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    strMaritalStatus = strInput;
                    break;
                }
            }        
        }

        void Get_Person_Ethnicity()
        /*
        Function Name: Get_Person_Ethnicity
        Function Purpose: This function is to gets the ethnicity of the person
        */
        {
            // Delcare Local Variables
            string strInput = "";

            // Get the user input                          
            while (true) { 
                cout << "\n\nPlease enter the ethnicity of the household member:";
                // Check if the input is valid
                if (!(cin >> strInput)) {
                    cout << "Invalid input. Please an String: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    strEthnicity = strInput;
                    break;
                }
            }        
        }        

        void Get_Person_Occupation()
        /*
        Function Name: Get_Person_Occupation
        Function Purpose: This function is to gets the Occupation of the person
        */
        {
            // Delcare Local Variables
            string strInput = "";

            // Get the user input                          
            while (true) { 
                cout << "\n\nPlease enter the education level of the household member:";
                // Check if the input is valid
                if (!(cin >> strInput)) {
                    cout << "Invalid input. Please an String: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    strEthnicity = strInput;
                    break;
                }
            }        
        } 

        void Get_Person_EducateLevel()
        /*
        Function Name: Get_Person_EducateLevel
        Function Purpose: This function is to gets the education level of the person
        */
        {
            // Delcare Local Variables
            string strInput = "";

            // Get the user input                          
            while (true) { 
                cout << "\n\nPlease enter the education level of the household member:";
                // Check if the input is valid
                if (!(cin >> strInput)) {
                    cout << "Invalid input. Please an String: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    strEthnicity = strInput;
                    break;
                }
            }        
        } 

        void Display_Person_Menu()
        /*
        Function Name: Display_User_Menu
        Function Purpose: This function is the display function for the user menu
        */
        {
            cout << "\n\n---------------------------------------------------------------------------------------";
            cout << "\n\t\t\t Please select from the menu options " << endl;
            cout << "---------------------------------------------------------------------------------------";
            cout << "\n1.) Enter Person(s) First/Last Name";
            cout << "\n2.) Enter Person(s) Age";
            cout << "\n3.) Enter Person(s) Gender";
            cout << "\n4.) Enter Person(s) Marital Status";
            cout << "\n5.) Enter Person(s) Ethnicity";
            cout << "\n6.) Enter Person(s) Occupation";
            cout << "\n7.) Display House Hold Person(s) Demographics";
            cout << "\n8.) Display House Hold Person(s) Demographics";
            cout << "\n9.) Display House Hold Person(s) Demographics";
        } 

        void Menu_Person_Switch_Control()
        /*
        Function Name: Menu_Person_Switch_Control
        Function Purpose: This function is the primary switch control for the user's Person Demographics menue.
        */
        {
            // Delcaer Local Variables
            int intSelectionNum = 0;
            bool blnFlag = false;

            while (!(blnFlag)) {
                // Display the options
                Display_Person_Menu();

                // Get the user input for the menu selection 
                cout << "\n\n Please enter your choice here: ";
                cin >> intSelectionNum;

                // Use switch statement to find what the user would like to perform 
                switch (intSelectionNum) {
                    case 1:
                        
                        break;
                    case 2:
                        
                        break;
                    case 3:
                        
                        break;
                    case 4:
                        
                        break;
                    case 5:
                        
                        break;
                    case 6:
                        
                        break;
                    case 7:
                        
                        break;
                    case 8:

                        break;
                    case 9:
                        // Exit the program
                        blnFlag = true;
                        exit(0);
                        break;
                    default:
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n\nPlease select any number from the menu!" << endl;
                        break;
                }
            }
        }  

        void Display_Person_Age()
        /*
        Function Name: Display_User_Menu
        Function Purpose: This function is the display function for the age range menu
        */
        {
            cout << "\n\n---------------------------------------------------------------------------------------";
            cout << "\n\t\t\t Please select age range from the menu options " << endl;
            cout << "---------------------------------------------------------------------------------------";
            cout << "\n1.) Under 5 Years Old";
            cout << "\n2.) 5 to 9 Years Old";
            cout << "\n3.) 10 to 14 Years Old";
            cout << "\n4.) 15 to 19 Years Old";
            cout << "\n5.) 20 to 24 Years Old";
            cout << "\n6.) 25 to 29 Years Old";
            cout << "\n7.) 30 to 34 Years Old";
            cout << "\n8.) 40 to 44 Years Old";
            cout << "\n9.) 45 to 49 Years Old";
            cout << "\n10.) 50 to 54 Years Old";
            cout << "\n11.) 55 to 59 Years Old";
            cout << "\n12.) 60 to 64 Years Old";
            cout << "\n13.) 65 to 69 Years Old";
            cout << "\n14.) 70 to 74 Years Old";
            cout << "\n15.) 75 to 79 Years Old";
            cout << "\n16.) 80 to 84 Years Old";
            cout << "\n17.) 85 and over";
        } 

        void Menu_Person_Age_Switch_Control()
        /*
        Function Name: Menu_Person_Age_Switch_Control
        Function Purpose: This function is the primary switch control for the user's Person age range menue.
        */
        {
            // Delcaer Local Variables
            int intSelectionNum = 0;
            bool blnFlag = false;

            while (!(blnFlag)) {
                // Display the options
                Display_Person_Age();

                // Get the user input for the menu selection 
                cout << "\n\n Please enter your choice here: ";
                cin >> intSelectionNum;

                // Use switch statement to find what the user would like to perform 
                switch (intSelectionNum) {
                    case 1:
                        
                        break;
                    case 2:
                        
                        break;
                    case 3:
                        
                        break;
                    case 4:
                        
                        break;
                    case 5:
                        
                        break;
                    case 6:
                        
                        break;
                    case 7:
                        
                        break;
                    case 8:

                        break;
                    case 9:

                        break;
                    case 10:

                        break;
                    case 11:

                        break;
                    case 12:

                        break;
                    case 13:

                        break;
                    case 14:

                        break;
                    case 15:

                        break;
                    case 16:

                        break;                                                                                                                                                                                                
                    case 17:

                        break;
                    default:
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n\nPlease select any number from the menu!" << endl;
                        break;
                }
            }
        }  

        
    // Delcare the private class members    
    private:
        // Set the arrays
        string aNamesList[2] = {"First", "Last"};
        string* aNameInputList[2] = {&strFirstName, &strLastName};

        // Set the members
        string strFirstName = "";
        string strLastName = "";
        string strAge = "";
        string strGender = "";
        string strMaritalStatus = "";
        string strEthnicity = "";
        string strOccupation = "";
        string strEducationLevel = "";
};

