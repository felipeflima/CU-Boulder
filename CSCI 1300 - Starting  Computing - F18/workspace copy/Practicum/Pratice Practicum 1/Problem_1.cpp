#include<iostream>
using namespace std;

double CoffeeCost(int n, double c)
{
    if (n <= 12)
    {
        double t = n * c;
        return t;
    }
    if (n > 12)
    {
        double t2 = (n - (n/12)) * c;
        return t2;
    }
}

int main()
{
    cout << CoffeeCost(12,3) << endl;
    cout << CoffeeCost(14,3);

}