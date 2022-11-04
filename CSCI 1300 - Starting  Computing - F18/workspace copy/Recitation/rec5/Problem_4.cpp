// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1// Recitation 5 - Problem #4

#include <iostream>
# include <string>
using namespace std;

/** 
 * Algorithm: return the last index at which a character is used in a string
 *  1. create a function called getLastIndex
 *  2. take a character and a string and pass it to the function
 *  3. check if the length of the string is 0. if yes, return -1
 *  4. create index and assign it to -2 (this way if the character is not found on the string, the function will return -2)
 *  5. for loop to run through every character in the string
 *      check if the input character is equal to a character on the string. if yes, index becomes the number of the that last character on the string
 *  6. return index
 *  7. test cases
 */

int getLastIndex (char x, string s) // create function -- creates character x sub and string s (input)
{
    if (s.length() == 0) // if the length of the string is 0
    {
        return -1; // return -1
    }
    int index = -2; // creates index and assigns it to -2
    for (int i = 0; i < s.length(); i++) // for loop -- i is assigned to 0; executes when i is less than the lenght of the string; i increments by 1
    {
        if (x == s[i]) // if the input character is equal to a character on the string
        {
            index = i; // reassigns index to i (number of the that last character on the string)
        }
    }
    return index; // returns index
}

int main()
{
    cout << getLastIndex('l',"Hello, World!") << endl; // test case
    cout << getLastIndex('p',"Hello, World!") << endl; // test case
    cout << getLastIndex('e',"Hello, World!") << endl; // test case
    cout << getLastIndex('e',"") << endl; // test case
}