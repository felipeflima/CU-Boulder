// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – Favorite TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Homework 3 - Problem #4

#include <iostream>
using namespace std;

/** 
 * Algorithm: simulate a portion of the control software for a vehicle-- control the doors
 *  1.  create a function called vehicle
 *  2. take the all the variables values and pass it to the function
 *  3. check if the car is in conditions to be unlocked from all means
 *      if yes, check if one of the means to open from each side is activated and display message that all doors open
 *      if not, check if one of the sides are activates and display message that the doors of the activated side will open
 *      if not (nothing was activated), all doors stay closed
 *  4. check if the master lock or the gear are not in the position for the doors to open
 *      if yes, both doors stay closed
 *  5. check if child lock is on (prevents door from being open from the inside) and masterlock is unlocked and gear is at 'P'
 *      if yes, check if one of the means to open the door from outside from each side is activated and display message that all doors open
 *      if not, check if one of the sides are activates and display message that the doors of the activated side will open
 *      if not, check if only the inside handles are activated, display both doors stay closed
 *      if not (nothing was activated), all doors stay closed
 *  6. test cases
 */

void vehicle(bool dashboardLeft, bool dashboardRight, bool childLock,
        bool masterLock, bool insideLeftlatch, bool outsideLeftlatch, 
        bool insideRightlatch, bool outsideRightlatch, char gearShift) // create function -- creates variable for all the means to open the doors and the locks (input)
{
     if ((masterLock == 0) && (childLock == 0) && (gearShift == 'P')) // check if master lock, child lock and gear shift are in the right position to unlock the doors
        {
            if (((dashboardLeft == 1) || (insideLeftlatch == 1) || (outsideLeftlatch == 1)) && 
            ((dashboardRight == 1) || (insideRightlatch == 1) || (outsideRightlatch == 1))) // if yes, try both sides, if one works on each side open the door
            {
                cout << "Both doors open" << endl; // output message
            }
            else if ((dashboardLeft == 1) || (insideLeftlatch == 1) || (outsideLeftlatch == 1)) // check if one of the means to open the door on the left is activated
            {
                cout << "Left door opens" << endl; // output message
            }
            else if ((dashboardRight == 1) || (insideRightlatch == 1) || (outsideRightlatch == 1)) // // check if one of the means to open the door on the right is activated
            {
                cout << "Right door opens" << endl; // output message
            }
            else // if non of the statements above are true
            {
                cout << "Both doors stay closed" << endl; // output message
            }
        }
    else if ((masterLock == 1) || (gearShift != 'P')) // check if master lock and gear are on the worng position to open the doors
    {
        cout << "Both doors stay closed" << endl; // output message
    }
    else if ((childLock == 1) && (masterLock == 0) && (gearShift == 'P')) // check if child lock is on, master lock is off and gearshift is at 'P'
    {
        if (((dashboardLeft == 1) || (outsideLeftlatch == 1)) && 
            ((dashboardRight == 1) || (outsideRightlatch == 1))) // if yes, try both sides from the outside, if one works on each side open the door
            {
                cout << "Both doors open" << endl; // output message
            }
        else if ((dashboardLeft == 1) || (outsideLeftlatch == 1)) // check if any of the means to open the left door from the outside are activated
        {
            cout << "Left door opens" << endl; // output message
        }
        else if ((dashboardRight == 1) || (outsideRightlatch == 1)) // check if any of the means to open the right door from the outside are activated
        {
            cout << "Right door opens" << endl; // output message
        }
        else if ((insideLeftlatch == 1) || (insideRightlatch == 1)) // check if any of the means to open the doors from the inside are activated
        {
            cout << "Both doors stay closed" << endl; // output message
        }
        else // if non of the statements above are true
        {
            cout << "Both doors stay closed" << endl; // output message
        }
    }
}

int main()
{
    vehicle(1,1,0,0,1,0,0,1,'P'); // test case 1
    vehicle(0,0,0,0,0,0,1,0,'P'); // test case 2
    vehicle(0,0,1,1,0,0,0,0,'1'); // test case 3
    vehicle(1,0,1,0,1,1,0,1,'P'); // test case 4
    vehicle(0,1,0,0,0,0,0,0,'3'); // test case 5
    vehicle(1,0,0,1,1,1,1,1,'P'); // test case 6
    vehicle(1,0,0,0,0,0,0,0,'P'); // test case 7
}