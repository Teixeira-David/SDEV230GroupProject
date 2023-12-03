/*
Author: Lucas Landis
Date of creation: 11/28/2023 7:20PM
Date of last update: 11/30/2023 8:54AM

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

};
