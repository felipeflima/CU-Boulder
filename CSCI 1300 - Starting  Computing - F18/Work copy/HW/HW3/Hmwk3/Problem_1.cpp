// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – Favorite TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Homework 3 - Problem #1


#include <iostream>
using namespace std;

/** 
 * Algorithm: take an input and calculate the output based on the Collatz sequence
 *  1. create a function called collatzStep
 *  2. take the n value and pass it to the function
 *  3. check if the integer is even and positive
 *      if yes, create variable neven and assign it a value (n/2)
 *      return neven
 *  4. if previous statement is false, check if n is positive
 *      if yes, create variable nodd and assign it a a value 3 times n + 1
 *      return nodd
 *  5. if non of the previous statements are true
 *      return 0
 *  6. test cases
 */

int  collatzStep (int n) // create function -- creates variable for n (input)
{
    if ((n % 2 == 0) && (n >= 0)) // check if the input is even and positive
    {
        int neven = n/2; // create neven and assign it a value
        return neven; // return neven
    }
    else if (n >= 0) // check if n is positive and since it is not even (according to previous statement) n is odd
    {
        int nodd = 3* n + 1; // create nodd and assign it a value
        return nodd; // return nodd
    }
    else // if none of the previous is true (number will be negative)
    {
        return 0; // return 0
    }
}

int main()
{
    cout << collatzStep(3) << endl; // test case for when n equals to 3
    cout << collatzStep(8) << endl; // test case for when n equals to 8
    cout << collatzStep(-3) << endl; // test case for when n equals to -3
    cout << collatzStep(0) << endl; // test case for when n equals to 0
}