#include <iostream>
using namespace std;

double TuitionCost (int u, double c)
{
    int uc = u * c;
    if (u < 0 || c < 0)
    {
        return -1;
    }
    else if (u >= 0 && u <= 16)
    {
        double t = uc;
        return t;
    }
    else if (u > 16)
    {
        double t2 = 16 * c + (u - 16) * (c/2);
        return t2;
    }
    
}

int main ()
{
    cout << TuitionCost(17,300) << endl;
    cout << TuitionCost(10,202.2)<<endl;
}