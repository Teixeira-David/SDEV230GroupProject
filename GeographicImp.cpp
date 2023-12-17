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
    : intRurality(0), strRurality(""), strState("") {}

// Constructor with parameters
geographicClass::geographicClass(int rurality, string ruralityString, string state)
    : intRurality(rurality), strRurality(ruralityString), strState(state) {}

// Enter Geo inputs function


// setter functions
void geographicClass::set_Rurality() {
    int intInput;
    bool valid = false;
    
    while (!(valid)) {
        cout << "\nEnter 1 for Rural, 2 for Urban, 3 for Suburban: ";
        cin >> intInput;

        // Check if input is valid // (Author: David Teixeira)
        if (intInput == 1 || intInput == 2 || intInput == 3) {
            valid = true;
            switch(intInput) { // Added this switch to make the int a string var after selection
            case 1:
                strRurality = "Rural"; break;
            case 2:
                strRurality = "Urban"; break;
            case 3: 
                strRurality = "Suburban"; break;
            default:
                strRurality = "No Rurality recorded";
                break;
            }
        } 
        else {
            cout << "\nError: Invalid input. Please enter 1, 2, or 3.";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }
}

void geographicClass::set_State() {
    // string strInput;
    // cout << "\nPlease enter the state, territory, embassy, or U.S. base where you reside : ";
    // cin >> strInput; // with how open ended this is, there is no real plausible way to have validation
    // strState = strInput;
    string strInput;

    while (true) {
        cout << "\nPlease enter the state, territory, embassy, or U.S. base where you reside: ";
        if (!(cin >> strInput)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error reading input. Please try again.\n";
            continue;
        }

        // Check if input contains any digits
        if (any_of(strInput.begin(), strInput.end(), ::isdigit)) {
            cout << "State name should not contain numbers. Please try again.\n";
            continue;
        }

        // If input is valid, set it and break the loop
        strState = strInput;
        break;
    }
}    


void geographicClass::menu_Swith_Control() {
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
}

// getter functions

// returns the variables function
string geographicClass::get_State() const{
    string dState = strState;
    return dState;
}

// returns the variables function
int geographicClass::get_Rurality() const{
    int dRurality = intRurality;
    return dRurality;
}

// Method Purpose: Get the custom gender
string geographicClass::get_Rurality_String() const 
{
    return strRurality;
}

// print functions
void geographicClass::print_State() {
    if (strState == "") {
        cout << "\nNo state recorded.";
    }
    else {
        cout << "\nState is: " << strState;
    }
}

void geographicClass::print_Rurality() {
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
}

void geographicClass::print_Rurality_String() {
    if (strRurality == "") {
        cout << "\nNo Rurality recorded.";
    } else {
        cout << "\nRurality is: " << strRurality;
    }
}

void geographicClass::display_Geo_Menu() {
    cout << "\n\n---------------------------------------------------------------------------------------";
    cout << "\n\t\t\tPlease select from the menu options " << endl;
    cout << "---------------------------------------------------------------------------------------";
    cout << "\n1.) Enter state";
    cout << "\n2.) Enter Rurality"; // not sure what word to use?
    cout << "\n3.) Display House hold Rurality";
    cout << "\n4.) Display House hold state";
    cout << "\n9.) Exit program";
}

void geographicClass::enterGeographicDetails() 
/*
Function Name: enterGeographicDetails
Function Purpose: This function is to get all the inputs required for each Geographic
*/
{
    // Call the existing setter methods for each attribute
    set_Rurality();
    set_State();
}
    
geographicClass** geographicClass::allocGeographics() 
/*
Function Name: allocGeographics
Function Purpose: This function is to allocate memory for each new Geographic entry and return the Geographic array 
object to user.
(Author: David Teixeira)
*/
{
    while (true) {
        // Create the null pointer
        geographicClass** m_aGeographics = nullptr;
        try {
            // Create the pointer array set to the maximum number of people in the Geographic
            m_aGeographics = new geographicClass*[m_intMaxGeographicCount];

            // Allocate memory for the Geographic objects
            for (int i = 0; i < m_intMaxGeographicCount; i++) {
                m_aGeographics[i] = new geographicClass();
                // m_aGeographics[i]->enterGeographicDetails();
            }
            // Return the array of pointers. This return object must be paired with the destroy function 
            return m_aGeographics;
        } catch (const std::bad_alloc& e) {
            // Handle memory allocation failure
            cout << "Memory allocation failed: " << e.what() << endl;
            // Deallocate memory allocated so far
            for (int i = 0; i < m_intMaxGeographicCount; i++) {
                delete m_aGeographics[i];
            }
            delete[] m_aGeographics;
            return nullptr;
        } catch (const std::exception& e) {
            // Handle other exceptions
            cout << "An error occurred: " << e.what() << endl;
            // Deallocate memory allocated so far
            for (int i = 0; i < m_intMaxGeographicCount; i++) {
                delete m_aGeographics[i];
            }
            delete[] m_aGeographics;
            return nullptr;
        }
    }
}

void geographicClass::deallocGeographics(geographicClass** aGeographics, int intSize) 
/*
Function Name: deallocGeographics
Function Purpose: This function is to de-allocate memory for each new Geographic entry and return the Geographic array 
object to user.
(Author: David Teixeira)
*/
{
    if (aGeographics != nullptr) {
        for (int i = 0; i < intSize; i++) {
            delete aGeographics[i];
        }
        delete[] aGeographics;
    }
}

// Method Purpose: Get the member (Author: David Teixeira)
int geographicClass::getMaxGeographicCount() const 
{
    return m_intMaxGeographicCount;
}

// Method to format for file (Author: David Teixeira)
string geographicClass::formatForFile() const 
{
    // Declare Local Variables
    stringstream ss;

    // Concatenate member variables into a string
    ss << get_State() << ", "
       << get_Rurality_String();

    // Return the concatenated string
    return ss.str();   
}