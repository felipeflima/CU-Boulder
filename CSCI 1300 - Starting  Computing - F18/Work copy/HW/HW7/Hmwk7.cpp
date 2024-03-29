// CSCI1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: <https://ide.c9.io/feli0059/csci1300fl1>
// hmwk7
// debugging help from Sarah Lundell

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Book.h"
#include "User.h"
using namespace std;


/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu(){
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Read book file" << endl;
  cout << "2. Read user file" << endl;
  cout << "3. Print book list" << endl;
  cout << "4. Find number of books user rated" << endl;
  cout << "5. Get average rating" << endl;
  cout << "6. Quit" << endl;
}


/* split function
 * the function to split the given string into array of string with respect to a delimiter
 *
 * @param : string , the string we are going to split
 * @param : char, the delimiter
 * @param : string array, the array of string we save after spliting
 * @param : int, size of the  indicates the maximum number of split-apart string pieces
*/
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


/* readBooks function
 * the function reads a book file from the text into book and author arrays
 *
 * @param: string, the name of the file to be read
 * @param: array of User objects: user data
 * @param: string array, authors
 * @param: int: number of users currently stored in the array of User object
 * @param: int: the capacity of the user array 
 */
int readBooks (string filename, Book booksData[], int booksCurrentlyStored, int capacity)
{
    int lineidx = booksCurrentlyStored; // create variable
    ifstream myfilestream; // create a file stream for reading to file
    myfilestream.open(filename); // open the file 
    if (myfilestream.is_open()) // if the file is open
    {
        string line = ""; // assign string line to ""
        while (getline(myfilestream, line)) // read in an entire line from myfilestream and set line equal to its contents.
        {
            Book authorTitle; // instantiate a User object,
            string temp[2]; // creates temporary array
            split(line, ',', temp, 2); // calls split function
            if (line != "") // if line is not empty
            {
            authorTitle.setAuthor(temp[0]); // assign the line to the array at index 0
            authorTitle.setTitle(temp[1]); // assign the line to the array at index 1
            booksData[lineidx] = authorTitle; // 
            lineidx++; // increment lineidx
            }
        }
    }
    else // if non of the consitions above are met
    {
        return -1; // return -1
    }
    return lineidx; // return lineidx
}


/* readRatings function
 * Read the user ratings from the file and store them
 * into users array and ratings array
 *
 * @param: string, the name of the file to be read
 * @param: string array, usernames
 * @param: 2D int array, list of ratings for each user (first index specifies user)
 * @param: int, the number of users currently stored in the array
 * @param: int, row capacity of the 2D array (convention: array[row][column]) [assume to be 100]
 * @param: int, column capacity of the 2D array [assume to be 50]
 * @return: the number of users in total
 */
 int readRatings (string filename, User userData[], int usersCurrentlyStored, int capacity) 
{
    int count = 0; // create variable count and assign it to 0
    int lineidx = usersCurrentlyStored; // create variable
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
                object.setUsername(temp[0]); // assign the line as an integer to the array
                userData[lineidx].setUsername(temp[0]);
                cout << temp[0] << "..." << endl;
                string temp2[200]; // creates temporary array
                split (temp[1], ' ', temp2, 200); // calls split fuction
                for (int i = 0; i < 200; i++) // for loop to run through the array
                {
                    if (temp2[i] != "") // if temp2at postion i is not an empty string
                    {
                        userData[lineidx].setRatingAt(i, stoi(temp2[i])); // assign the line as an integer to the array
                       
                    }
                }
                lineidx++; // increment lineidx
            }
            if (object.getNumRatings() != -1) // if ht number of ratings in the array does not equal 0
            {
                count++; // increment count
            }
        }
    }
    else // if none of the consitions above are met
    {
        return -1; // return -1
    }
    // for (int i = 0; i < 200; i++)
    // {
    //      userData[i].setNumRatings(lineidx);
    // }
    return lineidx; // return lineidx
}

void printAllBooks (Book booksData[], int booksCurrentlyStored) // prints all the books in the titles array
{
    if (booksCurrentlyStored == 0) // if the number of books is zero or the first index of authors is empty
    {
        cout << "No books are stored" << endl; // print "No books are stored"
    }
    else // if the condition above is not met
    {
        cout << "Here is a list of books" << endl; // print "Here is a list of books"
        for (int i = 0; i < booksCurrentlyStored; i++) // for loop to run through the array
        {
            cout << booksData[i].getTitle() << " by " << booksData[i].getAuthor() << endl; // prints a list of the books "by" the author
        }
    }
}

int main(int argc, char const *argv[]) {
    Book booka[200];
    User usera[200];
    string choice;
    int numBooks = 0; // number of books
    int numUsers = 0; // number of users
    
    string titles[50]; // titles array
    string authors[50]; // authors array
    string filename; // name of the file the fuction is reading
    
    string users[100]; // users
    int ratings[100][50]; // ratings
    
    string username; // username inoput by the user
    int booksRead = 0; // number of books read
    
    string title; // name of the book input by the user
    double average = 0; // variable for the average of the ratings of the books

    while (choice != "6") {
            displayMenu();
            cin >> choice;
            switch (stoi(choice)) {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    
                    cin >> filename; // user inputs the name of the file and it is assigned to filename
                    numBooks = readBooks(filename, booka, numBooks, 200); // number of books is assigned to the value the funtion readBooks return
                    if (numBooks == -1) // if the number of books is -1 (returned by the fuiction)
                    {
                        cout << "No books saved to the database" << endl; // print "No books saved to the database"
                    }
                    else // if the condition above is not met
                    {
                    cout << "Total books in the database: " << numBooks << endl; // print "Total books in the database: " and the number the fuction returns
                    }
                    cout << endl; // end line
                    break;

                case 2:
                    // read user file
                    cout << "Enter a rating file name:" << endl;
                    
                    cin >> filename; // user inputs the name of the file and it is assigned to filename
                    numUsers = readRatings(filename, usera, numUsers, 200); // number of users is assigned to the value the funtion readratings return
                    if (numUsers != -1) // if the fuction readRatings does not return -1
                    {
                        cout << "Total users in the database: " << numUsers << endl; // prints "Total users in the database: " and the value numUsers returns
                        cout << endl; // end line
                    }
                    else // if the conditions above are not met
                    {
                        cout << "No users saved to database" << endl; // print "No users saved to database"
                        cout << endl; // end line
                    }
                    break;

                case 3:
                    
                    printAllBooks(booka, numBooks); // call fuction printAllBooks
                    cout << endl; // end line
                    
                    break;
                // case 4:
                //     for (int i = 0; i <= 50; i++)
                //     {
                //         cout << usera[50].getRatingAt(i) << endl;
                //     }
                //     break;

            //     case 4:
            //         // find the number of books user read
            //         cout << "Enter username:" << endl;
                    
            //         cin >> username;
            //         booksRead = getUserReadCount(username, users, ratings, numUsers, numBooks);
                    
            //         cout << endl;
            //         break;

            //     case 5:
            //         // get the average rating of the book
            //         cout << "Enter book title:" << endl;
                    
            //         cin.ignore();
            //         getline(cin, title);
            //         average = calcAvgRating(title, titles, ratings, numUsers, numBooks);
                    
            //         cout << endl;
            //         break;
                case 6:
                    // quit
                    cout << "good bye!" << endl;
                    break;

                default:
                    cout << "invalid input" << endl;
                    cout << endl;
            }
    }

    return 0;
}