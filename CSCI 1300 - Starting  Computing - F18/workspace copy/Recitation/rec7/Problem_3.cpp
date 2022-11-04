// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Kinlgner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 7 - Problem #3

#include <iostream>
#include <fstream>
using namespace std;

/** 
 * Algorithm: print out a "map" of which points in the array are below the water level.
 *  1. check if a position in the arrray is greater than or less than the level of the water
 *      a. if it is greater print "_"
 *      b. if it is less print "*"
 *  2. test cases
 */

void floodMap (double a[][4], int rows, double level) // fucntion with three input values; 2D array, an integer for number of rows, and a double for the level of the water
{
    for (int i = 0; i < rows; i++) // for loop to run through the rows of the array
    {
        for (int j = 0; j < 4; j++) // for loop to run through the columns of the array 
        {
            if (a[i][j] > level) // if the ineteger on the array is greater than the level
            {
                cout << "_"; // print "_"
            }
            else if (a[i][j] < level) // if the ineteger on the array is less than the level
            {
                cout << "*"; // print "*"
            }
        }
        cout << endl; // print and end line
    }
}

int main()
{
    double map[1][4] = {{5.0, 7.6, 3.1, 292}};
    floodMap(map, 1, 6.0);
    cout << endl;
    // expected *_*_
    
    double map2[1][4] = {0, 0, 0, 0};
    floodMap(map2, 1, 1);
    cout << endl;
    // expected ****
    
    double map3[1][4] = {9, 9, 9, 9};
    floodMap(map3, 1, 0);
    cout << endl;
    // expected ____
    
    double map4[3][4] = {{2.35879, 16.1916, 5.37617, 5.89066},
    {2.8125, 5.44745, 16.8526, 4.57367},
    {13.6683, 8.70118, 3.64799, 5.23928}};
    floodMap(map4, 3, 11);
    // expected *_**
    //          **_*
    //          _***
}