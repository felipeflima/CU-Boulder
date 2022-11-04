#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

void PrintNonLetters (string s)
{
    int count = 0;
    if (s == "")
    {
        cout << "NULL";
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            {
                count++;
            }
            else if ((s[i] != 'A' && s[i] != 'Z') || (s[i] != 'a' && s[i] != 'z'))
            {
                cout << s[i];
            }
        }
        if (count == s.length())
        {
            cout << "-2";
        }
    }
}

int main()
{
    PrintNonLetters("hey2");
}