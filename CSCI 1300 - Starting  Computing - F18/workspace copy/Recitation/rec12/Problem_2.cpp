// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 12 - Problem #2

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

/** 
 * Algorithm: converts a decimal value to binary using recursion.
 *      1. function takes in an int variable
 *      2. sets r (remainder to 0) sets the binary string to 0
 *      3. if x equals to 0
 *      4. set binary equal to 0.
 *      5. if remainder is 1 add 1 if its 0 add 0
 *      6. recursion passing x/2 as the variable
 */

string decimalToBinaryRecursive(int x) //
{
    int r = 0; // int r for remainder set it to 0
    string binary = ""; // string binary (retunr value)
    if (x == 0) // of x equals to 0
    {
        return "0"; // returns 0 as a string
    }
    r = x%2; // set r equal to the remainder of x/2
    if (r == 1) // if r equals to 1
    {
        binary = "1"; // sets binary equal to 1
    }
    else 
    {
        binary = "0"; // sets binary equal to 0
    }
    return decimalToBinaryRecursive (x/2) + binary; // call the function passing the original x divided by 2 and add binary
}

int main()
{
    cout << decimalToBinaryRecursive(42); // test case for 42
    cout << decimalToBinaryRecursive(0); // test case for 0
    cout << decimalToBinaryRecursive(5); // test case for 5
}