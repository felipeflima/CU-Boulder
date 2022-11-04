// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 3 - Problem #1


#include <iostream>
using namespace std;

/** 
 * Algorithm: determine whether a number is positive, negative or zero
 *  1. create function
 *  2. take the integer value passed to the function
 *  3. check if the integer is greater than 0
 *      if yes, print "positive"
 *  4. check if integer is equal to 0
 *      if yes, print "zero"
 *  5. in non of the previous statments are true:
 *      print "negative"
 *  6. return nothing
 *  7. test cases
 */

void numberSign (int integer) // create function -- creates variable for integer (input)
{
    if (integer > 0) // checks if input value is greater than 0
    {
        cout << "positive" << endl; // output message
    }
    else if (integer == 0) // checks if input value is equal to 0
    {
        cout << "zero" << endl; // output message
    }
    else // for all other values
    {
        cout << "negative" << endl; // output message
    }
}

int main()
{
    numberSign(1); // test case for when integer equals to 1
    numberSign(-1); // test case for when integer equals to -1
    numberSign(0); // test case for when integer equals to 0
    numberSign(500); // test case for when integer equals to 500
    numberSign(-300); // test case for when integer equals to -300
}
    
