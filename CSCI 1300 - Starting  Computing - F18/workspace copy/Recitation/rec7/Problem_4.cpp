// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Kinlgner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 7 - Problem #4

#include <iostream>
#include <fstream>
using namespace std;

/** 
 * Algorithm: reads from a file of integers and stores its content in an array.
 *  1. open file and read the file
 *  2. assign the values on the files to an array as integers
 *  3. return lineidx
 *  4. test cases
 */

int getLinesFromFile (string filename, int a[4], int length) // fucntion with three input values; a string, an array, and length
{
    int lineidx = 0; // create variable
    ifstream myfilestream; // create a file stream for reading to file
    myfilestream.open(filename); // open the file 
    if (myfilestream.is_open()) // if the file is open
    {
        string line = ""; // assgin assign string line to ""
        while (getline(myfilestream, line)) // read in an entire line from myfilestream and set line equal to its contents.
        {
            if (line != "") // if line is not empty
            {
            a[lineidx] = stoi(line); // assign the line as an integer to the array
            lineidx++; // increment lineidx
            }
        }
    }
    else // if non of the consitions above are met
    {
        return -1; // return -1
    }
    return lineidx; // return lineidx
}


int main()
{
    int arr[4];
    cout << getLinesFromFile("fileName.txt", arr, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << endl;
        cout << arr[i];
    }
    cout << endl;
    cout << endl;
    // expected 4
    //          1
    //          2
    //          3
    //          4
    
    int numArray[12];
    int x = getLinesFromFile("emptyLines.txt", numArray, 12);
    cout << "Function returned: " << x << "\n";
    for(int i = 0; i < x; i++)
    {
        cout << numArray[i] << endl;
    }
    // expected Function returned: -1
}