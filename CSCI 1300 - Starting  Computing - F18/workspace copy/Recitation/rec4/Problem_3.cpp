// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – Favorite TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 4 - Problem #3

#include <iostream>
using namespace std;

/** 
 * Algorithm: print a filled and hollow square of given width side by side to the screen
 *  1. create a function called printMultiples
 *  2. take the width value and pass it to the function
 *  3. create a string a and assign it to "*"
 *  4. create a for loop
 *      i. create r and assign it to 1; r is less than or equal to width; increment r by 1 (loop for the rows)
 *          a. create for loop (inside the first loop) -- create c and assign it to 1; c is less than or equal to width; increment c by 1 (loop for the columns)
 *              1. display a for every time the loop runs
 *          b. display " " (space) between the squares
 *          c. if r equals to 1 or equals to the width (first and last row)
 *              1. if yes, create a for loop (where c is assgined to 1; c is less than or equal to width; increments c) in which it displays a
 *              2. if not, create another for loop (where c is assgined to 1; c is less than or equal to width; increments c)
 *                  i. inside the for loop create an if statement (if c equals to one or equal to width)
 *                      a. if yes, display a
 *                      b. if not, display " "
 *      ii. end line
 *  5. test cases
 */

void printSquares(int width) // create function -- creates variable for width (input)
{
    string a = "*"; // create string a and assing it to "*"
    for (int r = 1; r <= width; r++) // for loop -- create r and assign it to 1; execute when r is less than or equal to width; then increment r by 1 (rows)
    {
        for (int c = 1; c <= width; c++) //for loop -- create c and assign it to 1; execute when c is less than or equal to width; then increment c by 1 (loop for the columns)
        {
            cout << a; // display a
        }
        cout << " "; // display " " (space) between the squares
        if (r == 1 || r == width) // if r equals to 1 or equals to width (first and last row)
        {
            for (int c = 1; c <= width; c++) //for loop -- create c and assign it to 1; executes when c is less than or equal to width; then increment c by 1 (loop for the columns)
            {
                cout << a; // displays a
            }
        }
        else // if the condition above is not true
        {
            for (int c = 1; c <= width; c++) // for loop -- create c and assign it to 1; executes when c is less than or equal to width; then increment c by 1 (loop for the columns)
            {
                if (c == 1 || c == width) // if c equals to one or equal to width
                {
                    cout << a; // displays a
                }
                else // if not
                {
                    cout << " "; // display " " (space)
                }
            }
        }
        cout << endl; // end line
    }
}

int main()
{
    printSquares(5); // test case for when width equals to 5
    printSquares(7); // test case for when width equals to 7
    printSquares(-4); // test case for when width equals to -4
    printSquares(10); // test case for when width equals to 10
}