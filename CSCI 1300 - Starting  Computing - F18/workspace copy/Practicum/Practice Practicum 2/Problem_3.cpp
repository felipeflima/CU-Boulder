#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

bool IsAllLower (string s)
{
    bool x = 0;
    int count = 0;
    if (s == "")
    {
        return 1;
    }
    else
        {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                count++;
            }
        }
        if (count == s.length())
        {
            x = 1;
        }
    }
    return x;
}

int main()
{
    cout << IsAllAlpha("sdfgh1");
}