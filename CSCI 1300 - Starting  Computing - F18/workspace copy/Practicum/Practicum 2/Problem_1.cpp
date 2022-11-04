#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

int CountUpper (string s)
{
    int count = 0;
    int count2 = 0;
    if (s == "")
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                count++;
            }
        }
    }
    if (count != 0)
    {
        return count;
    }
    else 
    {
        return -2;
    }
}

int main ()
{
    cout << CountUpper("hello");
}