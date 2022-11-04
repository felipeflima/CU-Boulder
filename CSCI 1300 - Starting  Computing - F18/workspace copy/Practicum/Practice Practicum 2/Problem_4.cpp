#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

bool IsPrime (int x)
{
    bool a = 0;
    if (x == 3 || x == 5 || x == 7 || x == 2)
    {
        a = 1;
    }
    else if (x % 2 == 0 || x % 3 == 0 || x % 4 == 0 || x % 5 == 0 || x % 6 == 0 || x % 7 == 0 || x % 8 == 0 || x % 9 == 0 || x == 1)
    {
        a = 0;
    }
    else 
    {
        a = 1;
    }
    return a;
}

int main()
{
    cout << IsPrime(1);
}