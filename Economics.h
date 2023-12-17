// ----------------------------------------------------------------
// Author: Nick Moffitt
// Project: Group Final Project
// Course: SDEV-230
// ----------------------------------------------------------------

// Economics.h

#ifndef Economics_H
#define Economics_H

#include <iostream>
#include <fstream>
#include <string>

// Place the enumeration class for household classification 
// add to make sure we have options for relationships to owner
enum class EmploymentType{FULL_TIME, PART_TIME, UNEMPLOYED, SELF_EMPLOYED, SEASONAL, 
                TEMP, CONTRACTOR, FMLA, OTHER}; 

class Economics {
public:
    // Constructors 
    Economics();
    Economics(double grossIncome, EmploymentType employmentStatus);

    // Execution memory methods 
    Economics** allocEconomics();
    void deallocEconomics(Economics** aEconomics, int intSize);

    // Setters 
    void enterEconomicsDetails();

    // Function to get the user's gross income
    void setGrossIncome();

    // Function to get the user's employment status
    void setEmploymentStatus();

    // Function to display user information
    void displayEconomics() const;

    //Function to save user information to a text file
    void saveToFile(const std::string& filename) const;

    // Getters 
    int getMaxEconomicCount() const; // 
    double getGrossIncome() const;
    std::string getEmploymentStatus() const;

    // Format for file dump
    std::string formatForFile() const;

    // Enum to string
    std::string employmentTypeToString() const;

private:
    // Store memory information
    // Economics** m_aEconomics; 
    int m_intMaxEconomicCount = 1;

    double grossIncome;
    std::string employmentStatus;

    // Add the custom member 
    std::string m_strCustomEmploymentType;
    
    // Helper function to validate numeric input
    double getNumericInput(const std::string& prompt);
    // double getNumericInput(const std::string& prompt) const;

    // Enumeration Types 
    EmploymentType m_eEmploymentType;
};

#endif // Economics_H
