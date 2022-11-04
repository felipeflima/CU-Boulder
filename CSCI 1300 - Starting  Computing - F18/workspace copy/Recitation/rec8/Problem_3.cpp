// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 8 - Problem #3

#include <iostream>
#include <fstream>
using namespace std;

/** 
 * Algorithm: open a file in read mode, check for success, and read the lines until the end of the file then closes the file
 *  1. creates the function that takes in one string paramenter
 *  2. create a file stream for reading a file
 *  3. open the file passed to the function as string s with the file stream
 *  4. check if the file is open
 *      a. create count variable that will count the lines
 *      b. creates a string that will be used in the getline fuction
 *      c. while there is a line, increment count
 *  5. close file
 *  6. return count
 *  7. if the file is not oepn return -1
 *  8. test cases
 */

int fileLoadRead (string s) // creates a function with one string parameter
{
    ifstream filename; // create a file stream for reading a file
    filename.open(s); // open the file passed to the function as string s with the file stream
    if (filename.is_open()) // if the file is open
    {
        string line = ""; // create string line and assign it to "" (empty string)
        int count = 0; // create a count variable and assign it to 0
        while (getline(filename, line)) // while there is a line to get, get line from filename and write it in line
        {
            count ++; // increment count
        }
        filename.close(); // close file
        return count; // return count
    }
    else // if the file is not open
    {
        return -1; // return -1
    }
}

int main()
{
    cout << fileLoadRead("file.txt"); // opens file and executes function for the squares and prints on file - expected 10 (if reading from file text that has 10 lines)
    cout << fileLoadRead("hi.txt"); // file doesn't exist -  expected -1
}
