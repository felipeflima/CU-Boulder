#include <iostream>
// #include <string>
// #include <fstream>
// #include <sstream>
// #include <iomanip>
using namespace std;

class AwardWinners
{
    public:
        AwardWinners();
        int ReadFile(string);
        string getWinnerName(int);
        int getWinningYear(string);
    private:
        string name[20];
        int year[20];
    
};

AwardWinners::AwardWinners()
{
    for (int i = 0; i < 20; i++)
    {
        name[i] = "";
        year[i] = 0;
    }
}

int AwardWinners::ReadFile(string filename)
{
    // ifstream myFile; 
    // myFile.open(filename);
    // if (myFile.is_open())
    // {
    //     string line = "";
    //     while (getline(filename, line))
    //     {
    //         split(line, '@', name, 20);
    //         cout << line << endl;
    //     }
    //     return 0;
    // }
    // else 
    // {
    //     return -1;
    // }
    
    int lineidx = 0; // create variable
    ifstream myfilestream; // create a file stream for reading to file
    myfilestream.open(filename); // open the file 
    if (myfilestream.is_open()) // if the file is open
    {
        string line = ""; // assign string line to ""
        while (getline(myfilestream, line)) // read in an entire line from myfilestream and set line equal to its contents.
        {
            string temp[2];
            split(line, '@', temp, 2);
            if (line != "") // if line is not empty
            {
                name[lineidx] = temp[0]; // assign the line as an integer to the array
                year[lineidx] = temp[1];
                lineidx++; // increment lineidx
            }
        }
        return 0;
    }
    else // if non of the consitions above are met
    {
        return -1; // return -1
    }
}

string AwardWinners::getWinnerName(int winningYear)
{
    
}

int AwardWinners::getWinningYear(string winner)
{
    
}

