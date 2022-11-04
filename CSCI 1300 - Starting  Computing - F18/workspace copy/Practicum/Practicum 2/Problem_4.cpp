#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

string removeCapitals (string s)
{
    string x;
    for (int i = 0; i < s.length(); i++)
    {
        if (!(s[i] >= 'A' && s[i] <= 'Z'))
        {
            x = x + s[i];
        }
    }
    return x;
}


int main()
{
    cout << removeCapitals("HelloWorld");
}