// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Kinlgner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 7 - Problem #1

#include <iostream>
#include <fstream>
using namespace std;

/** 
 * Algorithm: replaces each element except the first and last by the larger of its two neighbors.
 *  1. Run through the array comparing integers
 *  2. if at a index in the array, the next integer is greater than the previous one
 *      a. replace the index with the next integer (the greatest)
 *  3. if at a index in the array, the next previous is greater than the next one
 *      a. replace the index with the previous integer (the greatest)
 *  4. process has to be done by using two arrays so the for loop comapres the right integers (the original integers and not the updates ones)
 *  5. test cases
 */

void replaceNums (int a[], int length)
{
    int b[length]; // creates an array to update the given array to the new one
    b[0] = a[0]; // sets the index 0 of the new array to index 0 of the given array
    b[length - 1] = a[length - 1]; // sets the last integer of the new array to equal to the last integer of the give array
    for (int i = 0; i < length; i++) // for loop to run through the array
    {
        if (a[i-1] <= a[i+1]) // if at a index in the array, the next integer is greater than the previous one
        {
            if ((i != 0) && (i != (length - 1))) // if it is not the first of last integer in the array
            {
            b[i] = a[i+1]; // set the the integer int the new array to be equal to the next integer
            }
        }
        else if (a[i+1] <= a[i-1]) // if at a index in the array, the prvious integer is greater than the next one
        {
            if ((i != 0) && (i != (length - 1))) // if it is not the first of last integer in the array
            {
            b[i] = a[i-1]; // // set the the integer int the new array to be equal to the prvious integer
            }
        }
    }
    for (int i = 0; i < length; i++) // for loop to run through the array
    {
        a[i] = b[i]; // assign array b to array a
    }
}

int main()
{
    int myArray[4] = {1, 3, 4, 5}; // test case
    int myArray2[4] = {5, 4, 3, 1}; // test case 
    int myArray3[3] = {5, 3, 1}; // test case
    replaceNums(myArray, 4); // test case for an array of length 4
    cout << endl;
    replaceNums(myArray2, 4); // test case for an array of length 4
    cout << endl;
    replaceNums(myArray3, 4); // test case for an array of length 4
}