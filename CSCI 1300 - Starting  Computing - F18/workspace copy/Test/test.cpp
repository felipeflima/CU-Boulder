#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

// g++ -std=c++11 User.cpp Hmwk8.cpp Book.cpp Library.cpp
// ./a.out

// int buyOxen()
// {
//     cout << "There are 2 oxen in a yoke and the price of each yoke is $40." << endl;
//     cout << "How many yokes do you wich to purchase? - You must spend between $100 and $200 dollars on oxen" << endl;
//     cout << "If you wish to exit type 0" << endl;
//     int oxen = -1;
//     cin >> oxen;
//     while (oxen != 0)
//     {
//         if (oxen >= 3 && oxen <= 5)
//         {
//             cout << "You bought " << oxen << " yokes / " << oxen * 2 << " oxen.";
//             return oxen;
//         }
//         else
//         {
//             cout << "Invalid input. You must spend between $100 and $200 dollars on oxen (3 to 5 yokes)" << endl;
//             cin >> oxen;
//         }
//     }
// }

// int main()
// {
//     buyOxen();
// }


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


int ReadFile(string filename)
{
    string name[20];
    ifstream myFile; 
    myFile.open(filename);
    if (myFile.is_open())
    {
        string line = "";
        while (getline(myFile, line))
        {
             split(line, '@', name, 20);
             cout << name << endl;
        }
        return 0;
    }
    else 
    {
        return -1;
    }
}


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
                u[lineidx] = temp[0]; // assign the line as an integer to the array
                string temp2[50];
                split (temp[1], ' ', temp2, 50);
                for (int i = 0; i < 50; i++)
                {
                    r[lineidx][i] = stoi(temp2[i]);
                }
                lineidx++; // increment lineidx
            }
        }
    }
    else // if non of the consitions above are met
    {
        return -1; // return -1
    }

int main()
{
    ReadFile("File.txt");
}