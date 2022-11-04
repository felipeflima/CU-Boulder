// CSCI1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: <https://ide.c9.io/feli0059/csci1300fl1>
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

int readBooks (string filename, string t[50], string a[50], int n, int length) 
{
    int lineidx = 0; // create variable
    ifstream myfilestream; // create a file stream for reading to file
    myfilestream.open(filename); // open the file 
    if (myfilestream.is_open()) // if the file is open
    {
        string line = ""; // assign string line to ""
        while (getline(myfilestream, line)) // read in an entire line from myfilestream and set line equal to its contents.
        {
            string temp[2]; 
            split(line, ',', temp, 2);
            if (line != "") // if line is not empty
            {
            a[lineidx] = temp[0]; // assign the line as an integer to the array
            t[lineidx] = temp[1];
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

 int readRatings (string filename, string u[100], int r[][50], int n, int rc, int cc) 
{
    int lineidx = 0; // create variable
    ifstream myfilestream; // create a file stream for reading to file
    myfilestream.open(filename); // open the file 
    if (myfilestream.is_open()) // if the file is open
    {
        string line = ""; // assign string line to ""
        while (getline(myfilestream, line)) // read in an entire line from myfilestream and set line equal to its contents.
        {
            string temp[2]; // creates a temporary array
            split(line, ',', temp, 2); // calls the split function
            if (line != "") // if line is not empty
            {
                u[lineidx] = temp[0]; // assign the line as an integer to the array
                string temp2[50]; // creates temporary array
                split (temp[1], ' ', temp2, 50); // calls split fuction
                for (int i = 0; i < 50; i++) // for loop to run through the array
                {
                    r[lineidx][i] = stoi(temp2[i]); // assign the line as an integer to the array
                }
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


/** find user function (helper function)
 * used to find the index for the position of the user in the user array
 * returns the index
 */
 
int findUser (string username, string allUsers[], int userCount)
{
    for (int i = 0; i < userCount; i++) // for loop to run throughthe array
    {
        if (allUsers[i] == username) // if any index in the array is equal to the username typoed by the user
        {
            return i; // return the index
        }
    }
    return -1; // returns negative one if the index is not found
}


int getUserReadCount (string username, string allUsers[], int allRatings[][50], int userCount, int b)
{
    if (b == 0 && userCount > 0)
    {
        cout << username << " rated 0 books" << endl;
        return -1;
    }
    if (b == 0 || userCount == 0)
    {
        cout << username << " does not exist in the database" << endl;
        return -1;
    }
    int index = findUser (username, allUsers, userCount);
    if (index == -1)
    {
        cout << username << " does not exist in the database" << endl;
        return -1;
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
            for (int i = 0; i < b; i++)
            {
                if (allRatings[index][i] != 0)
                {
                    count ++;
                }
            }
            cout << username << " rated " << count << " books" << endl;
            return count;
        }
        
    }
}

int findBookReview (string title, string titles[], int numBooks)
{
    for (int i = 0; i < numBooks; i++)
    {   
        if (titles[i] == title)
        {
            return i;
        }
    }
    return -1;
}

double calcAvgRating (string title, string titles[50], int ratings[100][50], int numUsers, int numBooks)
{
    if (numBooks == 0 || numUsers == 0)
    {
        cout << title << " does not exist in our database" << endl;
        return -1;
    }
    int index = findBookReview (title, titles, numBooks);
    if (index == -1)
    {
        cout << title << " does not exist in our database" << endl;
        return -1;
    }
    else 
    {
        if (index == -1)
        {
            cout << title << " does not exist in our database" << endl;
        }
        else
        {
            int count = 0;
            double avg = 0;
            for (int i = 0; i < numUsers; i++)
            {
                if (ratings[i][index] != 0)
                {
                    count++;
                    avg += ratings[i][index];
                }
            }
            avg = avg/count;
            cout << "The average rating for " << title << " is " << fixed << setprecision(2) << avg << endl;
            return avg;
        }
        
    }
}


/** printAllBooks fuction
 * prints all books in the titles array from the books.txt file
 * check if the number of books is zero or the first index of authors is empty
 *      if yes prints "No books are stored"
 * else print "Here is a list of books" and display a list of all the books 
 */
 
void printAllBooks (string titles[], string authors[], int b) // prints all the books in the titles array
{
    if (b == 0 || authors[0] == "") // if the number of books is zero or the first index of authors is empty
    {
        cout << "No books are stored" << endl; // print "No books are stored"
    }
    else // if the condition above is not met
    {
        cout << "Here is a list of books" << endl; // print "Here is a list of books"
        for (int i = 0; i < b; i++) // for loop to run through the array
        {
            cout << titles[i] << " by " << authors[i] << endl; // prints a list of the books "by" the author
        }
    }
}

int main(int argc, char const *argv[]) {
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
                    numBooks = readBooks(filename, titles, authors, 0, 50); // number of books is assigned to the value the funtion readBooks return
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
                    numUsers = readRatings(filename, users, ratings, 0, 100, 50); // number of users is assigned to the value the funtion readratings return
                    for (int i = 0; i < 86; i++) // for loop to rin through the array
                    {
                        if (numUsers != -1) // if the fuction readRatings does not return -1
                        {
                            cout << users[i]; // print all the users
                            cout << "..."; // prints ... after every user
                            cout << endl; // end line
                        }
                    }
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
                    
                    printAllBooks(titles, authors, numBooks);
                    cout << endl;
                    
                    break;

                case 4:
                    // find the number of books user read
                    cout << "Enter username:" << endl;
                    
                    cin >> username;
                    booksRead = getUserReadCount(username, users, ratings, numUsers, numBooks);
                    
                    cout << endl;
                    break;

                case 5:
                    // get the average rating of the book
                    cout << "Enter book title:" << endl;
                    
                    cin.ignore();
                    getline(cin, title);
                    average = calcAvgRating(title, titles, ratings, numUsers, numBooks);
                    
                    cout << endl;
                    break;
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