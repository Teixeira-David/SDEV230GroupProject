// ----------------------------------------------------------------
// Author: Nick Moffitt
// Project: Group Final Project
// Course: SDEV-230
// ----------------------------------------------------------------

// Economics.cpp

#include "Economics.h"
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <array>
#include <sstream>

// Class method implementations 
// Defualt Constructor (Co-edit: David Teixeira)
Economics::Economics() 
    : grossIncome(0.0),
      m_eEmploymentType(EmploymentType::OTHER) {}

// Constructor with parameters (Co-edit: David Teixeira)
Economics::Economics(double grossIncome, EmploymentType employmentStatus)
    : grossIncome(grossIncome),
      m_eEmploymentType(employmentStatus) {}

void Economics::setGrossIncome() {
    grossIncome = getNumericInput("Enter your gross income: ");
}

// void Economics::setEmploymentStatus() {
//     std::cout << "Enter your employment status (e.g., Full-time, Part-time, unemployed, self-employed): ";
//     std::getline(std::cin, employmentStatus);
// } Commented this out because it was replaced by the function below - (Co-edit: David Teixeira)

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

double Economics::getNumericInput(const std::string& prompt) {
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

// double Economics::getNumericInput(const std::string& prompt) const {
//     double value;
//     std::cout << prompt;
//     while (!(std::cin >> value)) {
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         std::cout << "Invalid input. Please enter a numeric value: ";
//     }
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
//     return value;
// } Commented this out because it was replaced by the function below - (Co-edit: David Teixeira)

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
(Author: David Teixeira)
*/
{
    // Call the existing setter methods for each attribute
    setGrossIncome();
    setEmploymentStatus();

    // Set the employment status
    employmentStatus = employmentTypeToString();
}
    
Economics** Economics::allocEconomics() 
/*
Function Name: allocEconomics
Function Purpose: This function is to allocate memory for each new Economics entry and return the Economics array 
object to user.
(Author: David Teixeira)
*/
{
    while (true) {
        // Create the null pointer
        Economics** m_aEconomics = nullptr;
        try {
            // Create the pointer array set to the maximum number of people in the Economics
            m_aEconomics = new Economics*[m_intMaxEconomicCount];

            // Allocate memory for the Economics objects
            for (int i = 0; i < m_intMaxEconomicCount; i++) {
                m_aEconomics[i] = new Economics();
                // m_aEconomics[i]->enterEconomicsDetails();
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
(Author: David Teixeira)
*/
{
    if (aEconomics != nullptr) {
        for (int i = 0; i < intSize; i++) {
            delete aEconomics[i];
        }
        delete[] aEconomics;
    }
}

// Method Purpose: Get the member (Author: David Teixeira)
int Economics::getMaxEconomicCount() const 
{
    return m_intMaxEconomicCount;
}

// Method to format for file (Author: David Teixeira)
std::string Economics::formatForFile() const 
{
    // Declare Local Variables
    std::stringstream ss;

    // Concatenate member variables into a string
    ss << getGrossIncome() << ", "
       << employmentTypeToString();

    // Return the concatenated string
    return ss.str();   
}

void Economics::setEmploymentStatus() {
/*
Function Name: setEmploymentStatus
Function Purpose: This function is to sets the employment status
(Author: David Teixeira)
*/    
    while (true) {
        try {
            // Declare Local Variables
            int choice;

            // Display the choices
            std::cout << "\n\nSelect the employment status:\n\n";
            std::cout << "1. Full Time\n";
            std::cout << "2. Part Time\n";
            std::cout << "3. Unemployed\n";
            std::cout << "4. Self Employed\n";
            std::cout << "5. Seasonal\n";
            std::cout << "6. Temporary\n";
            std::cout << "7. Contractor\n";
            std::cout << "8. Federal Medical Leave Assistance (FMLA)\n";
            std::cout << "9. Other\n";
            std::cout << "\n\nEnter your choice: ";
            
            // Get the input choice
            std::cin >> choice;            
            if (std::cin.fail() || choice < 1 || choice > 9) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::runtime_error("Invalid selection. Please enter a number between 1 and 9.");
            }

            switch (choice) {
                case 1: m_eEmploymentType = EmploymentType::FULL_TIME; break;
                case 2: m_eEmploymentType = EmploymentType::PART_TIME; break;
                case 3: m_eEmploymentType = EmploymentType::UNEMPLOYED; break;
                case 4: m_eEmploymentType = EmploymentType::SELF_EMPLOYED; break;
                case 5: m_eEmploymentType = EmploymentType::SEASONAL; break;
                case 6: m_eEmploymentType = EmploymentType::TEMP; break;
                case 7: m_eEmploymentType = EmploymentType::CONTRACTOR; break;
                case 8: m_eEmploymentType = EmploymentType::FMLA; break;
                case 11: 
                    m_eEmploymentType = EmploymentType::OTHER;
                    std::cout << "Enter custom employment type: ";
                    std::cin >> std::ws; // Consume any leading whitespace
                    getline(std::cin, m_strCustomEmploymentType); 
                    if (m_strCustomEmploymentType.empty()) {
                        throw std::runtime_error("Custom employment type cannot be empty.");
                    }
                    break;
                default:
                    throw std::runtime_error("Invalid selection.");
            }
            break;

        } catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what() << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\nPlease enter the custom employment type of household member: ";
        }
    }
} 

std::string Economics::employmentTypeToString() const 
/*
Function Name: employmentTypeToString
Function Purpose: This function converts the enum type to string
*/
{
    switch (m_eEmploymentType) {
        case EmploymentType::FULL_TIME: return "Full Time";
        case EmploymentType::PART_TIME: return "Part Time";
        case EmploymentType::UNEMPLOYED: return "Unemployed";
        case EmploymentType::SELF_EMPLOYED: return "Self Employed";
        case EmploymentType::SEASONAL: return "Seasonal";
        case EmploymentType::TEMP: return "Temporary";
        case EmploymentType::CONTRACTOR: return "Contractor";
        case EmploymentType::FMLA: return "Federal Medical Leave Assistance (FMLA)";
        case EmploymentType::OTHER: return "Other: " + m_strCustomEmploymentType;
        default: return "Unknown employment type";
    }
}