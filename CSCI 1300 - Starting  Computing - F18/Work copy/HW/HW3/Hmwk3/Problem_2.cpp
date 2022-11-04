// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – Favorite TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Homework 3 - Problem #2

#include <iostream>
using namespace std;

/** 
 * Algorithm: takes integer as input and returns how many digits the number has
 *  1. create a function called countDigits
 *  2. take the number value and pass it to the function
 *  3. check if the integer is negative
 *      if yes, assign number to number times (-1) (so the number becomes positive)
 *  4. check if the number is positive and less than 10
 *      if yes, return 1 (1 digit)
 *  5. check if the number greater or equal to 10 AND less then 100
 *      if yes, return 2 (2 digits)
 *  6. check if the number is greater then or equal to 100 AND less than 1000
 *      if yes, return 3 (3 digits)
 *  7. check if the number is equal to 1000
 *      if yes, return 4 (4 digits)
 *  8. test cases
 */

int countDigits(int number) // create function -- creates variable for number (input)
{
    if (number < 0) // check if the number is negative
    {
        number = number * (-1); // if yes, make it positive
    }
    if (number >= 0 && number < 10) // check is the number is in between 0 and 10 (including 0)
    {
        return 1; // if yes, return 1 (number of digits)
    }
    else if (number >= 10 && number < 100) // check is the number is in between 10 and 100 (including 10)
    {
        return 2; // if yes, return 2 (number of digits)
    }
    else if (number >= 100 && number < 1000) // check is the number is in between 100 and 1000 (including 100)
    {
        return 3; // if yes, return 3 (number of digits)
    }
    else if (number == 1000) // check is the number is equal to 1000
    {
        return 4; // if yes, return 4 (number of digits)
    }
    
}

int main()
{
   cout << countDigits(4) << endl; // test case for when number equals to 4
   cout << countDigits(30) << endl; // test case for when number equals to 30
   cout << countDigits(-25) << endl; // test case for when number equals to -25
   cout << countDigits(573) << endl; // test case for when number equals to 573
   cout << countDigits(1000) << endl; // test case for when number equals to 1000
}