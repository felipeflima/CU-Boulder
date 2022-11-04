#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

void MultiplicationTableWhile ()
{
    int a = 1;
    while (a <= 1)
    {
        cout << a << " ";
        a++;
    }
    cout << endl;
    int b = 2;
    while (b <= 4)
    {
        cout << b << " ";
        b += 2;
    }
    cout << endl;
    int c = 3;
    while (c <= 9)
    {
        cout << c << " ";
        c += 3;
    }
    cout << endl;
    int d = 4;
    while (d <= 16)
    {
        cout << d << " ";
        d += 4;
    }
    cout << endl;
    int e = 5;
    while (e <= 25)
    {
        cout << e << " ";
        e += 5;
    }
    cout << endl;
}

int main ()
{
    MultiplicationTableWhile();
}