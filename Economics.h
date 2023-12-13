// Economics.h

#ifndef Economics_H
#define Economics_H

#include <iostream>
#include <fstream>
#include <string>

class Economics {
public:
    // Function to get the user's gross income
    void setGrossIncome();

    // Function to get the user's employment status
    void setEmploymentStatus();

    // Function to display user information
    void displayEconomics() const;

    //Function to save user information to a text file
    void saveToFile(const std::string& filename) const;

private:
    double grossIncome;
    std::string employmentStatus;
    
    // Helper function to validate numeric input
    double getNumericInput(const std::string& prompt) const;
};

#endif // Economics_H
