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
        int intInput;
        bool valid = false;
            while(!(valid)) {
                cout << "\n Enter 1 for Full-time, 2 for Part-time, 3 for self-employed, 4 for unemployed: ";
                cin >> intInput;

                if(inInput == 4 || intInput == 3 || intInput == 2 || intInput == 1){
                    valid = true;
                    intEmployStatus = intInput;
                }
                else{
                    cout << "\nError: Invalid input. Please use the 1, 2, 3, or 4 number keys.";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
    };

    // Gets the Users gross income
    void get_Gross_Income() {
        double input;
        cout << "\n Please enter your yearly gross income : ";
        cin >> input;
    };

    void display_employStatus() {
        string strOutput
        switch(intEmployStatus)
            case 1:
                strOutput = "Full-time";
                cout << "\nEmployStatus is: " << strOutput;
                break;
       
            case 2:
                strOutput = "Part-time";
                cout << "\nEmployStatus is: " << strOutput;
                break;

            case 3:
                strOutput = "Self-Employed";
                cout << "\nEmployStatus is: " << strOutput;
                break;

            case 4:
                strOutput = "Unemployed";
                cout << "\nEmployStatus is: " << strOutput;
                break;
    }
};
