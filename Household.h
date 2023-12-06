#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

using namespace std;

class Household{
    public:
        void setHouseholdInfo(string, string, string, string);
        void printHouseholdInfo() const;
        Household();

    private:
        string address;
        string relationship;
        string residence;
        string ownership;
};

#endif
