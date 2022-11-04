#include <iostream>
using namespace std;

double PizzaParty (int n, double c, double d)
{
    if (n >= 0 && n < 10)
    {
        double t = n * c + 10;
        return t;
    }
    else if (n >= 10)
    {
        double t2 = n * (c - (d * c));
        return t2;
    }
}

int main()
{
    //cout << PizzaParty(10,10,0.1);
    cout << PizzaParty(9,10.4,.1) << endl;
}

// cost = (number of pizzas * cost per pizza) + 10
// cost = number of pizzas * (cost per pizza - (discount * cost per pizza))