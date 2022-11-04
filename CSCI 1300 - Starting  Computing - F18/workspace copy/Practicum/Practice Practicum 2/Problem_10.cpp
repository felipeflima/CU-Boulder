#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

void PrintPlus ()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "+";
        }
        cout << endl;
    }
}

int main()
{
    PrintPlus();
}