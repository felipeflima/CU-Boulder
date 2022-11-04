#include <iostream>
#include <fstream>
using namespace std;

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


int main()
{
    string au[50];
    string ti[50];
    cout << readBooks("books.txt", au, ti, 0, 50);
    // for (int i = 0; i < 50; i++)
    // {
    //     cout << au[i];
    //     cout << endl;
    //     cout << ti[i];
    // }
}