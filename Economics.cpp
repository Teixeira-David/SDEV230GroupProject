// Economics.cpp

#include "Economics.h"

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
