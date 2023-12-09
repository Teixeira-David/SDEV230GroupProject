#include <iostream>
#include "UserClass.h"

using namespace std;

// file to test class UserClass

class PersonClass
    /*
    skeleton class of class PersonClass
    only for testing its derived class UserClass
    */
{
public:
    void print() const {
        cout << "this is just a test function" << endl;
    }
};


int main()
{
    UserClass employee;
    cout << "testing enter function: " << endl;
    employee.enterUserDetails();
    cout << "testing print function(s): " << endl;
    employee.print();
    cout << "testing getter functions: " << endl;
    cout << employee.getFirstName() << endl;
    cout << employee.getLastName() << endl;
    cout << employee.getEmpID() << endl;
    return 0;
}
