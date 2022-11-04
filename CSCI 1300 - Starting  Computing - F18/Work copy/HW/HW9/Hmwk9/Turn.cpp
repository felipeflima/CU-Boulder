#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Turn.h"
using namespace std;

Turn::Turn()
{
    day = 0;
    month = 0;
    year = 0;
    miles = 0;
    foodT = 0;
    bulletsT = 0;
    moneyT = 0;
}

bool Turn::readInfo(filename)
{
    //reads information from a file that has the Status variable values stored 
    // stores the information in the Turn class variables
}

void Turn::statusUpdate()
{
    //print a status uptade:
    // ○ Current date (mm-dd-yyyy)
    // ○ Miles traveled (in miles from the start of the trip)
    // ○ Distance until the next milestone (in miles)
    // ○ Food available (in lbs.)
    // ○ Number of Bullets available
    // ○ Cash available (in $)
}

int choice()
{
    cout << "What would you like to do?" << endl;
    cout << "1. Rest" << endl << "2. Continue on the trail" << endl << "3. Hunt" << "4. Quit" << endl;
    int x = 0;
    cin >> x;
    while (x != 4)
    {
        switch(x)
        // return a number and if statements on the driver if statements decide what function to call corresponding to the statement above
        {
            case 1: 
                return 1;
                break;
            case 2: 
                return 2;
                break;
            case 3: 
                return 3;
                break;
            case 4: 
                return 4;
                break;
            default:
                    cout << "invalid input" << endl;
                    cout << endl;
        }
    }
}

void Turn::rest()
{
    //Resting takes between 1 and 3 days. Note: a turn where the player chooses to rest does not take 2 weeks.
    //b. The resting party consumes 3 lbs. of food, per person, per day
    //update date
}

void Turn::continueTrail()
{
    // A turn where the player chooses to continue on the trail takes 2 weeks
    // b. The travelling party consumes 3 lbs of food, per person, per day
    // c. You typically travel between 70 and 140 miles per turn
    //update date
}

void Turn::hunt()
{
    //follows the hunt requirements from the writeup and coutns as a hunting turn
    // update date
    //hunt is successfull if user comletes puzzle
}

void quit()
{
    cout << "The trip was cut short and everyone was sad" << endl;
    //ends the game
}

bool puzzle()
{
    //computer generates a number and user has to guess it
}