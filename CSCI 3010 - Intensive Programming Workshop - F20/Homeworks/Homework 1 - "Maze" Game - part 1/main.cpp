/* CSCI 3010 - IPW
* Felipe Lima
* Homework 1 - "Maze" Game - part 2
* 09/18/2020
* Fun-ish maze game. User controls the player and the enemies and tries to reach the exit with the human
* How to run: using Makefile
~make
~./maze
*/
#include <iostream>
#include <vector>
#include "Player.h"
#include "Maze.h"

/*
In roder to improve the game for part 2, I chose to do numbers 2 and 3. Adding one trap and one treasure.
*/



/**
 * Just greets the player and calls Maze() to initialize the game
 */ 
int main()
{
    std::cout << "Hello and welcome to the \"Maze\" Game!" << std::endl << "Your objective is to reach the exit without being eliminated by the zombies!" << std::endl;
    std::cout << "Here are the rules: " << std::endl;
    std::cout << "* Human is the man, Walls are represented by X, Exit is the checkmark, Enemies are the zombies, Trap is fire, Treasure are the genies, and Moon is the superpower." << std::endl;
    std::cout << "* You can move in the vertical and horizontal. No diagonal moves are allowed." << std::endl;
    std::cout << "* The current player will earn 100 points each time they collect a treasure (genie)." << std::endl;
    std::cout << "* If an enemy moves onto a square with the human on it, the human is destroyed. If the human moves onto a square with an enemy on it, the human is destroyed." << std::endl;
    std::cout << "* If an enemy moves to a square with another enemy, neither player moves and the turn is forfeited. (Hint: think of this as the enemy \"doing nothing\")." << std::endl;
    std::cout << "* If an enemy walks into the fire, the fire is out and path is clear for the human. Nothing happens to the zombie." << std::endl;
    std::cout << "* If the human walks into the moon, he becomes a warewolf and gets 150 extra points." << std::endl;
    std::cout << "* If a zombie walks into a moon, the moon disappears and it gets 150 extra points." << std::endl;
    std::cout << "* If the human or wolf walks into the fire the game is over and the player loses. " << std::endl;
    std::cout << "* The game ends when the player successfully reaches the exit or the enemies destroy the human." << std::endl;
    std::cout << "Here is your maze and good luck!" << std::endl;
    Maze();
}