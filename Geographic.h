/*
Author: Lucas Landis
Date of creation: 11/28/2023 7:20PM
Date of last update: 12/05/2023 12:54PM

*/


#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 


// Geographic class
class geographicClass {
    public: 
        string state; // state, territory, embassy, or base
        string popGeo; // rural, Urban, or suburban
        
        // Default constructor
        geographicClass() {}

        // Constructor parameters
        geographicClass(string popGeo, int state)
            : strPopGeo(popGeo), intState(state), {}

        // Gets the Rural, Urban, or suburban / popGeo
        void get_Population_Geo() {
            int input;
            cout << "\n Enter 1 for Rural, 2 for Urban, 3 for Suburban: ";
            cin >> input;
        };

        // Gets the state/territory
        void get_Population_Geo() {
            string input;
            cout << "\n Please enter the state, territory, embassy, or U.S. base where you reside : ";
            cin >> input;
        };

        // Display menu
        void Display_Geo_Menu() {
        };

        // Menu control
        void menu_Swith_Control() {
        };

    // Delcare the private class members    
    private:
        // Set the members
        string strPopGeo;
        int intState;
};
