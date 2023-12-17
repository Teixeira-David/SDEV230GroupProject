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
#include <vector>

// Include the headers for class definition
#include "CensusData.h"


// Provide scope to identifiers inside the standard library
using namespace std;

// Class method implementations 
// Defualt Constructor

// Constructor with PersonClass object
// CensusData::CensusData(const PersonClass& personData) : person(personData) {}
CensusData::CensusData(const vector<PersonClass>& personsData) : m_aPersonsData(personsData) {}

// Constructor with Household object
CensusData::CensusData(const Household& householdData) : household(householdData) {}

// Constructor with Household object
CensusData::CensusData(const Economics& economicData) : economic(economicData) {}

// Constructor with Household object
CensusData::CensusData(const geographicClass& geographicData) : geographic(geographicData) {}

// Setter for PersonClass
void CensusData::setPerson(const PersonClass& personData) {
    person = personData;
}

// Setter for Household
void CensusData::setHousehold(const Household& householdData) {
    household = householdData;
}

// Setter for Economics
void CensusData::setEconomics(const Economics& economicData) {
    economic = economicData;
}

// Setter for geographicClass
void CensusData::setGeographic(const geographicClass& geographicData) {
    geographic = geographicData;
}

// Method to format for file
string CensusData::formatForFile() const 
{
    // Declare Local Variables
    stringstream ss;

    // Format data for each person in m_aPersonsData
    for (const auto& person : m_aPersonsData) {
        ss << person.formatForFile() << ", ";
    }

    // Remove the trailing comma and space if persons data is not empty
    if (!m_aPersonsData.empty()) {
        ss.seekp(-2, ios_base::end); // Go back two characters
        ss << ' '; // Replace the last comma with a space
    }
    
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

// Method to add a person to the census data
void CensusData::addPerson(const PersonClass& person) {
    m_aPersonsData.push_back(person);
}

// Method to add a person to the census data
const vector<PersonClass>& CensusData::getPersonsData() const
{
    return m_aPersonsData;
}