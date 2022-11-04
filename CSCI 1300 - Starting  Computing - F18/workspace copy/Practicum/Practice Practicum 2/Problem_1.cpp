#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

int CountVowels (string s)
{
    if (s == "")
    {
        return -1;
    }
    else 
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                count++;
            }
        }
    return count;
    }
}

int main()
{
    cout << CountVowels("Hello");
}