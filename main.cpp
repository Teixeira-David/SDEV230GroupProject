// main.cpp

#include "Economics.h"

int main() {
    Economics user;

    user.setGrossIncome();
    user.setEmploymentStatus();

    // Display user information
    user.displayEconomics();

    // Save user information to a text file
    user.saveToFile("Economics_info.txt");

    return 0;
}
