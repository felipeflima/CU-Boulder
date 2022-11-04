#include<iostream>
using namespace std;

double GasBill(int x)
{
    if (x >= 0 && x <= 100)
    {
        double t = x * 1.23;
        return t;
    }
    else if (x > 100 && x <= 200)
    {
        double t2 = (100 * 1.23) + ((x - 100) * 1.14);
        return t2;
    }
    else if (x > 200)
    {
        double t3 = (100 * 1.23) + (100 * 1.14) + ((x - 200) * 1.08);
        return t3;
    }
    else 
    {
        cout << "Incorrect input" << endl;
        return 0;
    }
}

int main()
{
    cout << GasBill(244) << endl;
    cout << GasBill(82) << endl;
    cout << GasBill(0) << endl;
    cout << GasBill(-2) << endl;
}