// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 12 - Problem #1

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

/** 
 * Algorithm: converts a decimal value to binary using a loop.
 *      1. function takes in an int variable
 *      2. sets r (remainder to 0) sets the binary string to 0
 *      3. if x equals to 0
 *      4. set binary equal to 0.
 *      5. while loop (if remainder is 1 add 1 if its 0 add 0)
 * 
 */

string decimalToBinaryIterative(int x)
{
    int r = 0; // int r for remainder set it to 0
    string binary = ""; // string binary (retunr value)
    if (x == 0) // if x equals to 0
    {
        binary = "0"; // set binary equal to 0
    }
    while (x != 0) // while x is not equal to 0
    {
        r = x%2; // set r equal to the remainder of x/2
        x = x/2; // set x equal to x/2
        if (r == 1) // if r equals to 1 
        {
            binary = "1" + binary; // set binary equal to 1 + binary
        }
        else 
        {
            binary = "0" + binary; // set binary equal to 0 plus binary 
        }
    }
    return binary; // retrun binary
}

int main()
{
    cout << decimalToBinaryIterative(42); // test case for 42
    cout << decimalToBinaryIterative(5); // test case for 5
    cout << decimalToBinaryIterative(0); // test case for 0
}