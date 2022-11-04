// CSCI1300 Fall 2018
// Author: <Your name>
// Recitation: <202> – <John Klingner>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/feli0059/csci1300fl1>
// Project1 

/*
    Print "Welcome to Jeopardy Dice!"
    1st turn is always human:
        print "It is now human's turn"
        create a varibale to store the value of each turn
        print "Do you want to roll a dice (Y/N)?:"
        create a varible for the decision 
        while the user is answering yes:
            roll the dice
            if it rolls 2 or 4 or 5
                print "You rolled a " number rolled
                print "Your turn total is " number rolled plus stored value for previous rolls on the same round
                ask the user if they want to roll the dice again -- this will repeat the process
            if it rolls a 3
                print "You rolled a " number rolled
                print "Your turn total is " number rolled plus stored value for previous rolls on the same round
                assing the value of the round to 15 and finish the turn
                return the turn value to the total value
            if it rolls 1 or 6
                print "You rolled a " number rolled
                print "Your turn total is " number rolled plus stored value for previous rolls on the same round
                assing the value of the round to 0 and finish the turn
                return the turn value to the total value
        if the user answesrs no
            return the turn value to the total value
        finish human's turn
        display score
    computer's turn
        print "It is now human's turn"
        create a varibale to store the value of each roll
        create a loop so when the score is greater than 10 it ends the computer's turn
        roll the dice
            if it rolls 2 or 4 or 5
                print "Computer rolled a " number rolled
                print "Computer turn total is " number rolled plus stored value for previous rolls on the same round
                ask the user if they want to roll the dice again -- this will repeat the process
            if it rolls a 3
                print "Computer rolled a " number rolled
                print "Computer turn total is " number rolled plus stored value for previous rolls on the same round
                assing the value of the round to 15 and finish the turn
                return the turn value to the total value
            if it rolls 1 or 6
                print "Computer rolled a " number rolled
                print "Computer turn total is " number rolled plus stored value for previous rolls on the same round
                assing the value of the round to 0 and finish the turn
                return the turn value to the total value
            end computer turn
            display score
    create a loop around human's turn and computer turn so they keep repeating until one of the total scores reaches 100
    print "Congratulations! human won this round of jeopardy dice!" or "Congratulations! computer won this round of jeopardy dice!" -- 
         --depending on who reched the score of 100 first
            
    
                
    
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std; 

// funtion that generates random number between 1 and 6 for the dice
int rollDice()
{
	return random() % 6 + 1; 
}

// function modifies and stores the human score and displays the scores at the end of each human turn
int total_human(int x, int humanT, int computerT) // passes three variables and returns one
{
    humanT += x; // modifies the current score for the human
    cout << "computer: " << computerT << endl; // displays the score for the computer
    cout << "human: " << humanT << endl << endl; // displays the score for the human
    return x; // return x

}

// function modifies and stores the computer score and displays the scores at the end of each computer turn
int total_computer(int y, int humanT, int computerT) // passes three variables and returns one
{
    computerT += y; // modifies the current score for the human
    cout << "computer: " << computerT << endl; // displays the score for the computer
    cout << "human: " << humanT << endl << endl; // displays the score for the human
    return y; // return y
}

// funtion for the turn of the human -- lays out every step for the human's turn
int turnH(int humanT, int computerT) //passes three variables and returns one
{
    cout << "It is now human's turn" << endl << endl; // output message
    int rollT = 0; //create variable to store the value of each turn and initially assign it to 0 
    char decision; // creating variable for the decision to roll the dice
    cout << "Do you want to roll a dice (Y/N)?:" << endl;  // output message
    cin >> decision; // user input for the decision to roll the dice
    while (decision == 'y' || decision == 'Y') // while the decision to roll the dice is yes
    {
        int roll = rollDice(); // roll the dice and store the value of the roll as roll
        if (roll == 2 || roll == 4 || roll == 5) // if the dice rolls to 2,4 or 5
        {
            cout << "You rolled a " << roll << endl; // output message
            rollT += roll; //store the value of each turn (past rolls plus current roll)
            cout << "Your turn total is " << rollT << endl; // output message
            cout << "Do you want to roll again (Y/N)?:" << endl; // output message
            cin >> decision; // user input for the decision
        }
        else if (roll == 3) // if the dice rolls 3
        {
            cout << "You rolled a " << roll << endl; // output message
            cout << "Your turn total is 15" << endl; // output message
            rollT = 15; // set the value of the rolls for the turn to 15 
            decision = 'n'; // end turn
        }
        else // if dice rolls any other number (1 or 6)
        {
            cout << "You rolled a " << roll << endl; // output message
            cout << "Your turn total is 0" << endl; // output message
            rollT = 0; // set the value of the rolls for the turn to 0
            decision = 'n'; // end turn
        }
    }
       int a = total_human(rollT, humanT, computerT); // create variable a and assign it to call the total_human function
       return a; // return a
}

// funtion for the turn of the human -- lays out every step for the human's turn
int turnC(int humanT , int computerT) //passes three variables and returns one
{
    cout << "It is now computer's turn" << endl << endl; // output message
    int rollTC = 0; //create variable to store the value of each turn and initially assign it to 0 
    int k = 0; // create variable to exit the while loop
    while (rollTC < 10 && k == 0) // while the total score for the turn is less than 10 and k equals to 0
    {
        int roll = rollDice(); // roll the dice
        if (roll == 2 || roll == 4 || roll == 5) // if the dice rolls to 2,4 or 5
        {
            cout << "Computer rolled a " << roll << endl; // output message
            rollTC += roll; //store the value of each turn (past rolls plus current roll)
            cout << "Computer turn total is " << rollTC << endl; // output message
            k = 0; // k = 0 so the computer rolls the dice again
        }
        else if (roll == 3) // if the dice rolls 3
        {
            cout << "Computer rolled a " << roll << endl; // output message
            cout << "Computer turn total is 15" << endl; // output message
            rollTC = 15; // set the value of the rolls for the turn to 15
            k = 1; // k = 1 so the turn ends
        }
        else if (roll == 1 || roll == 6) // if dice rolls 1 or 6
        {
            cout << "Computer rolled a " << roll << endl; // output message
            cout << "Computer turn total is 0" << endl; // output message
            rollTC = 0; // set the value of the rolls for the turn to 0
            k = 1; // k = 1 so the turn ends
        }
    }
    return total_computer(rollTC, humanT, computerT); // return the call to the total_computer function
}

// function displays the final messages of the game
void end_game(int humanT, int computerT) // function takes in 2 parameters and returns nothing
{
     if (humanT >= 100) // in the human's score is greater than or equal to 100
    {
        cout << "Congratulations! human won this round of jeopardy dice!" << endl; // output message -- congratulations/final message
    }
    else if (computerT >= 100) // in the computer's score is greater than or equal to 100
    {
        cout << "Congratulations! computer won this round of jeopardy dice!" << endl; // output message -- congratulations/final message
    }
}

// game function -- coordinates what functions to call and display initial message
void game() // void function
{
    cout << "Welcome to Jeopardy Dice!" << endl << endl; // output message -- welcome message
    int humanT = 0; // createv ariable for the human's score and assigns its initial value to 0
    int computerT = 0; // createv ariable for the co computer's score and assigns its initial value to 0
    while (humanT < 100 && computerT < 100) // while both the scores are under 100
    {
        humanT += turnH(humanT , computerT); // calls the human's turn function and updates the human's score
        if (humanT < 100 && computerT < 100) // if both socres are under 100
        {
            computerT += turnC(humanT , computerT); // calls the computer's turn function and updates the computer's score
        }
    }
    end_game(humanT, computerT); // calls endgame function
}

// main function -- runs program
int main()
{
	game(); // calls game function
	return 0; // returns 0
}