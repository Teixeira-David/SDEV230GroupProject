// Economics.cpp

#include "Economics.h"

double Economics::getGrossIncome() const {
    return getNumericInput("Enter your gross income: ");
}

std::string Economics::getEmploymentStatus() const {
    std::cout << "Enter your employment status (e.g., Full-time, Part-time, unemployed, self-employed): ";
    std::string status;
    std::getline(std::cin, status);
    return status;
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
