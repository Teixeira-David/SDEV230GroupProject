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
#include "Geographic.h"

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

// getter functions


// print functions
