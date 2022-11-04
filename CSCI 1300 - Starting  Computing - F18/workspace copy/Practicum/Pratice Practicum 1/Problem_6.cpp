#include <iostream>
#include <iomanip>
using namespace std;

void calculator (double a, double b, char c)
{
    switch (c)
    {
        case '+': cout << a << " + " << b << " = " << a + b << endl; break;
        case '-': cout << a << " - " << b << " = " << a - b << endl; break;
        case '*': cout << a << " * " << b << " = " << a * b << endl; break;
        case '/': cout << a << " / " << b << " = " << setprecision(2) << fixed << a / b << endl; break;
        default: cout << "Invalid operator!" << endl; break;
    }
}

int main()
{
    calculator(3, -7, '+');
    calculator(3, -7, '/');
}