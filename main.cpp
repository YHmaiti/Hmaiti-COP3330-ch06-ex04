/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Yohan Hmaiti
 */

// include the header file that contains all the imports needed
#include "std_lib_facilities.h"

// use the standard namespace
using namespace std;

// create a class named Name_value
// this class holds a value and a String
// this will enable us to work with one vector combining the
// String name and value at once instead of having a vector for the name
// and another for the value
class Name_value {

    // declare public elements
    public:
        string name;
        int value;
        // assign the passed variables to their respective class
        // variables, the value will store num and the name String will
        // store str
        Name_value(string str, int num)
            : name(str), value(num) {}
};

// main driver function
int main(void) {

    // variables declaration
    // create a string variable to hold the name
    // create an int type variable to hold the value
    // create a vector of type Name_value to hold the assigned pairs as 
    // desired by the assignment and matching the type of input expected combined
    // in one vector
    string currentString;
    int currentValue;
    vector<Name_value> pairsCombined;

    // prompt the user for input
    cout << "Enter the names and their respective values desired seperated by a space as pairs: (! to end, input a pair with the name NoName and a value of 0):\n";

    // scan for input in regards of the name and its related value
    // unless the user enters NoName then we stop as requested from the assignment
    // we will also prohibit the storing of duplicates by throwing an error message
    while ((cin >> currentString >> currentValue) && !(currentString == "NoName" && currentValue == 0))
    {

        // check if the current scanned input is already present
        // if so throw an error
        for (int i = 0; i < pairsCombined.size(); i++)

            if (currentString == pairsCombined[i].name)

                error("The following element is already present try again -> ", currentString); 

        // if there are no duplicates then we can store the pair safely in our vector
        pairsCombined.push_back(Name_value(currentString, currentValue));
    }

    // let's print the pairs after a successful building of the vector
    int j = 0;
    cout << '\n';
    while (j < pairsCombined.size()) {

        // we will make sure to have one pair per line
        cout << '(' << pairsCombined[j].name << " , " << pairsCombined[j].value << ')' << endl;
        j++;
    
    }


    // end of the main function
    return 0; 
}
