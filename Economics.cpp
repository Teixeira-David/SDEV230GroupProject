// Author: Nicholas Moffitt
// Project: CensusHub Group Final Project
// Course: SDEV-230

// Economics class Implementation file

// Economics.cpp

// Include the header for the class
#include "Economics.h"

// Constructors with parameters
// function to set the users yearly income
void Economics::setGrossIncome() {
    grossIncome = getNumericInput("Enter your gross income: ");
}
// Function to set employment status
void Economics::setEmploymentStatus() {
    std::cout << "Enter your employment status (e.g., Full-time, Part-time, unemployed, self-employed): ";
    std::getline(std::cin, employmentStatus);
}
// function to display the users employment status and yearly income
void Economics::displayEconomics() const {
    std::cout << "Gross Income: $" << grossIncome << std::endl;
    std::cout << "Employment Status: " << employmentStatus << std::endl;
}
//function to put the users employment status and gross income into a text file
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
// clears the users input for the next user
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
