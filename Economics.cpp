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
