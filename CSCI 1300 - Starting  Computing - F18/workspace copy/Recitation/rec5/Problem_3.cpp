// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1// Recitation 5 - Problem #3

#include <iostream>
# include <string>
using namespace std;

/** 
 * Algorithm: takes a candidate substring and returns the number of times it occurs in another string.
 *  1. create a function called getMatchCount
 *  2. take a substring and a string and pass it to the function
 *  3. set the count = 0
 *  4. check if either the lenght of the substring or the length of the string is 0. if yes, return -1
 *  5. check if the lenght of the substring is greater than the length of the string. if yes, return -2
 *  6. for loop to run through every character in the string
 *      check if the substring is equal to a part of the string. if yes, add 1 to count
 *  7. return count
 *  8. test cases
 */

int getMatchCount(string sub, string s) // create function -- creates substring sub and string s (input)
{
    int count = 0; // creat and set count = 0
    if (sub.length() == 0 || s.length() == 0) // if either the lenght of the substring or the length of the string is 0
    {
        return -1; // return -1
    }
    if (sub.length() > s.length()) // if the lenght of the substring is greater than the length of the string
    {
        return -2; // return -2
    }
    for (int i = 0; i < s.length(); i++) // for loop -- i is assigned to 0; executes when i is less than the lenght of the string; i increments by 1
    {
        if (s.substr(i, sub.length()) == sub) // if the substring is equal to a part of the string
        {
            count++; // add one to count
        }
    }
    return count; // return count
}

int main()
{
    cout << getMatchCount("ello","Hello, World!") << endl; // test case
    cout << getMatchCount("l","Hello, World!") << endl; // test case
    
}