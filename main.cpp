// ----------------------------------------------------------------
// Author: David Teixeira 
// Project: Group Final Project
// Course: SDEV-230
// Creation Date: 12/10/2023
// ----------------------------------------------------------------

// Import the Preprocessor Directives
#include <iostream>
#include <string>

// Import header file for base class
#include "ControlFlowClass.h"

// Provide scope to identifiers inside the standard library
using namespace std;

// Create the constants

// Place the enumeration class for ControlFlow classification

int main() 
/*
Function Name: main
Function Purpose: This is the main function where the program starts
*/  
{
    try {
        
        ControlFlowClass controlFlow; // Create an instance of ControlFlowClass

        controlFlow.LoginMenu(); // Start the application with the login menu

        // Main_Dashboard is called at the end of LoginMenu function as per your implementation

        return 0; // End of the program

    } catch (const exception& e) {
        cout << "An error occurred in the application: " << e.what() << endl;
        return 1; // Return a non-zero value to indicate an error
    }
}