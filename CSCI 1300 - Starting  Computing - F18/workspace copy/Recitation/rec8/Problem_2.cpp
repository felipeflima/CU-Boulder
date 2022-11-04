// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 8 - Problem #2

#include <iostream>
#include <fstream>
using namespace std;

/**
 * Algorithm: opens a file and writes to it the squares of the numbers from 1 to 10, each on its own line. 
 *  1. creates a function that takes in one parameter (a string for the name of the file)
 *  2. create an output file stream for writing to file
 *  3. check if the file is open
 *      a. if yes
 *          i. create variable x and assign it 1 (x is going to be used to calculate and print the squares)
 *          ii. create while loop that repeats while x is less than or equal to 10
 *              1. write to the file x times x
 *              2. increment x
 *      b. if the file is not open
 *          i. return -1
 *  4. test cases
 */

int fileLoadWrite (string s) // creates a function with one string parameter
{
    ofstream filename; //create an output file stream for writing to file
    filename.open(s); // open the file passed to the function as string s with the file stream
    if (filename.is_open()) // if the file is open
    {
        int x = 1; // create variable x and assign it 1 (x is going to be used to calculate and print the squares)
        while (x <= 10) // while x is less than or equal to 10 (so x reaches 10)
        {
            filename << x * x << endl; // write to the file the value of x times x (square) and end line
            x++; // incerement x
        }
    }
    else // if the file is not open
    {
        return -1; //  return -1
    }
    return 0; // return 0
}

int main()
{
    fileLoadWrite("file.txt"); // opens file and executes function for the squares and prints on file - expected
    // 1
    // 4
    // 9
    // 16
    // 25
    // 36
    // 49
    // 64
    // 81
    // 100

    fileLoadWrite("hello.txt"); // file doesn't exist -  expected nothing (returns -1)
}
