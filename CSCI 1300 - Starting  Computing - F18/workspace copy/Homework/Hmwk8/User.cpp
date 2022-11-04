// CSCI1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: <https://ide.c9.io/feli0059/csci1300fl1>
// hmwk7

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "User.h"
using namespace std;

User::User()  // Default constructor
{
    username = ""; // assign username to an emptys tring
    numRatings = 0; // assign numRatings to 0
    size = 200; // assign seze to 200
    for (int i = 0; i < size; i++) // for loop to rin through the array
    {
        ratings[i] = -1; // assing every value in the array to -1
    }
}

User::User(string usernameA, int ratingsA[], int numRatingsA) // Parameterized constructor
{
    size = 200; // assign seze to 200
    username = usernameA; // assing username to usernameA
    for (int i = 0; i < size; i++) // for loop to run through the array
    {
        ratings[i] = ratingsA[i]; // assing every value from array ratings to array ratingsA
    }
    if (numRatingsA <= size) // if the size of arra ratingsA is less than or equal to the size fo the array
    {
        numRatings = numRatingsA; // assign numRatings to numratingsA
    }
}

string User::getUsername() // get username
{
    return username;
}

void User::setUsername(string usernameA) // ser username
{
    username = usernameA; // assign usernamer to usernameA
}

int User::getRatingAt(int index) // get ratings
{
    if (index < 0 || index >= 200) // is index is less than 0 or index is greater then or equal to 200
    {
        return -1; //  return -1
    }
    return ratings[index]; // return the ratings at every index
}

bool User::setRatingAt(int index,int value) // set rating
{
    if (index < 0 || index > size || value < 0 || value > 5) // if index is less than 0 or greater than size OR value is not in bewteen 0 and 5
    {
        return false; // return false
    }
    else 
    {
        ratings[index] = value; // assign the position at array ratings to value
        return true; // return true
    }
}

int User::getNumRatings() // get number of ratings
{
    return numRatings;
}

void User::setNumRatings(int numRatingsA) //set number of ratings
{
    numRatings = numRatingsA; //assign numRatings to nuRatingsA
}

int User::getSize() // get size
{
    return size;
}