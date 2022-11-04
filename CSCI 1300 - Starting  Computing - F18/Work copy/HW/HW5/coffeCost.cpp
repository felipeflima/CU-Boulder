#include <iostream>
#include <string>
using namespace std;

// invalid input, then return -1
double CoffeeCost(int cups, double price)
{
    double totalPrice = -1; 
    if(cups >= 0 && price >= 0) // input is valid
    {
        int rewards = cups/13; // how many free cups
        if (rewards >= 1) // have free coffee
        {
            totalPrice = (cups - rewards) * price;
        }
        else
        {
            totalPrice = cups * price;
        }
    }
    return totalPrice;
}
    
int main()
{
    // tests
    cout << CoffeeCost( 4, 5) << endl; // expected value: 20
    cout << CoffeeCost( 11, 5)<< endl; // expected value: 55
    cout << CoffeeCost( 12, 5)<< endl; // expected value: 60
    cout << CoffeeCost( 13, 5)<< endl; // expected value: 60
    cout << CoffeeCost( 14, 5)<< endl; // expected value: 65
    cout << CoffeeCost( 24, 5)<< endl; // expected value: 115
    cout << CoffeeCost( 25, 5)<< endl; // expected value: 120
    cout << CoffeeCost( 26, 5)<< endl; // expected value: 120
    cout << CoffeeCost( 27, 5)<< endl; // expected value: 125
    cout << CoffeeCost( -26, 5)<< endl; // expected value: -1
    cout << CoffeeCost( 27, -5)<< endl; // expected value: -1
    cout << CoffeeCost( -26, -5)<< endl; // expected value: -1
    return 0;
}
