// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 3 - Problem #3

#include <iostream> 
using namespace std;

/** 
 * Algorithm: checks if any year is a leap year
 *  1. create function checkLeapYear
 *  2. Take the year value passed to the function
 *  3. create variable leapYear
 *  4. for now, leapYear is assigned 0 (false - the input would not be a leap year)
 *  4. check if year (input value) is [less than 1582 AND divisible by 4] OR if year is [greater than or equal to 1582 AND divisible by 4 AND not divisible by 100] OR if [year is greater than or equal to 1582 AND is divisible by 4 AND is divisible by 400]
 *      if yes, than reassign the value of leapYear to 1 (true - the input value is a leap year)
 *  5. return: leapYear
 *  6. test cases in main
 */

bool checkLeapYear(int year) // create functoin checkLeapYear -- creates variable year (input)
{
    int leapYear; // creates the variable leapYear
    leapYear = 0; // assigns 0 (false) to the variable leapYear
    if (((year < 1582) && (year % 4 == 0)) || ((year >= 1582) && (year % 4 == 0) && (year % 100 != 0))|| ((year >= 1582) && (year % 4 == 0) && (year % 400 == 0))) // check if the input value is [less than 1582 AND divisible by 4] OR if year is [greater than or equal to 1582 AND divisible by 4 AND not divisible by 100] OR if [year is greater than or equal to 1582 AND is divisible by 4 AND is divisible by 400]
    {
        leapYear = 1; // if true, reassigns the value of leapYear to 1 (true)
    }
    return leapYear; // return leapYear (output)
}

int main()
{
    cout << checkLeapYear(5) << endl; // output message for test case when year == 5
    cout << checkLeapYear(400)<< endl; // output message for test case when year == 400
    cout << checkLeapYear(1500) << endl; // output message for test case when year == 1500
    cout << checkLeapYear(1800) << endl; // output message for test case when year == 1800
    cout << checkLeapYear(2000) << endl; // output message for test case when year == 2000
    cout <<  checkLeapYear(1891) << endl; // output message for test case when year == 1891
    cout <<  checkLeapYear(1782) << endl; // output message for test case when year == 1782
}