#include <iostream>
#include <string>

// Variables
string name;
string dob;
string gender;
string marital;
string ethnicity;
string occupation;
string education;
string address;
string relationship;
string residence;
string ownership;

int main() {
    // Print "Hello, World!" to the console
    std::cout << "Hello, World!" << std::endl;

    // Inputs
    // 1st catergory Personal Demographics
    std::cout << "Personal Demographics:" << std::endl; // personal demographics start here
    std::cout << "Enter your full name: " << std::endl;
    std::cin >> name;
    std::cout << "Enter DOB mm/dd/yyyy: " << std::endl;
    std::cin >> dob;
    std::cout << "Enter your gender: " << std::endl;
    std::cin >> gender;
    std::cout << "Enter your marital status: " << std::endl;
    std::cin >> marital;
    std::cout << "Enter your ethnicity: " << std::endl;
    std::cin >> ethnicity;
    std::cout << "Enter your occupation: " << std::endl;
    std::cin >> occupation;
    std::cout << "Enter your education level: " << std::endl;
    std::cin >> education; // personal demographics end here

    // 2nd catergory Household
    std::cout << "Household:" << std::endl;
    std::cout << "Enter your Address: " << std::endl;
    std::cin >> address;
    std::cout << "Enter your relationship to head of house hold: " << std::endl;
    std::cin >> relationship;
    std::cout << "Enter your type of residence: " << std::endl;
    std::cin >> residence;
    std::cout << "Are you a land owner?: " << std::endl;
    std::cin >> ownership;

    // 3rd catergory Economic
    std::cout << "Economic Status:" << std::endl;

    // 4th catergory Geographical
    std::cout << "Geographical:" << std::endl;

    // 5th catergory User Demographics
    std::cout << "User Demographics:" << std::endl;
    return 0;
}