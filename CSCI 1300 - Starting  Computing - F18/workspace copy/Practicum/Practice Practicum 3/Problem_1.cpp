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
    cout << "hello " << word << endl;
    return count ;
}


// float averageTemp(string s)
// {
//     string a[1];
//     double t[1];
//     int lineidx = 0;
//     ifstream filename; // create a file stream for reading a file
//     filename.open(s); //open the file passed to the function as string s with the file stream
//     if (filename.is_open()) // if the file is open
//     {
//         string line = ""; // assign string line to ""
//         while (getline(filename, line)) // read in an entire line from myfilestream and set line equal to its contents.
//         {
//             string temp[2];
//             split(line, ',', temp, 2);
//           // cout << temp;
//             // if (line != "") // if line is not empty
//             // {
//             // a[lineidx] = temp[0]; // assign the line as an integer to the array
//             // t[lineidx] = stod(temp[1]);
//             // lineidx++; // increment lineidx
//             // }
//         }
//     }
//     else // if the file is not open 
//     {
//         return -1; // return false
//     }
// }

int main()
{
    //averageTemp("File.txt");
    
    string array[2];
    cout << split("moneday,55", ',', array, 2);
}
 
 