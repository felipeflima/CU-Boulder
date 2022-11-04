#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

int countCharacter(string array[], int size, char ch)
{
    int count = 0;
    string line = "";
    for (int i = 0; i < size; i++)
    {
        line = line + array[i];
    }
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ch)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string a[] = {"elephant", "english", "elegant", "america", "united", "apple"};
    cout << countCharacter(a, 6, 'e');
}