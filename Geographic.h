/*
Author: Lucas Landis
Date of creation: 11/28/2023 7:20PM
Date of last update: 12/08/2023 7:46PM

*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include <iomanip>
#include <limits>

using namespace std;

// Geographic class
class geographicClass {
    public: 
        string state; // state, territory, embassy, or base
        int rurality; // rural, Urban, or suburban
        
        // Default constructor
        geographicClass() {}

        // Constructor parameters
        geographicClass(int rurality, string state)
            : intRurality(rurality), strState(state) {}

        // Gets the Rural, Urban, or suburban / rurality
        void get_Rurality() {
        int intInput;
        bool valid = false;

        while (!(valid)) {
            cout << "\nEnter 1 for Rural, 2 for Urban, 3 for Suburban: ";
            cin >> intInput;

            // Check if input is valid
            if (intInput == 1 || intInput == 2 || intInput == 3) {
                valid = true;
                intRurality = intInput;
            } 
            else {
                cout << "\nError: Invalid input. Please enter 1, 2, or 3.";
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            }

        }
        };

        // Gets the state/territory
        void get_State() {
            string strInput;
            cout << "\nPlease enter the state, territory, embassy, or U.S. base where you reside : ";
            cin >> strInput;
            strState = strInput;
        };

        // This displays the state or territory
        void display_State() {
            cout << "\nState is: " << strState;
        };
        // This displays the Rurality
        void display_Rurality() {
            string strOutput;
            switch(intRurality) { // gives the answer in string so user can tell what the rurality truly is
                case 1:
                    strOutput = "Rural";
                    cout << "\nRurality is: " << strOutput;
                    break;
                
                case 2:
                    strOutput = "Urban";
                    cout << "\nRurality is: " << strOutput;
                    break;

                case 3: 
                    strOutput = "Suburban";
                    cout << "\nRurality is: " << strOutput;
                    break;

                default:
                    cout << "\nNo Rurality recorded.";
                    break;
            }
        };

        // Display menu
        void display_Geo_Menu() {
            cout << "\n\n---------------------------------------------------------------------------------------";
            cout << "\n\t\t\t Please select from the menu options " << endl;
            cout << "---------------------------------------------------------------------------------------";
            cout << "\n1.) Enter state";
            cout << "\n2.) Enter Rurality"; // not sure what word to use?
            cout << "\n3.) Display House hold Rurality";
            cout << "\n4.) Display House hold state";
            cout << "\n9.) Exit program";
        };

        // Menu control
        void menu_Swith_Control() {
            // Local Variables
            int intSelectionNum = 0;
            bool blnFlag = false;

            while (!(blnFlag)) {
                // Display the options
                display_Geo_Menu();

                // Get the user input for the menu selection 
                cout << "\n\nPlease enter your choice here: ";
                cin >> intSelectionNum;

                // Use switch statement to find what the user would like to perform 
                switch (intSelectionNum) {
                    case 1:
                        get_State();
                        break;
                    
                    case 2:
                        get_Rurality();
                        break;
                    
                    case 3:
                        display_Rurality();
                        break;
                    
                    case 4:
                        display_State();
                        break;
                    
                    case 9:
                        // Exit the program
                        blnFlag = true;
                        exit(0);
                        break;
                    
                    default:
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n\nPlease select any number from the menu!" << endl;
                        break;
                }
            }
        };

    // Delcare the private class members    
    private:
        // Set the members
        int intRurality;
        string strState;
};
