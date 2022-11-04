#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

double smallestNumber (double a, double b, double c)
{
    if (a < b && a < c)
    {
        return a;
    }
    else if (b < c && b < a)
    {
        return b;
    }
    else if (c < a && c < b)
    {
        return c;
    }
}

int main()
{
    cout << smallestNumber(2,2,5);
}