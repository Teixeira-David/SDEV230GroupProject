/*
Author: Lucas Landis
Date of creation: 11/28/2023 7:20PM
Date of last update: 11/30/2023 8:54AM

*/


#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 


// Geographic section of census
class Geographic {
    public: 
        string state; // state, territory, embassy, or base
        string popGeo; // rural, Urban, or suburban
};
