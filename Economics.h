// Economics.h

#ifndef Economics_H
#define Economics_H

#include <iostream>
#include <string>

class Economics {
public:
    // Function to get the user's gross income
    void setGrossIncome();

    // Function to get the user's employment status
    void setEmploymentStatus();

    // Function to display user information
    void displayEconomics() const;

private:
    double grossIncome;
    std::string employmentStatus;
    
    // Helper function to validate numeric input
    double getNumericInput(const std::string& prompt) const;
};

#endif // Economics_H
