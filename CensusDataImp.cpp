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


string CensusData::Get_CensusData_File() const
{
    return m_fCensusDataFile;
}
