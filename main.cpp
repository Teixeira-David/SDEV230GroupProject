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

int main() {
    // Print "Hello, World!" to the console
    std::cout << "Hello, World!" << std::endl;

    // Inputs
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
// will continue with the other 4 catagories below, my hands are cramping
    return 0;
}
