// CSCI1300 Fall 2018
// Author: <Your name>
// Recitation: <123> – <Your TA name>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// hmwk6 


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;


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
 * @param: string array, titles
 * @param: string array, authors
 * @param: int, the number of books currently stored in the arrays
 * @param: int, capacity of the authors/titles arrays [assume to be 50]
 * @return: the total number of books in total
 */

//////////////////////////////////////////////////////////////////////////
// ToDo: implement readBooksfunction
// your readBooks function goes here
//////////////////////////////////////////////////////////////////////////


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

 //////////////////////////////////////////////////////////////////////////
 // ToDo: implement readRatings function
 // your readBooks function goes here
 //////////////////////////////////////////////////////////////////////////


 //////////////////////////////////////////////////////////////////////////
 // other helper functions
 //////////////////////////////////////////////////////////////////////////



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


int main(int argc, char const *argv[]) {
    string choice;
    int numBooks = 0;
    int numUsers = 0;

    while (choice != "6") {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    
                    //////////////////////////////////////////////////////////////////////////
                    // Your code here. Call the appropriate function(s).
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << "Total books in the database: " << numBooks << endl;
                    cout << endl;
                    break;

                case 2:
                    // read user file
                    cout << "Enter a raitng file name:" << endl;

                    //////////////////////////////////////////////////////////////////////////
                    // Your code here. Call the appropriate function(s).
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << "Total users in the database: " << numUsers << endl;
                    cout << endl;
                    break;

                case 3:
                    // print the list of the books
                    
                    //////////////////////////////////////////////////////////////////////////
                    // Your code here. Call the appropriate function(s).
                    //////////////////////////////////////////////////////////////////////////
                    
                    break;

                case 4:
                    // find the number of books user read
                    cout << "Enter username:" << endl;
                    
                    //////////////////////////////////////////////////////////////////////////
                    // Your code here. Call the appropriate function(s).
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << endl;
                    break;

                case 5:
                    // get the average rating of the book
                    cout << "Enter book title:" << endl;

                    //////////////////////////////////////////////////////////////////////////
                    // Your code here. Call the appropriate function(s).
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << endl;
                    break;
                case 6:
                    // quit
                    cout << "good bye!" << endl;
                    break;

                default:
                    cout << "invalid input" << endl;
            }
    }

    return 0;
}
