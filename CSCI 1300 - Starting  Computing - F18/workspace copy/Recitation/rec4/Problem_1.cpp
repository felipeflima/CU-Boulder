// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – Favorite TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 4 - Problem #1

#include <iostream>
using namespace std;

/** 
 * Algorithm: print all positive even integers less than or equal to a max value
 *  1. create a function called printEvenNums
 *  2. take the max value and pass it to the function
 *  3. create variable x and assign it to 0
 *  4. create a while loop
 *      while x is less than max-1
 *          increase x by 2
 *          display x
 *  5. test cases
 */

void printEvenNums(int max) //create function -- creates variable for max (input)
{
    int x = 0; // create x and assign it to 0
    while(x < max-1) // while x is less than max-1
    {
        x+=2; // increase x by 2 every time the loop runs
        cout << x << endl; // deisplay x
    }
}

int main()
{
    printEvenNums(100); // test case for when max equals to 100
    printEvenNums(9); // test case for when max equals to 9
    printEvenNums(18); // test case for when max equals to 18
    printEvenNums(27); // test case for when max equals to 27
    printEvenNums(-5); // test case for when max equals to -5
}