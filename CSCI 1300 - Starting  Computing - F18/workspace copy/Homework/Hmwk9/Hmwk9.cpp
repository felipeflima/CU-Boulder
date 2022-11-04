#include <iostream>
//g++ -std=c++11 Store.cpp Status.cpp Turn.cpp Misfortunes.cpp Hmwk9.cpp

#include <iomanip>
//#include "Turn.h"
#include "Store.h"
//#include "Status.h"
//#include "Misfortunes.h"
using namespace std;

void beginningGame()
{
    cout << "Welcome to Oregon Trail! First enter your name!" << endl;
    string player1 = "";
    string player2 = "";
    string player3 = "";
    string player4 = "";
    string player5 = "";
    while (getline(cin, player1))
    {
        if (player1 == "")
        {
            cout << "Please enter a name at least one character long: ";
        }
        else 
        {
            cout << "Now enter the name of your four travelling companions" << endl;
            cout << "1. " << player1 << endl << "2. ";
            while (getline(cin, player2))
            {
                if (player2 == "")
                {
                    cout << "Please enter a name at least one character long: ";
                }
                else 
                {
                    cout << "3. ";
                    while (getline(cin, player3))
                    {
                        if (player3 == "")
                        {
                            cout << "Please enter a name at least one character long: ";
                        }
                        else 
                        {
                            cout << "4. ";
                            while (getline(cin, player4))
                            {
                                if (player4 == "")
                                {
                                    cout << "Please enter a name at least one character long: ";
                                }
                                else 
                                {
                                    cout << "5. ";
                                    while (getline(cin, player5))
                                    {
                                        if (player5 == "")
                                        {
                                            cout << "Please enter a name at least one character long: ";
                                        }
                                        else 
                                        {
                                            return;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

    // cout << "Now enter the name of your four travelling companions" << endl;
    // cout << "1. " << player1 << endl << "2. ";
    // getline(cin, player2);
    // cout << "3. ";
    // getline(cin, player3);
    // cout << "4. ";
    // getline(cin, player4);
    // cout << "5. ";
    // getline(cin, player5);
    
void dateTrip()
{
    cout << "Now you must choose a start date for your trip. Would you like to start on the default start date of 03/28/1847 or to choose a different departure date between 03/01/1847 and 05/01/1847?" << endl;
    cout << "1. Default date" << endl << "2. Choose date" << endl;
    int x = 0;
    int day = 0;
    int month1 = 0;
    while (cin >> x)
    {
        switch (x)
            {   
                case 1: 
                    cout << "You're starting your trip on 03/28/1847!" << endl;
                    return;
                case 2: 
                    cout << "When would you like to departure for your trip? You have to leave between 03/01/1847 and 05/01/1847!" << endl;
                    cout << "Insert month: ";
                    while (cin >> month1)
                    {
                        if (month1 >= 3 && month1 <=5)
                        {
                            if (month1 == 3 || month1 == 5)
                            {
                                cout << "Now enter the day" << endl;
                                while (cin >> day)
                                {
                                    if (day >= 1 && day <= 31)
                                    {
                                        cout << "You and your companions are departuring on " << month1 << "/" << day << "/1847!" << endl;
                                        return;
                                    }
                                    else 
                                    {
                                        cout << "Invalid input. Please input a number between 1 and 31." << endl;
                                    }
                                }
                            }
                            else
                            {
                                cout << "Now enter the day" << endl;
                                while (cin >> day)
                                {
                                    if (day >= 1 && day <= 30)
                                    {
                                        cout << "You and your companions are departuring on " << month1 << "/" << day << "/1847!" << endl;
                                        return;
                                    }
                                    else 
                                    {
                                        cout << "Invalid input. Please input a number between 1 and 30." << endl;
                                    }
                                }
                            }
                        }
                        else
                        {
                            cout << "Invalid input. Please input a number between 3 and 5." << endl;
                        }
                    }
                    break;
                default:
                    cout << "Invalid input, please select option number 1 or option number 2." << endl;
                    break;
                    
            }
    }
}



void messages()
{
    cout << "You and you're companions are travelling from Independence Missouri to Oregon City. The way is 2,040 miles";
}

int main()
{
    Store store;
    
    beginningGame();
    dateTrip();
    store.storeInstructions();
    store.choiceBuy();
    
}