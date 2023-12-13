// ----------------------------------------------------------------
// Author: David Teixeira 
// Project: Group Final Project
// Course: SDEV-230
// Creation Date: 12/10/2023
// ----------------------------------------------------------------

// Check preprocessor macro for definition
#ifndef H_CensusDataClass
#define H_CensusDataClass

// Import the Preprocessor Directives
#include <iostream>
#include <string>

// Provide scope to identifiers inside the standard library
using namespace std;

// Create the constants

// Delcare Classes
class CensusData
/*
Class Name: CensusData
Class Purpose: This is the CensusData class
*/
{
    // Delcare the pulic user functions
    public:
        // Create the default constructor
        CensusData();

        // Constructor with parameters

        // Setter Functions

        // Getter Functions
        string Get_CensusData_File() const;
        
        // Execution memory methods

        // Display methods 

        // Functions to print member information

    // Delcare the private class members 'm_' -> member var indicator
    private:
        // Store memory information
        vector<CensusData> m_aCensusData;

        // Set the members
        string m_fCensusDataFile = "censusData.txt";

        // Enumeration Types

};

#endif