// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Homework 2 - Problem #1


#include <iostream>
using namespace std;

/** 
 * Algorithm: converts seconds into hours, minutes and seconds
 *  1. delcare variable seconds
 *  2. declare variable minutes and assign value
 *  3. declare variable f_sec and assign value
 *  4. declare variable hours and assign value
 *  5. declare variable f_min and assign value
 *  6. divide seconds by 60 to find minutes
 *  7. mod seconds by 60 to find the remainder for seconds
 *  8. divide minutes by 60 to find hours
 *  9. mod minutes by 60 to find remainder for minutes
 *  10. output: x hour(s) y minute(s) z second(s)
 *  11. test for 2 cases
 */

void convertSeconds(int seconds)
{
    int minutes = seconds/60; // initial number of seconds devided by 60 to find how many minutes in that amnount of seconds
    int f_sec = seconds%60; // initial number of seconds mod by 60 to find how many seconds remained and will be the final value for seconds
    
    int hours = minutes/60; // found number of minutes devided by 60 to find how many hours in that amnount of minutes
    int f_min = minutes%60; // found number of minutes mod by 60 to find how many minutes remained and will be the final value for minutes
    
    cout << hours << " hour(s) " <<  f_min << " minute(s) " << f_sec << " second(s)" << endl; // output message
}

int main()
{

    convertSeconds(3671); // test case one for 3671 seconds
    convertSeconds(65536); // test case two for 65536 seconds

    return 0;
}