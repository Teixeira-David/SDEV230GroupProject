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
#include "PersonClass.h"
#include "Household.h"
#include "Economics.h"
#include "GeographicClass.h"

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
        CensusData() : m_fCensusDataFile("censusData.txt") {}

        // Constructor with parameters 
        CensusData(const PersonClass& personData);
        CensusData(const Household& householdData);
        CensusData(const Economics& economicData);
        CensusData(const geographicClass& geographicData);
            
        // Setter Functions

        // Getter Functions
        string Get_CensusData_File() const;
        vector<CensusData> Get_Census_Data() const;

        // Execution memory methods

        // Functions to print member information

        // Format for file dump
        string formatForFile() const;

    // Delcare the private class members 'm_' -> member var indicator
    private:
        // Store memory information
        vector<CensusData> m_aCensusData;

        // Set the members
        string m_fCensusDataFile = "censusData.txt";
        PersonClass person;
        Household household;
        Economics economic;
        geographicClass geographic;

        // Enumeration Types

};

#endif