// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1// Recitation 6 - Problem #3

#include <iostream>
using namespace std;

/** 
 * Algorithm: split the input string in to pieces separated by the delimiter, and populate the array of strings with the split pieces up to the provided maximum number of pieces.
 *  1. create function that passes the four values
 *  2. create necessary variables
 *  3. if statement for when the string is empty. if yes return 0
 *  4. for loop to run through the string
 *      consider the first char different from the delimeter to be index 0
 *  5. for loop to run throught the string backwars
 *      consider the last char different from the delimeter to be the last
 *  6. set s (the string) equal to the subtring without the delimeter at the beggining or end of the string
 *  7. for loop to run through the string
 *      check if a position is equal to the delimeter and b is false
 *          pass the split to the array
 *          add one to count
 *          assign index to position plus 1
 *          check if position plus 1 equals the delimeter
 *          increment i and index
 *      check if i equals to the length of the string -1 and b == 0
 *          pass the value of the subtring to the array
 *  8. check if counts (number of splits) is greater than the max number of splits
 *      if yes, return -1
 *  9. return incremented count
 */

double split(string s, char c, string X[], int max) // function with the 4 input values
{
    int index = 0; // creates the variable index and sets it to 0
    int count = 0; // creates the variable count and sets it to 0
    bool b = 0; // creates the variable b and sets it to 0 (false)
    int in = 0; // creates the variable in and sets it to 0
    int in2 = 0; // creates the variable in2 and sets it to 0
    int length = s.length(); // // creates the variable length and sets it to the length of the string
    if (s == "") // if statement for when the string is empty
    {
        return 0; // if yes return 0
    }
    for (int i = 0; i < s.length(); i++) // for loop to run through the string
    {
        if (s[i] != c) // if a position in the string is different from the delimeter
        {
            in = i; // set in equal to the position
            i = s.length(); // set the position equal to the length
        }
    }
    for (int i = s.length() - 1; i >= 0; i--) // for loop to run through the string backwards
    {
        if (s[i] != c) // if a position in the string is different from the delimeter
        {
            in2 = i; // set in2 equal to the position
            i = -1; // set the position equal to -1
        }
    }
    s = s.substr(in, in2- in + 1); // set s (the string) equal to the subtring without the delimeter at the beggining or end of the string
    for (int i = 0; i < s.length(); i++)  // for loop to run through the string
    {
        if (s[i] == c && b == 0) // if a position is equal to the delimeter and b is false
        {
            X[count] = s.substr(index, i-index); // pass the split to the array
            count++; // add one to count
            index = i + 1; // assign index to position plus 1
            if (s[i+1] == c) // if position plus 1 equals the delimeter
            {
                i++; // increment i
                index++; // increment index
            }
        }
        if (i == s.length() -1 && b == 0) // if i equals to the length of the string -1 and b == 0
        {
           X[count] = s.substr(index, i-index + 1); // pass the value of the subtring to the array
        }
    }
    if (count > max) // if counts (number of splits) is greater than the max number of splits
    {
        return -1; // return -1
    }
    return ++count; // return incremented count
}

int main()
{
    string words[6]; // test case
    cout << split("one small  steps  ",' ', words, 6); // test case
    cout << split("one small steps",' ', words, 2); // test case
    cout << split("  one small  steps",' ', words, 6); // test case
}