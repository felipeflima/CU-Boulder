// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Kinlgner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 7 - Problem #2

#include <iostream>
#include <fstream>
using namespace std;

/** 
 * Algorithm: print and array. the array should be printed on a separate line with the integers separated by commas.
 *  1. deal with special cases
 *      a. if the length of the array is 0, print 0
 *      b. if the length of the array is negative, print -1
 *  2. create 1 for loop for the rows of the array and one for the columns
 *  3. print the array in the form of rows and columns (if is not the last column print a "," between the number and if it's the last columns end line)
 *  4. test cases
 */

void printTwoDArray (int a[][5], int length) // fucntion with two input values; 2D array and an integer for the length of the array
{
    if (length == 0) // if the length of the array is 0
    {
        cout << '0'; // print 0
    }
    if (length < 0) // if the length of the array is negative 
    {
        cout << "-1"; // print -1
    }
    for (int i = 0; i < length; i++) // for loop to run through the rows of the array 
    {
        for (int j = 0; j < 5; j++) // for loop to run through the columns of the array 
        {
            cout << a[i][j]; // print the array
            if (j != 4) // if the number of columns is different than 4
            {
                cout << ","; // print ","
            }
        }
        cout << endl; // print the end of a line
    }
}


int main()
{
    int myArray[3][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    printTwoDArray(myArray, 3);
    cout << endl;
    // expected 1,2,3,4,5
    //          6,7,8,9,10
    //          11,12,13,14,15
    int myArray2[4][5]={};
    printTwoDArray(myArray2,4);
    cout << endl;
    // expected 0,0,0,0,0
    //          0,0,0,0,0
    //          0,0,0,0,0
    //          0,0,0,0,0
    int myArray3[3][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    printTwoDArray(myArray3,0);
    cout << endl;
    cout << endl;
    // expected 0
    int myArray4[1][5] = {{-1,-13,0,12,108}};
    printTwoDArray(myArray4,1);
    cout << endl;
    // expected -1,-13,0,12,108
    int myArray5[2][5] = {{0,0,0,0,0}, {1,1,1,1,1}};
    printTwoDArray(myArray5,2);
    // expected 0,0,0,0,0
    //          1,1,1,1,1
}