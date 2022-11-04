// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – Favorite TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Homework 3 - Problem #3

#include <iostream>
using namespace std;

/** 
 * Algorithm: takes a single input argument, the month, and displays the number of days in that particular month
 *  1. create a function daysOfMonth
 *  2. take the month value and pass it to the function
 *  3. state that if the input is 1,3,5,7,8,10,12
 *      display: "Month " << month (number of the month) << " has 31 days"
 *  4. state that if the input is 2 (february)
 *      display: "Month 2 has 28 or 29 days"
 *  5. state that if the input is 4,6,9,11
 *      display: "Month " << month (number of the month) << " has 30 days"
 *  6. state if the input is none of the values 
 *      display: "Invalid month number"
 *  7. test cases
 */

void daysOfMonth(int month) // create function -- creates variable for month (input)
{
    switch (month) // switch statement to evaluate for cases
    {
       case 1: // for month equals to 1
       case 3: // for month equals to 3
       case 5: // for month equals to 5
       case 7: // for month equals to 7
       case 8: //  for month equals to 8
       case 10: // for month equals to 10
       case 12: // for month equals to 12
            cout << "Month " << month << " has 31 days" << endl; break; // output message for any of the cases above
       case 2: // for month equals to 2
            cout << "Month 2 has 28 or 29 days" << endl; break;  // output message for the case above
       case 4: // for month equals to 4
       case 6: // for month equals to 6
       case 9: // for month equals to 9
       case 11: // for month equals to 11
            cout << "Month " << month << " has 30 days" << endl; break; // output message for any of the cases above
       default: cout << "Invalid month number" << endl; break; // if the in out isn't any of the cases above, display "Invalid month number"
    }
}

int main ()
{
    daysOfMonth(1); // test case for when month equals to 1
    daysOfMonth(2); // test case for when month equals to 2
    daysOfMonth(3); // test case for when month equals to 3
    daysOfMonth(7); // test case for when month equals to 7
    daysOfMonth(11); // test case for when month equals to 11
}