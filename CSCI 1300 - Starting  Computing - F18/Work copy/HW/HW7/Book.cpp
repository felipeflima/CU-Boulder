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
#include "Book.h"
using namespace std;

Book::Book() // Default constructor
{
    title = ""; // assign title to an empty string 
    author = ""; // assign author to an empty string 
}

Book::Book(string titleA, string authorA) // Parameterized constructor
{
    title = titleA; // assign title to titleA
    author = authorA; // assign author to authorA
}

string Book::getTitle() // get the title
{
    return title;
}

void Book::setTitle(string titleA) // set the title
{
    title = titleA; // assign title to titleA
}

string Book::getAuthor() // get author
{
    return author;
}

void Book::setAuthor(string authorA) // set author
{
    author = authorA; // assign author to authorA
}