#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

void PrintCommas(string str) 
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ',') 
        {
            cout << str[i];
        }    
    }
}


int main()
{
    PrintCommas("hello,,, world");
}