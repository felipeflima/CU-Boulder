#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Store.h"
using namespace std;

Store::Store()
{
    money = 1000;
    bill = 0;
    yokes = 0;
    food = 0;
    bullets = 0;
    wheels = 0;
    axles = 0;
    tongues = 0;
    storeVisit = 0;
}

void Store::storeInstructions()
{
    cout << "WELCOME TO THE STORE!" << endl;
    cout << "YOU HAD SAVED $1200 TO SPEND FOR THE TRIP, AND YOU'VE JUST PAID $200 FOR A WAGON. YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS:" << endl;
    cout << "- OXEN. YOU CAN SPEND $100-$200 ON YOUR TEAM. THE MORE YOU SPEND, THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS" << endl;
    cout << "- FOOD. THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK" << endl;
    cout << "- AMMUNITION - YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND BANDITS, AND FOR HUNTING FOOD" << endl;
    cout << "- MISCELLANEOUS SUPPLIES. THIS INCLUDES MEDICINE AND OTHER THINGS YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS" << endl;
    cout << "YOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW. HOWEVER, ITEMS COST MORE AT THE FORTS. YOU CAN ALSO GO HUNTING ALONG THE WAY TO GET MORE FOOD." << endl;
}

int Store::choiceBuy()
{
    cout << "What would you like to buy?" << endl;
    cout << "1. Oxen" << endl << "2. Food" << endl << "3. Bullets" << endl << "4. Miscellaneous Supplies" << endl << "5. Exit store" << endl;
    int x = 0;
    while (x != 5)
    {
        cin >> x;
        switch(x)
        // return a number and if statements on the driver if statements decide what function to call corresponding to the statement above
        {
            case 1: 
                buyOxen();
                cout << "1. Oxen" << endl << "2. Food" << endl << "3. Bullets" << endl << "4. Miscellaneous Supplies" << endl << "5. Exit store" << endl;
                break;
            case 2: 
                buyFood();
                cout << "1. Oxen" << endl << "2. Food" << endl << "3. Bullets" << endl << "4. Miscellaneous Supplies" << endl << "5. Exit store" << endl;
                break;
            case 3: 
                buyBullets();
                cout << "1. Oxen" << endl << "2. Food" << endl << "3. Bullets" << endl << "4. Miscellaneous Supplies" << endl << "5. Exit store" << endl;
                break;
            case 4: 
                buyMiscellaneous();
                break;
            case 5:
                cout << "Good bye!" << endl;
                break;
            default:
                    cout << "invalid input" << endl;
                    cout << endl;
        }
    }
}

//before each purchase check is the user has the money necessary to by an item.

int Store::buyOxen()
{
    cout << "There are 2 oxen in a yoke and the price of each yoke is $40." << endl;
    cout << "How many yokes do you wich to purchase? - You must spend between $100 and $200 dollars on oxen" << endl;
    cout << "If you wish to exit type 0" << endl;
    int oxen = -1;
    cin >> oxen;
    while (oxen != 0)
    {
        if (oxen >= 3 && oxen <= 5)
        {
            yokes = oxen;
            bill += oxen * 40;
            if (bill > money)
            {
                bill = bill - (oxen * 40);
                cout << "You don't have enough money to buy that many yokes!" << endl;
            }
            else 
            {
                cout << "You bought " << oxen << " yokes / " << oxen * 2 << " oxen." << endl;
            }
            cout << "Current bill: " << bill << endl;
            return oxen;
        }
        else
        {
            cout << "Invalid input. You must spend between $100 and $200 dollars on oxen (3 to 5 yokes)" << endl;
            cin >> oxen;
        }
    }
}
    // sets that the player must spend between $100 and $200 dollars on oxen, inclusive.
    // create a user input value for the number of yokes
    // user input the number of yokes they wish to purchase
    // if user inputs 0, exit oxen store
    // set yokes equal to number of yokes bought 
    // prints a confirmation message (you're about the buy x yokes for y dollars, do you want to continue?)
    // prints out bill at the end (initial balence, amount spent, final balance)
    // returns the number of yokes bought

int Store::buyFood()
{
    cout << "The food is 50 cents per pound! How many pounds do you wish to purchase?" << endl;
    cout << "Hint: It is recommended that you buy at least 200 lbs. of food per person" << endl;
    cout << "If you wish to exit type 0" << endl;
    cin >> food;
    while (food != 0)
    {
        if (food < 0)
        {
            cout << "Invalid input. Please enter a positive number." << endl;
            cin >> food;
        }
        else 
        {
            bill += food * 0.50;
            if (bill > money)
            {
                bill = bill - (food * 0.5);
                cout << "You don't have enough money to buy that many pounds of food!" << endl;
            }
            else
            {
                cout << "You bought " << food << " pounds of food!" << endl;
            }
            cout << "Current bill: " << bill << endl;
            return food;
        }
    }
    
    // creates an input value for the number of pounds the user wishes to purhcase
    // user inputs the number of pounds they wish to purchase
    // if user inputs 0, exit food store
    // set food equal to number of pounds bought 
    // prints out bill at the end (initial balence, amount spent, final balance)
    // returns the number of pounds of food bought
    
}
int Store::buyBullets()
{
    cout << "A box of 20 bullets costs $2. How many boxes do you wish to purchase?" << endl;
    cout << "If you wish to exit type 0" << endl;
    cin >> bullets;
    while (bullets != 0)
    {
        if (bullets < 0)
        {
            cout << "Invalid input. Please enter a positive number." << endl;
            cin >> bullets;
        }
        else 
        {
            bill += bullets * 2;
            if (bill > money)
            {
                bill = bill - (bullets * 2);
                cout << "You don't have enough money to buy that many boxes of bullets!" << endl;
            }
            else
            {
                cout << "You bought " << bullets << " boxes of bullets!" << endl;
            }
            cout << "Current bill: " << bill << endl;
            return bullets;
        }
    }
    
    // creates an input value for the number of boxes the user wishes to purhcase
    // user inputs the number of boxes they wish to purchase
    // if user inputs 0, exit bullets store
    // set bullets equal to number of boxes bought times 20
    // prints out bill at the end (initial balence, amount spent, final balance)
    // returns the number of pounds of boxes bought
}
int Store::buyMiscellaneous()
{
    cout << "What would you like to purchse?" << endl;
    cout << "1. Wagon parts" << endl << "2 . Medical aid kit" << endl << "3. Exit store" << endl;
    int x = 0;
    cin >> x;
    while (x != 3)
    {
        switch(x)
        {
            case 1:
                cout << "Spare wagon parts. Always good to have a backup" << endl;
                cout <<  "wheel - $10" << endl << "axle - $10" << endl << "tongue - $10" << endl;
                // creates an input value for the number of parts the user wishes to purhcase
                cout << "How many wheels do you wish to purchase?" << endl;
                // user input number
                // set wheels equal to number of wheels bought
                cout << "How many axles do you wish to purchase?" << endl;
                //user input number
                // set axles equal to the number of axles bought
                cout << "How many tongues do you wish to purchase?" << endl;
                // user input number 
                // set tongues equal to number of tongues bought
                // prints out bill at the end (initial balence, amount spent, final balance)
                // returns the number of pounds of parts separately bought
                break;
            case 2:
                cout << "A medical aid kit costs $25. How many kits do you wish to purchase." << endl;
                 // creates an input value for the number of kits the user wishes to purhcase
                 // user inputs the number of boxes they wish to purchase
                 // prints out bill at the end (initial balence, amount spent, final balance)
                 // returns the number of pounds of kits bought
                break;
            case 3:
                cout << "Exit store" << endl;
                break;
            default:
                    cout << "invalid input" << endl;
                    cout << endl;
        }
    }
}

int Store::getYokes()
{
    return yokes;
}

int Store::getFood()
{
    return food;
}

int Store::getBullets()
{
    return bullets;
}

int Store::getWheels()
{
    return wheels;
}

int Store::getAxles()
{
    return axles;
}

int Store::getTongues()
{
    return tongues;
}

// every time it exits the store add 1 to store visit to keep track of what store they are visiting and increase the price respectively