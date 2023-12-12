// Economics.h

#ifndef Economics_H
#define Economics_H

#include <iostream>
#include <string>

class Economics {
public:
    // Function to get the user's gross income
    double getGrossIncome() const;

    // Function to get the user's employment status
    std::string getEmploymentStatus() const;

private:
    // Helper function to validate numeric input
    double getNumericInput(const std::string& prompt) const;
};

#endif // Economics_H
