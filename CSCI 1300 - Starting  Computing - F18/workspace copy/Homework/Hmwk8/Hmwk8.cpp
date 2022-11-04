// CSCI1300 Fall 2018
// Author: <Your name>
// Recitation: <123> – <Your TA name>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// hmwk8 / Project2


#include <iostream>
#include <iomanip>
#include "Library.h"
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
     cout << "6. Add a User" << endl;
     cout << "7. Checkout a book" << endl;
     cout << "8. View Ratings" << endl;
     cout << "9. Get Recommendations" << endl;
     cout << "10. Quit" << endl;
 }



int main(int argc, char const *argv[])
{
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
    
    bool add = 0;
    
    int rating;
    bool changeRating;
    
    Library library;

    while (choice != "10") {
            displayMenu();
            cin >> choice;
            switch (stoi(choice)) {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    
                    cin >> filename; // user inputs the name of the file and it is assigned to filename
                    numBooks = library.readBooks(filename); // number of books is assigned to the value the funtion readBooks return
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
                    numUsers = library.readRatings(filename); // number of users is assigned to the value the funtion readratings return
                    // for (int i = 0; i < 86; i++) // for loop to rin through the array
                    // {
                    //     if (numUsers != -1) // if the fuction readRatings does not return -1
                    //     {
                    //         //cout << users[i]; // print all the users
                    //         //cout << "..."; // prints ... after every user
                    //         //cout << endl; // end line
                    //     }
                    // }
                    if (numUsers != -1) // if the fuction readRatings does not return -1
                    {
                        cout << "Total users in the database: " << numUsers << endl; // prints "Total users in the database: " and the value numUsers returns
                        cout << endl;
                    }
                    else 
                    {
                        cout << "No users saved to database" << endl;
                        cout << endl;
                    }
                    break;

                case 3:
                    
                    library.printAllBooks();
                    cout << endl;
                    
                    break;

                case 4:
                    // find the number of books user read
                    cout << "Enter username:" << endl;
                    
                    cin >> username;
                    booksRead = library.getCountReadBooks(username);
                    
                    cout << username << " rated " << booksRead << " books" << endl;
                    
                    cout << endl;
                    break;

                case 5:
                    // get the average rating of the book
                    cout << "Enter book title:" << endl;
                    
                    cin.ignore();
                    getline(cin, title);
                    average = library.calcAvgRating(title);
                    
                    cout << "The average rating for " << title << " is " << fixed << setprecision(2) << average << endl;
                    
                    cout << endl;
                    break;
                    
                case 6:
                
                    cout << "Enter username:" << endl;
                    
                    cin >> username;
                    add = library.addUser(username);
                    if (add == 1)
                    {
                        cout << "Welcome to the library " << username << endl;
                    }
                    else 
                    {
                        cout << username << " could not be added in the database" << endl;
                    }
                    
                    cout << endl;
                    break;
                    
                case 7:
                    
                    cout << "Enter a username:" << endl;
                    cin >> username;
                    
                    cout << "Enter a book title:" << endl;
                    cin >> title;
                    
                    cout << "Enter a rating for the book:" << endl;
                    cin >> rating;
                    
                    changeRating = library.checkOutBook(username, title, rating);
                    
                    if (changeRating == 1)
                    {
                        cout << "We hope you enjoyed your book. The rating has been updated" << endl;
                    }
                    else if (changeRating == 0)
                    {
                        cout << username << " could not check out " << title << endl;
                    }
                    
                    cout << endl;
                    break;
                    
                case 8:
                    
                    cout << "Enter a username: " << endl;
                    cin >> username;
                    
                    library.viewRatings(username);
                    
                    cout << endl;
                    break;
                
                case 9:
                    
                    cout << "Enter a username: " << endl;
                    
                    break;
                
                case 10:
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