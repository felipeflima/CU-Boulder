#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
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


int parseScores (string str)
{
    // double grades[3];
    // string names[1];
    int max = 0;
    ifstream filename; 
    filename.open(str); 
    if (filename.is_open()) 
    {
        string line = ""; 
        int count = 0; 
        while (getline(filename, line)) 
        {
            count++; 
            string temp[4]; 
            split(line, ',', temp, 4);
            if (temp[0] > temp[1] && temp[0] > temp[2])
            {
                max =  stoi(temp[0]);
            }
            else if (temp[1] > temp[0] && temp[1] > temp[2])
            {
                max = stoi(temp[1]);
            }
            else if (temp[2] > temp[0] && temp[2] > temp[1])
            {
                max = stoi(temp[2]);
            }
            cout << temp[3] << ": " << max << endl;
        }
        
        filename.close(); 
        return count; 
    }
    else 
    {
        return -1; 
    }
}

int main()
{
    parseScores("file3.txt");
}