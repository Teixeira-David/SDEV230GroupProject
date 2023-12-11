// Geographic class Implementation file
/*  
Author: Lucas Landis
Date of creation: 12/9/2023 2:30PM
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include <iomanip>
#include <limits>
#include "Geographic.h"

using namespace std;

// Defualt Constructor
geographicClass::geographicClass()
    : intRurality(""), strState("") {}

// Constructor with parameters
geographicClass::geographicClass(int rurality, string state)
    : intRurality(rurality), strState(state) {}

