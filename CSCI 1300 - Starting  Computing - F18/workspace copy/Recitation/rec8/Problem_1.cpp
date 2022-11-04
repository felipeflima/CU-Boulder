// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 8 - Problem #1

#include <iostream>
#include <fstream>
using namespace std;

/** 
 * Algorithm: opens a file and check if the file was opened
 *  1. creates a function that takes in one parameter (a string for the name of the file)
 *  2. create a file stream for reading a file
 *  3. open the file
 *  4. check if the file is open
 *      a. if yes, return true
 *      b. if not, return false
 *  5. test cases
 */

bool checkFile (string s) // function that returns true or false and takes in one string parameter
{
    ifstream filename; // create a file stream for reading a file
    filename.open(s); //open the file passed to the function as string s with the file stream
    if (filename.is_open()) // if the file is open
    {
        return true; // return true
    }
    else // if the file is not open 
    {
        return false; // return false
    }

}

int main ()
{
    cout << checkFile("file.txt") << endl; // opens the right file - expected 1
    cout << checkFile("hey.txt") << endl; // file does not exist - expected 0
}