// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Homework 2 - Problem #4

#include <iostream>
#include <math.h>
using namespace std;

/** 
 * Algorithm: calculate luminosity based on the formula for any given value
 *  1. declare variable lum and assign a value (formula)
 *  2. return the result for lum
 *  3. output: luminosity 
 *  4. test ofr two cases
 */

int luminosity(double b, double d)
{
    double lum = 4* b * M_PI * pow(d, 2); // assign a value (formula) for lum
    return lum; // return the value for lum
}

int main()
{
    cout << luminosity(1.5,17.8) << endl; // test case one
    cout << luminosity(2.1,20.9) << endl; // test case two
    return 0;
}