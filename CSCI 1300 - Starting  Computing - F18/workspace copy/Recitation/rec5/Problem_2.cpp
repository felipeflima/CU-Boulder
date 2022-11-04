// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1// Recitation 5 - Problem #2

#include <iostream>
# include <string>
using namespace std;

/** 
 * Algorithm: count the number of digits in a string
 *  1. create a function called getDigitCount
 *  2. take a string and pass it to the function
 *  3. set the count = 0
 *  4. for loop to run through every character in the string
 *      check if a position in the string is a number. if yes, add 1 to count
 *  5. return count
 *  6. test cases
 */

int getDigitCount (string s) // create function -- creates string s (input)
{
    int count = 0; // creat and set count = 0
    for (int i = 0; i < s.length(); i++) // for loop -- i is assigned to 0; executes when i is less than the lenght of the string; i increments by 1
    {
        if (s[i] >= '0' && s[i] <= '9') // position in the string is a number
        {
            count++; // add one to count
        }
    }
    return count; // return count
}


int main()
{
    cout << getDigitCount("40js") << endl; // test case
    cout << getDigitCount("dsfg45678k") << endl; // test case
    cout << getDigitCount("fghj") << endl; // test case
    cout << getDigitCount("40987") << endl; // test case
}