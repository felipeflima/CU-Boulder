// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1// Recitation 5 - Problem #1

#include <iostream>
# include <string>
using namespace std;

/** 
 * Algorithm: takes a sentence and returns the number of words in the sentence
 *  1. create a function called getWordCount
 *  2. take a string and pass it to the function
 *  3. set the count = 1 (0 spaces = 1 word)
 *  4. check if the length of the string is 0, if yes, return 0
 *  5. for loop to run through every character in the string
 *      check if a position in the string is a space. if yes, add 1 to count
 *  6. return count
 *  7. test cases
 */
 

int getWordCount (string s) // create function -- creates string s (input)
{
    int count = 1; // creat and set count = 1 (0 spaces = 1 word)
    if (s.length() == 0) // if string length is 0
        {
            return 0; // return 0
        }
    //cout << s.length() << endl;
    for (int i = 0; i < s.length(); i++) // for loop -- i is assigned to 0; executes when i is less than the lenght of the string; i increments by 1
    {
        if (s[i] == ' ') // if a character on the string is a space
        {
            count++; // increment count by 1
        }
    }
    return count; // return count
}

int main()
{
    cout << getWordCount("Hello, World!") << endl; // test case
    // cout << getWordCount("") << endl; // test case
    // cout << getWordCount("Hello, I'm World!") << endl; // test case
}