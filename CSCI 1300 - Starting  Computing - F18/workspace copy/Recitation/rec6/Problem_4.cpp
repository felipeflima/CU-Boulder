// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1// Recitation 6 - Problem #4

#include <iostream>
using namespace std;

/** 
 * Algorithm: split the input string in to pieces separated by the delimiter, and populate the array of strings with the split pieces up to the provided maximum number of pieces.
 *  1. create function that passes the three values
 *  2. create necessary variables
 *  3. if statement for when the string is empty. if yes return 0
 *  4. for loop to run through the string
 *      consider the first char different from the delimeter to be index 0
 *  5. for loop to run throught the string backwars
 *      consider the last char different from the delimeter to be the last
 *  6. set s (the string) equal to the subtring without the delimeter at the beggining or end of the string
 *  7. for loop to run through the string
 *      check if a position is equal to the delimeter and b is false
 *          pass the split to the array as an integer
 *          add one to count
 *          assign index to position plus 1
 *          check if position plus 1 equals the delimeter
 *          increment i and index
 *      check if i equals to the length of the string -1 and b == 0
 *          pass the value of the subtring to the array as an integer
 *  8. check if counts (number of splits) is greater than the max number of splits
 *      if yes, return -1
 *  9. return incremented count
 */

double getScores(string s, int X[], int max) // function with the 3 input values
{
    int index = 0; // creates the variable index and sets it to 0
    int count = 0; // creates the variable count and sets it to 0
    bool b = 0; // creates the variable b and sets it to 0 (false)
    int in = 0; // creates the variable in and sets it to 0
    int in2 = 0; // creates the variable in2 and sets it to 0
    char c = ' '; // creates the variable c and assigns it to ' '
    int length = s.length(); // creates variable length and assign it to the length of the string
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
            X[count] = stoi(s.substr(index, i-index)); // pass the split to the array as an integer
            count++; // add one to count
            index = i + 1; // assign index to position plus 1
            while (s[i+1] == c) // while position plus one is equal to c
            {
                i++; // increment i
                index++; // increment index
            }
        }
        if (i == s.length() -1 && b == 0) // if i equals to the length of the string -1 and b == 0
        {
            
           X[count] = stoi(s.substr(index, i-index + 1)); // pass the value of the subtring to the array
        }
        if (count >= max) // if counts (number of splits) is greater than the max number of splits
        {
        return -1; // return -1
        }
    }
    return ++count; // return incremented count
}

int main()
{
    int nums[6];
    cout << getScores("15     2007 5",nums,4) << endl; // test case
    cout << getScores(" 123 ", nums, 6) << endl; // test case
    cout << getScores("123 000 ", nums, 6) << endl; // test case
    cout << nums[1];
}