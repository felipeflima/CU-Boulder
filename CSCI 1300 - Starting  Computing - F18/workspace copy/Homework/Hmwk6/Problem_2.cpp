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
    return lineidx; // return lineidx
}


int main()
{
    string us[100];
    int ra[100][50];
    readRatings("ratings.txt", us, ra, 0, 100, 50);
    for (int j = 0; j < 100; j++)
    {
        
    for (int i = 0; i < 50; i++)
    {
        cout << endl;
        cout << ra[j][i];
    }
    cout << endl;
    cout << us[1];

    }
}