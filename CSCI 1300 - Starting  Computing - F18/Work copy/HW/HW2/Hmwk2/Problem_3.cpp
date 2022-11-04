// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Homework 2 - Problem #3

#include <iostream>
using namespace std;

/** 
 * Algorithm: calculate U.S. population in exactly one year, based on census info for any given initial population
 *  1. declare variable currentPop
 *  2. declare variable secondsPerYear and assign a value
 *  3. declare variable birthsPerYear and assign a value
 *  4. declare variable deathsPerYear and assign a value
 *  5. declare variable immigrantsPerYear and assign a value
 *  6. declare variable pop and assign a value
 *  7. return the resdult for the variable pop
 *  8. output: population after one year
 *  9. test for two cases
 */

int population (int currentPop)
{
    int secondsPerYear = 31536000; // assign a value for the variable secondsPerYear
    int birthsPerYear = secondsPerYear/8; // find how many births there are per year
    int deathsPerYear = secondsPerYear/12; // find how many deaths there are per year
    int immigrantsPerYear = secondsPerYear/27; // find how many new immigrants there are per year
    int pop = currentPop + birthsPerYear - deathsPerYear + immigrantsPerYear; // find the total population by using the census info
    
    return pop; // return the value of the final population
}

int main()
{
    cout << population (12365478) << endl; // test for an initial population of 12365478
    cout << population (8276483) << endl; // test for an initial population of 8276483
    return 0;
}