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
        void Set_LoginCred();
        void Set_CensusReport();
        vector<CensusData> Set_All_Requirements();
        vector<CensusData> Set_Households_Info();
        vector<CensusData> Set_Persons_Info();
        vector<CensusData> Set_Economics_Info();
        vector<CensusData> Set_Geographics_Info();

        // Getter Functions
        string Get_EmployeeData_File() const;
        
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


    // Delcare the private class members 'm_' -> member var indicator
    private:
        // Store memory information
        vector<CensusData> m_aCensusData;

        // Set the members
        string m_fEmployeeDataFile = "employee.txt";

        // Enumeration Types

};

#endif