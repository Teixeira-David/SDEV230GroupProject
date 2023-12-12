// Geographic class Implementation file
/*  
Author: Lucas Landis
Date of creation: 12/9/2023 2:30PM
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include <iomanip>
#include <limits>
#include "GeographicClass.h"

using namespace std;

// Defualt Constructor
geographicClass::geographicClass()
    : intRurality(""), strState("") {}

// Constructor with parameters
geographicClass::geographicClass(int rurality, string state)
    : intRurality(rurality), strState(state) {}

// Enter Geo inputs function


// setter functions
void set_Rurality() {
    int intInput;
    bool valid = false;
    
    while (!(valid)) {
        cout << "\nEnter 1 for Rural, 2 for Urban, 3 for Suburban: ";
        cin >> intInput;

        // Check if input is valid
        if (intInput == 1 || intInput == 2 || intInput == 3) {
            valid = true;
            intRurality = intInput;
        } 
        else {
            cout << "\nError: Invalid input. Please enter 1, 2, or 3.";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

    }
};

void set_State() {
    string strInput;
    cout << "\nPlease enter the state, territory, embassy, or U.S. base where you reside : ";
    cin >> strInput; // with how open ended this is, there is no real plausible way to have validation
    strState = strInput;
};

void menu_Swith_Control() {
    // Local Variables
    int intSelectionNum = 0;
    bool blnFlag = false;
    while (!(blnFlag)) {
        // Display the options
        display_Geo_Menu();

        // Get the user input for the menu selection 
        cout << "\n\nPlease enter your choice here: ";
        cin >> intSelectionNum;

        // Use switch statement to find what the user would like to perform 
        switch (intSelectionNum) {
            case 1:
                set_State();
                break;
            
            case 2:
                set_Rurality();
                break;
                    
            case 3:
                print_Rurality();
                break;
                    
            case 4:
                print_State();
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
};

// getter functions


// print functions
void print_State() {
    if (strState == "") {
        cout << "No state recorded.";
    }
    else {
        cout << "\nState is: " << strState;
    }
};

void print_Rurality() {
    string strOutput;
    switch(intRurality) { // gives the answer in string so user can tell what the rurality truly is
        case 1:
            strOutput = "Rural";
            cout << "\nRurality is: " << strOutput;
            break;
                
            case 2:
                strOutput = "Urban";
                cout << "\nRurality is: " << strOutput;
                break;

            case 3: 
                strOutput = "Suburban";
                cout << "\nRurality is: " << strOutput;
                break;

            default:
                cout << "\nNo Rurality recorded.";
                break;
        }
};

void display_Geo_Menu() {
    cout << "\n\n---------------------------------------------------------------------------------------";
    cout << "\n\t\t\t Please select from the menu options " << endl;
    cout << "---------------------------------------------------------------------------------------";
    cout << "\n1.) Enter state";
    cout << "\n2.) Enter Rurality"; // not sure what word to use?
    cout << "\n3.) Display House hold Rurality";
    cout << "\n4.) Display House hold state";
    cout << "\n9.) Exit program";
};
