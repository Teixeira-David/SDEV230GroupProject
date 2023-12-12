// main.cpp

#include "Economics.h"

int main() {
    Economics user;

    user.setGrossIncome();
    user.setEmploymentStatus();

    // Display user information
    user.displayEconomics();

    return 0;
}
