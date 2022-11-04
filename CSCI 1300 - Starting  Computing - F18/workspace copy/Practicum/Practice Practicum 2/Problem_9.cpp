#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

void PrintOddPattern ()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "$*$*$" << endl;
    }
}

int main()
{
    PrintOddPattern();
}