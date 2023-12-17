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

int main() 
/*
Function Name: main
Function Purpose: This is the main function where the program starts
*/  
{
    try {
         // Create an instance of ControlFlowClass
        ControlFlowClass controlFlow;
        controlFlow.ClearScreen(); 
        controlFlow.LoginMenu();

        return 0; // End of the program

    } catch (const exception& e) {
        cout << "An error occurred in the application: " << e.what() << endl;
        return 1;
    }
}