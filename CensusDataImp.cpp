// ----------------------------------------------------------------
// Author: David Teixeira 
// Project: Group Final Project
// Course: SDEV-230
// Creation Date: 12/10/2023
// ----------------------------------------------------------------

// Import the Preprocessor Directives
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <array>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <functional>

// Include the headers for class definition
#include "CensusData.h"

// Provide scope to identifiers inside the standard library
using namespace std;

// Class method implementations 
// Defualt Constructor

// Constructor with PersonClass object
CensusData::CensusData(const PersonClass& personData) : person(personData) {}

// Constructor with Household object
CensusData::CensusData(const Household& householdData) : household(householdData) {}

// Constructor with Household object
CensusData::CensusData(const Economics& economicData) : economic(economicData) {}

// Constructor with Household object
CensusData::CensusData(const geographicClass& geographicData) : geographic(geographicData) {}

// Method to format for file
string CensusData::formatForFile() const 
{
    // Declare Local Variables
    stringstream ss;

    // Format person data
    ss << person.formatForFile() << ", ";

    // Format household data
    ss << household.formatForFile() << ", ";

    // Format economic data
    ss << economic.formatForFile() << ", ";

    // Format geographic data
    ss << geographic.formatForFile();

    return ss.str();
}

// Method Purpose: Get the census data  
vector<CensusData> CensusData::Get_Census_Data() const
{
    return m_aCensusData;
}

// Method Purpose: Get the census data file 
string CensusData::Get_CensusData_File() const
{
    return m_fCensusDataFile;
}
