#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Library.h"
#include "Book.h"
#include "User.h"
using namespace std;

Library::Library()
{
    numBooks = 0;
    numUsers = 0;
}

int split (string str, char c, string array[], int size)
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
 }

int Library::readBooks(string filename)
{
    ifstream myfilestream; // create a file stream for reading to file
    myfilestream.open(filename); // open the file 
    if (myfilestream.is_open()) // if the file is open
    {
            string line = ""; // assign string line to ""
            while (getline(myfilestream, line)) // read in an entire line from myfilestream and set line equal to its contents.
            {
                if (numBooks < 200){
                Book authorTitle; // instantiate a User object,
                string temp[2]; // creates temporary array
                split(line, ',', temp, 2); // calls split function
                if (line != "") // if line is not empty
                {
                authorTitle.setAuthor(temp[0]); // assign the line to the array at index 0
                authorTitle.setTitle(temp[1]); // assign the line to the array at index 1
                books[numBooks] = authorTitle; // 
                numBooks++; // increment numBooks
                }
                }
            }
    }
    else // if non of the consitions above are met
    {
        return -1; // return -1
    }
    return numBooks; // return numBooks
}

int Library::readRatings(string filename)
{
    int count = 0; // create variable count and assign it to 0
    ifstream myfilestream; // create a file stream for reading to file
    myfilestream.open(filename); // open the file 
    if (myfilestream.is_open()) // if the file is open
    {
        string line = ""; // assign string line to ""
        while (getline(myfilestream, line)) // read in an entire line from myfilestream and set line equal to its contents.
        {
            User object;
            string temp[2]; // creates a temporary array
            split(line, ',', temp, 2); // calls the split function
            if (line != "") // if line is not empty
            {
                if (numUsers < 200){
                    object.setUsername(temp[0]); // assign the line as an integer to the array
                    users[numUsers].setUsername(temp[0]);
                    cout << temp[0] << "..." << endl;
                    string temp2[200]; // creates temporary array
                    split (temp[1], ' ', temp2, 200); // calls split fuction
                    for (int i = 0; i < 200; i++) // for loop to run through the array
                    {
                        if (temp2[i] != "") // if temp2 at postion i is not an empty string
                        {
                            users[numUsers].setRatingAt(i, stoi(temp2[i])); // assign the line as an integer to the array
                           
                        }
                    }
                    numUsers++; // increment numUsers
                }
                if (object.getNumRatings() != -1) // if the number of Ratings in the array does not equal 0
                {
                    count++; // increment count
                }
            }
        }
    }
    else // if none of the consitions above are met
    {
        return -1; // return -1
    }
    return numUsers; // return numUsers
}

void Library::printAllBooks()
{
    if (numBooks == 0) // if the number of books is zero or the first index of authors is empty
    {
        cout << "Database has not been fully initialized" << endl; // print "No books are stored"
    }
    else // if the condition above is not met
    {
        cout << "Here is a list of books" << endl; // print "Here is a list of books"
        for (int i = 0; i < numBooks; i++) // for loop to run through the array
        {
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl; // prints a list of the books "by" the author
        }
    }
}

int findUser (string username, User users[200], int numUsers)
{
    for (int i = 0; i < numUsers; i++) // for loop to run throughthe array
    {
        if (users[i].getUsername() == username) // if any index in the array is equal to the username typoed by the user
        {
            return i; // return the index
        }
    }
    return -1; // returns negative one if the index is not found
}

int Library::getCountReadBooks(string username)
{
    if (numBooks == 0 && numUsers > 0)
    {
        cout << "Database has not been fully initialized" << endl;
        return -1;
    }
    else if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        return -1;
    }
    int index = findUser (username, users, numUsers);
    if (index == -1)
    {
        cout << username << " does not exist in the database" << endl;
        return -2;
    }
    else 
    {
        if (index == -1)
        {
            cout << username << " does not exist in the database" << endl;
        }
        else
        {
            int count = 0;
            for (int i = 0; i < numBooks; i++)
            {
                if (users[index].getRatingAt(i) != 0 && users[index].getRatingAt(i) != -1)
                {
                    count ++;
                }
            }
            if (count != 0){
            }
            return count;
        }
        
    }
}


int findBookReview (string bookTitle, int numBooks, Book books[200])
{
    for (int i = 0; i < numBooks; i++)
    {   
        if (books[i].getTitle() == bookTitle)
        {
            return i;
        }
    }
    return -1;
}

double Library::calcAvgRating(string bookTitle)
{
    if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        return -1;
    }
    int index = findBookReview (bookTitle, numBooks, books);
    if (index == -1)
    {
        cout << bookTitle << " does not exist in the database" << endl;
        return -2;
    }
    else
    {
        int count = 0;
        double avg = 0;
        for (int i = 0; i < numUsers; i++)
        {
            if (users[i].getRatingAt(index) != 0)
            {
                count++;
                avg += users[i].getRatingAt(index);
            }
        }
        avg = avg/count;
        return avg;
    }
}

bool Library::addUser(string username)
{
    string temp = "";
    for (int i = 0; i < username.length(); i++)
    {
        temp +=  tolower(username[i]);
    }
    for (int i = 0; i < numUsers; i++)
    {
        if (username == users[i].getUsername())
        {
            cout << username << " already exists in the database" << endl;
            return false;
        }
    }
    if (numBooks == 200)
    {
        cout << "Database full" << endl;
        return false;
    }
    else
    {
        users[numUsers].setUsername(username);
        numUsers++;
        return true;
    }
}

bool Library::checkOutBook(string username, string bookTitle, int newRating)
{
    bool foundUser = 0;
    bool foundBook = 0;
    int userIndex = -1;
    int bookIndex = -1;
    for (int i = 0; i < numUsers; i++)
    {
        if (username == users[i].getUsername())
        {
            foundUser = 1;
            userIndex = i;
        }
    }
    for (int i = 0; i < numBooks; i++)
    {
        if (bookTitle == books[i].getTitle())
        {
            foundBook = 1;
        }
    }
    if ((numBooks == 0 || numUsers == 0) || (foundUser != 1) || (newRating < 0 || newRating > 5) || (foundBook != 1))
    {
        if (numBooks == 0 || numUsers == 0)
        {
            cout << "Database has not been fully initialized" << endl;
        }
        if (foundUser != 1)
        {
            cout << username << " does not exist in the database" << endl;    
        }
        if (foundBook != 1)
        {
            cout << bookTitle << " does not exist in the database" << endl;
        }
        if (newRating < 0 || newRating > 5)
        {
            cout << newRating << " is not valid" << endl;
        }
        return false;
    }
    for (int i = 0; i < numBooks; i++)
    {
        if (bookTitle == books[i].getTitle())
        {
            bookIndex = i;
        }
    }
    users[userIndex].setRatingAt(bookIndex, newRating);
    return true;
}

void Library::viewRatings(string username)
{
    bool foundUser = 0;
    int userIndex = -1;
    bool booksRated = 0;
    if ((numBooks == 0 || numUsers == 0) && (foundUser != 1))
    {
        cout << "Database has not been fully initialized" << endl;
        cout << username << " does not exist in the database" << endl;
        return;
    }
    if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        return;
    }
    for (int i = 0; i < numUsers; i++)
    {
        if (username == users[i].getUsername())
        {
            foundUser = 1;
            userIndex = i;
        }
    }
    if (foundUser != 1)
    {
        cout << username << " does not exist in the database" << endl;
        return;
    }
    for (int i = 0; i < numBooks; i++)
    {
        if (users[userIndex].getRatingAt(i) != 0 &&  users[userIndex].getRatingAt(i) != -1)
        {
            booksRated = 1;
        }
    }
    if (booksRated == 1)
    {
        cout << "Here are the books that " << username << " rated" << endl;
        for (int i = 0; i < numBooks; i++)
        {
            if (users[userIndex].getRatingAt(i) != 0 &&  users[userIndex].getRatingAt(i) != -1)
            {
                cout << "Title: " << books[i].getTitle() << endl;
                cout << "Rating: " << users[userIndex].getRatingAt(i) << endl;
                cout << "-----" << endl;
            }
        }
    }
    else if (booksRated == 0)
    {
        cout << username << " has not rated any books yet" << endl;
        return;
    }
}

void Library::getRecommendations(string username)
{
    bool foundUser = 0;
    int userIndex = -1;
    bool booksRated = 0;
    if ((numBooks == 0 || numUsers == 0) && (foundUser != 1))
    {
        cout << "Database has not been fully initialized" << endl;
        cout << username << " does not exist in the database" << endl;
        return;
    }
    if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        return;
    }
    for (int i = 0; i < numUsers; i++)
    {
        if (username == users[i].getUsername())
        {
            foundUser = 1;
            userIndex = i;
        }
    }
    if (foundUser != 1)
    {
        cout << username << " does not exist in the database" << endl;
        return;
    }
}