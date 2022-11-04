// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 3 - Problem #2

#include <iostream>
using namespace std;

/** 
 * Algorithm: calculate the total pay for a number of hours with a specific hourly pay rate
 *  1. create a function caclPay
 *  2. check if hours OR payrate is less than 0
 *      if yes, return -1
 *  3. check if hours is less than forty AND hours greater than 0
 *      if yes, payRate is assigned to hours times payrate
 *      return payRate
 *  4. if non of the previous statments are true:
 *      payrate is assigned to (40 times p) + hours above (40 times 1.5 times p)
 *      return payRate2
 *  5. test cases
 */

double calcPay(double h, double p) // create functoin calcPay -- creates variable h and p (input)
{
    if (h < 0 || p < 0) // checks if h and p are less than 0
    {
        return -1; // if true return -1
    }
    else if (h <= 40 && h >= 0) // checks if hours is between 0 and 40 (including 0 and 40)
    {
        double payRate = h * p; // if true, assign payRate to h times p
        return payRate; // return payRate
    }
    
    else // for all other values 
    {
        double payRate2 = (40 * p) + ((h - 40) * (1.5) * p); // if true, assigns payRate2 to (40 * p) + ((h - 40) * (1.5) * p)
        return payRate2; // return payRate2
    }
    
}

int main()
{
    cout << calcPay(41,10) << endl; // test case 1 for caclPay
    cout << calcPay(20,30) << endl; // test case 2 for caclPay
    cout << calcPay(-5,12) << endl; // test case 3 for caclPay
}