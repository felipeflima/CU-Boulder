// CSCI1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: <https://ide.c9.io/feli0059/csci1300fl1>
// hmwk7

#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User
{
    public:
        User(); // default constructor
        User(string, int*, int); // constructor
        string getUsername(); 
        void setUsername(string);
        int getRatingAt(int);
        bool setRatingAt(int,int);
        int getNumRatings();
        void setNumRatings(int);
        int getSize();
    
    private:
        string username;
        int ratings[200];
        int numRatings;
        int size;
};

#endif