#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 


// Econcomic class
class economicClass {
public:
    double grossIncome; // User enters their yearly Gross Income
    int employStatus; // Have user enter their current employment status. Part-time, Full-time, or unemployed
    
    // Default constructor
    economicClass() {}

    // Constructor parameters
    economicClass(double grossIncome, int employStatus)
        : doublegrossIncome(grossIncome), intemploystatus(employStatus), {}

        // Gets the users employment status
        void get_Employment_Status() {
        int input;
        cout << "\n Enter 1 for Full-time, 2 for Part-time, 3 for Unemployed: ";
        cin >> input;
    };

    // Gets the Users gross income
    void get_Gross_Income() {
        double input;
        cout << "\n Please enter your yearly gross income : ";
        cin >> input;
    };

};
