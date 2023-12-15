// Economics.h

#ifndef Economics_H
#define Economics_H

#include <iostream>
#include <fstream>
#include <string>

class Economics {
public:
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
    int getMaxEconomicCount() const;
    double getGrossIncome() const;
    std::string getEmploymentStatus() const;

    // Format for file dump
    std::string formatForFile() const;

private:
    // Store memory information
    // Economics** m_aEconomics;
    int m_intMaxEconomicCount = 1;

    double grossIncome;
    std::string employmentStatus;
    
    // Helper function to validate numeric input
    double getNumericInput(const std::string& prompt);
    // double getNumericInput(const std::string& prompt) const;
};

#endif // Economics_H
