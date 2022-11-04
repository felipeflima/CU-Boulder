// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – Favorite TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 4 - Problem #4

#include <iostream>
using namespace std;

/** 
 * Algorithm: print a diamond with given side length to the screen
 *  1. create a function called printMultiples
 *  2. take the width value and pass it to the function
 *  3. create string a and assign it to "*"
 *  4. for loop (rows growing the number of *)
 *      for loop
 *          print " " for every row from lenght (always decreasing 1 and printing lenght - r spaces) to 0
 *      for loop
 *          print a for every row from lenght (always increasing one and printing 2 * r -1 a's) to 0
 *      end line
 *  5. same thing but the other way around (decreasing the * and increasing the spaces)
 */

void printDiamond(int lenght) // // create function -- creates variable for width (input)
{
    string a = "*"; // create string a and assing it to "*"
    for (int r = 1; r <= lenght; r++) // for loop -- r is assigned to 1; executes when r is less than or equal to lenght; r increments by 1
    {
        for (int s = 1; s <= lenght - (r); s++) // for loop -- s is assigned to 1; executes when s is less than or equal to lenght - r; s increments by 1
        {
            cout << " "; // display " " (space)
        }
        for (int c = 1; c <= 2 * (r) -1; c++) // for loop -- c is assigned to 1; executes when c is less than or equal to 2 times 2 -1; c increments by 1
        {
            cout << a; // displays "*"
        }
        cout << endl; // end line
    }
   for (int r = 1; r <= lenght -1; r++) // for loop -- r is assigned to 1; executes when r is less than or equal to lenght - 1; r increments by 1
    {
        for (int c = 1; c <= (r) ; c++) // for loop -- c is assigned to 1; executes when c is less than or equal to r; c increments by 1
        {
            cout << " "; // displays " " (space)
        }
        for (int s = 1; s <= lenght + (lenght-1) - 2*r; s++) // for loop -- s is assigned to 1; executes when s is less than or equal to lenght + (lenght-1) - 2*r; s increments by 1
        {
            cout << a; // displays "*"
        }
        cout << endl; // end line
    }
}

int main()
{
    printDiamond(10); // test case for when lenght equals to 10
    printDiamond(4); // test case for when lenght equals to 4
    printDiamond(5); // test case for when lenght equals to 5
    printDiamond(-5); // test case for when lenght equals to -5
}