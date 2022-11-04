// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Homework 2 - Problem #2

#include <iostream>
#include <iomanip>
using namespace std;

/** 
 * Algorithm: convert celsius to fahrenheit
 *  1. declare the variable tempC (temperature in celsius)
 *  2. declare the variable temp F (temperature in fahrenheit) and assign a value
 *  3. output: The temperature of tempC in fahrenheit is tempF
 *  4. test for two cases
 */

void celsiusToFahrenheit(double tempC)
{
    double tempF = tempC * (9.0/5.0) + 32; // set temperature in Fahrenheit equal to the initial value in celsius * (9/5) + 32
    cout << "The temperature of " << tempC << " in fahrenheit is " << setprecision(2) << fixed << tempF << endl; // output message
}

int main()
{
    celsiusToFahrenheit(38); // test case one for 38 Celsius
    celsiusToFahrenheit(0); // test case two for 0 Celsius
    
    return 0;
}