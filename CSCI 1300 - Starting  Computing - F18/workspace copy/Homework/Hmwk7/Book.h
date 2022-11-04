// CSCI1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: <https://ide.c9.io/feli0059/csci1300fl1>
// hmwk7

#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;

class Book
{
    public:
        Book();
        Book(string, string);
        string getTitle();
        void setTitle(string);
        string getAuthor();
        void setAuthor(string);
    
    private:
        string title;
        string author;
};

#endif