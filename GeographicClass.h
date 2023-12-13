/*
Author: Lucas Landis
Date of creation: 11/28/2023 7:20PM
Date of last update: 12/11/2023 7:04PM

*/

// Check preprocessor macro for definition
#ifndef H_GeographicClass
#define H_GeographicClass

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
        // Execution memory methods
        geographicClass** allocGeographics();
        void deallocGeographics(geographicClass** aGeographics, int intSize);

        //string state; // state, territory, embassy, or base
        //int rurality; // rural, Urban, or suburban
        
        // Default constructor
        geographicClass();

        // Constructor parameters
        geographicClass(int rurality, string state);

        // setter
        void set_Rurality(); // Gets the Rural, Urban, or suburban / rurality
        void set_State(); // Gets the state/territory
        void menu_Swith_Control(); // Menu control
        void enterGeographicDetails();
        int getMaxGeographicCount() const;

        // getter
        string get_State() const;
        int get_Rurality() const;
        string get_Rurality_String() const;

        // print
        void print_State(); // This displays the state or territory
        void print_Rurality(); // This displays the Rurality]
        void display_Geo_Menu(); // Display menu
        void print_Rurality_String();

        // Format for file dump
        string formatForFile() const;

    // Delcare the private class members    
    private:
        // Store memory information
        geographicClass** m_aGeographics;
        int m_intMaxGeographicCount;

        // Set the members
        int intRurality;
        string strRurality;
        string strState;
};

#endif
