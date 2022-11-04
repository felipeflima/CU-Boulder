// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – Favorite TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 4 - Problem #2

#include <iostream>
using namespace std;

/** 
 * Algorithm: print all positive multiples of an integer number less than or equal to a max value
 *  1. create a function called printMultiples
 *  2. take the x and max value and pass it to the function
 *  3. create variable y and assign it to 0
 *  4. create a while loop
 *      while y is less than or equal to max-x AND x is greater than 0
 *      reassign y to y + x
 *      display y
 *  5. test cases
 */

void printMultiples(int x, int max) // create function -- creates variable for max (input)
{
    int y = 0; // create y and assign it to 0
    while ((y <= max-x) && (x>0)) //  while y is less than or equal to max-x AND x is greater than 0
    {
        y = y + x; // reassign y to y + x
        cout << y << endl; // display y
    }
}

int main()
{
    printMultiples(3,10); // test case for when x is 3 and max is 10
    printMultiples(1,7); // test case for when x is 1 and max is 7
    printMultiples(15,10); // test case for when x is 15 and max is 10
    printMultiples(4,17); // test case for when x is 4 and max is 17
    printMultiples(-3,10); // test case for when x is -3 and max is 10
    printMultiples(3,-10); // test case for when x is 3 and max is -10
}