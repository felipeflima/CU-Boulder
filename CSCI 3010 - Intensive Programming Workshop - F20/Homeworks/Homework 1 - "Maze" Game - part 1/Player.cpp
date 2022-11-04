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
#include "Player.h"

/**
 * constructs a player assigning a name, whether or not it is human, a position, points
 * @param name of the player, whether or not it is human, the number of the enemy to be constructed, and the position of the player
*/
Player::Player(const std::string name, const bool is_human, int enemy_num, Position pos_player){
    is_human_ = is_human; 
    pos_ = pos_player;
    name_ = name;
    points_ = 0;
}

/**
 * Updates the points of the player by updating “points_” with the value passed in the function
 * @param amount of points to be added to the pleyer
*/
void Player::ChangePoints(const int x){
    points_ += x;
}  

/**
 * Sets a new position for the player by updating the value of “pos_” with the value passed in the function.
 * @param new position of the player
 */ 
void Player::SetPosition(Position pos){
    pos_ = pos;
}

/**
 * Compares current position of the player with position passed into the function and returns a direction (i.e. “Up”, “down” etc.)
 * @param the position being compared to the position of the player
 * @return the direction as a string
 */ 
std::string Player::ToRelativePosition(Position other){
    std::string direction = "";
    if (other.row == pos_.row+1 && other.col == pos_.col){
        direction = "Down";
    }
    else if (other.row == pos_.row-1 && other.col == pos_.col){
        direction = "Up";
    }
    else if (other.row == pos_.row && other.col == pos_.col+1){
        direction = "Right";
    }
    else if (other.row == pos_.row && other.col == pos_.col-1){
        direction = "Left";
    }
    else {direction = "not a valid direction";}
    return direction;
}

/**
 * Converts this instance of “Player” into a string representing its name and points
 * @return string saying “Player had x points”
 */ 
std::string Player::Stringify(){
    std::string stringify = name_ + " has " + std::to_string(points_)+ " points. ";
    return stringify;
}