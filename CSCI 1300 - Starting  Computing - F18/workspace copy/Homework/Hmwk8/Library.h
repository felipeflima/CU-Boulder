// CSCI1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: <https://ide.c9.io/feli0059/csci1300fl1>
// hmwk8

#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "User.h"
#include <iostream>
using namespace std;

class Library
{
    public:
        Library();
        int readBooks(string);
        int readRatings(string);
        void printAllBooks();
        int getCountReadBooks(string);
        double calcAvgRating(string);
        bool addUser(string);
        bool checkOutBook(string, string, int);
        void viewRatings(string);
        void getRecommendations(string);
        
    
    
    private:
        Book books[200];
        User users[200];
        int numBooks;
        int numUsers;
        int sizeBook;
        int sizeUser;
    
};

#endif

