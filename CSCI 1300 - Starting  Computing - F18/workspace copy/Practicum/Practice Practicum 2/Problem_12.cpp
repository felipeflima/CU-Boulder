#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

string ReplaceHashTag (string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '#')
        {
            s[i] = '@';
        }
    }
    return s;
}

int main ()
{
    cout << ReplaceHashTag("#SKO#");
}