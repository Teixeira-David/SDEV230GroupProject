// ----------------------------------------------------------------
// Author: David Teixeira 
// Project: Group Final Project
// Course: SDEV-230
// Creation Date: 12/10/2023
// ----------------------------------------------------------------

// Check preprocessor macro for definition
#ifndef H_ControlFlowClass
#define H_ControlFlowClass

// Import the Preprocessor Directives
#include <iostream>
#include <string>
#include "CensusData.h"

// Provide scope to identifiers inside the standard library
using namespace std;

// Create the constants

// Place the enumeration class for ControlFlow classification

// Delcare Classes
class ControlFlowClass
/*
Class Name: ControlFlowClass
Class Purpose: This is the ControlFlowClass class
*/
{
    // Delcare the pulic user functions
    public:
        // Create the default constructor
        ControlFlowClass();

        // Constructor with parameters

        // Setter Functions
        // void Set_LoginCred();
        // void Set_CensusReport();
        void Set_All_Requirements();
        void Set_Households_Info(CensusData& censusData);
        void Set_Persons_Info(CensusData& censusData);
        void Set_Economics_Info(CensusData& censusData);
        void Set_Geographics_Info(CensusData& censusData);

        // Getter Functions
        string Get_EmployeeData_File() const;
        string getCurrentWorkingDirectory() const;
        
        // Execution memory methods

        // Display methods 
        void ClearScreen();
        void DisplayStartUpMsg();
        void DisplayLoginMsg();
        void Display_DashBoardMenu();
        void Display_HouseHolds_Msg();
        void Display_Persons_Msg();
        void Display_Economics_Msg();
        void Display_Geographics_Msg();
        void Display_UserDemos_Msg();    
        void LoginMenu();
        void Main_Dashboard();
        void Generate_CensusReport();
        void ExitProgram();

        // Functions to print member information
        void displayTable(const vector<vector<string>>& data) const;
        void displayCensusData(const string& fileName) const;

        // Format for file dump
        string FormatCensusDataForFile() const;
        void WriteCensusDataToFile(const string& fileName) const;
        vector<string> readFileContents(const string& fileName) const;
        vector<vector<string>> parseData(const vector<string>& lines) const;

    // Delcare the private class members 'm_' -> member var indicator
    private:
        // Store memory information
        vector<CensusData> m_aCensusData;
        
        // Set the members
        string m_fEmployeeDataFile = "employee.txt";

        // Enumeration Types

};

#endif