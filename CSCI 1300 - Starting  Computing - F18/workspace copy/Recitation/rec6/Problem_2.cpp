// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1// Recitation 6 - Problem #2


#include <iostream>
using namespace std;

/** 
 * Algorithm: declare and populate three arrays
 *  1. declare arrays
 *  2. populate arrays
 */

int main()
{
    float temps[10]; // declare array of floating-points with 10 elements
    for (int g = 0; g < 10; g++) // for loop will iterate for every position in the array
    {
        temps[g] = {-459.67}; // initialize array with -459.67
    }
    string colors[] = {"Red", "Blue", "Green", "Cyan", "Magenta"}; // declare array if strings with 5 elements and populate array
    int sequence[100]; // declare array of integers with 49 elements
    for (int i = 0; i < 100; i++) //for loop will iterate for every position in the array
    {
        sequence[i] = i+1; // every time it runs the array add 1 so it creates a list of the 100 integers
    }
}