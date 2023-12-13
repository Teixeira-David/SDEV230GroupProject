// Economics.cpp

#include "Economics.h"
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <array>
#include <sstream>

void Economics::setGrossIncome() {
    grossIncome = getNumericInput("Enter your gross income: ");
}

void Economics::setEmploymentStatus() {
    std::cout << "Enter your employment status (e.g., Full-time, Part-time, unemployed, self-employed): ";
    std::getline(std::cin, employmentStatus);
}

void Economics::displayEconomics() const {
    std::cout << "Gross Income: $" << grossIncome << std::endl;
    std::cout << "Employment Status: " << employmentStatus << std::endl;
}

void Economics::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << "Gross Icome: $" << grossIncome << std::endl;
        outFile << "Employment Status: " << employmentStatus << std::endl;
        outFile.close();
        std::cout << "User economic information saved to " << filename << std::endl;
    }
    else {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}

double Economics::getNumericInput(const std::string& prompt) const {
    double value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a numeric value: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
    return value;
}

// Method Purpose: Get the gross income
double Economics::getGrossIncome() const 
{
    return grossIncome;
}

// Method Purpose: Get the employment status
std::string Economics::getEmploymentStatus() const 
{
    return employmentStatus;
}

void Economics::enterEconomicsDetails() 
/*
Function Name: enterEconomicsDetails
Function Purpose: This function is to get all the inputs required for each Economics
*/
{
    // Call the existing setter methods for each attribute
    setGrossIncome();
    setEmploymentStatus();
}
    
Economics** Economics::allocEconomics() 
/*
Function Name: allocEconomics
Function Purpose: This function is to allocate memory for each new Economics entry and return the Economics array 
object to user.
*/
{
    while (true) {
        // Delcare Local Variables
        int m_intMaxEconomicCount = 0;
        
        // Create the null pointer
        Economics** m_aEconomics = nullptr;
        try {
            // Create the pointer array set to the maximum number of people in the Economics
            m_aEconomics = new Economics*[m_intMaxEconomicCount];

            // Allocate memory for the Economics objects
            for (int i = 0; i < m_intMaxEconomicCount; i++) {
                m_aEconomics[i] = new Economics();
                m_aEconomics[i]->enterEconomicsDetails();
            }
            // Return the array of pointers. This return object must be paired with the destroy function 
            return m_aEconomics;
        } catch (const std::bad_alloc& e) {
            // Handle memory allocation failure
            std::cout << "Memory allocation failed: " << e.what() << std::endl;
            // Deallocate memory allocated so far
            for (int i = 0; i < m_intMaxEconomicCount; i++) {
                delete m_aEconomics[i];
            }
            delete[] m_aEconomics;
            return nullptr;
        } catch (const std::exception& e) {
            // Handle other exceptions
            std::cout << "An error occurred: " << e.what() << std::endl;
            // Deallocate memory allocated so far
            for (int i = 0; i < m_intMaxEconomicCount; i++) {
                delete m_aEconomics[i];
            }
            delete[] m_aEconomics;
            return nullptr;
        }
    }
}

void Economics::deallocEconomics(Economics** aEconomics, int intSize) 
/*
Function Name: deallocEconomics
Function Purpose: This function is to de-allocate memory for each new Economics entry and return the Economics array 
object to user.
*/
{
    if (aEconomics != nullptr) {
        for (int i = 0; i < intSize; i++) {
            delete aEconomics[i];
        }
        delete[] aEconomics;
    }
}

// Method Purpose: Get the member
int Economics::getMaxEconomicCount() const 
{
    return m_intMaxEconomicCount;
}

// Method to format for file
std::string Economics::formatForFile() const 
{
    // Declare Local Variables
    std::stringstream ss;

    // Concatenate member variables into a string
    ss << getGrossIncome() << ", "
       << getEmploymentStatus();

    // Return the concatenated string
    return ss.str();   
}