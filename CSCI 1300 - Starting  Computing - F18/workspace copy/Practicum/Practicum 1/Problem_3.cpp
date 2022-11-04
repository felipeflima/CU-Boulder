#include <iostream>
using namespace std;

void cardSuit (int x)
{
    switch (x)
    {
        case 0: cout << "Suit " << x << ": Clubs" << endl; break;
        case 1: cout << "Suit " << x << ": Diamonds" << endl; break;
        case 2: cout << "Suit " << x << ": Spades" << endl; break;
        case 3: cout << "Suit " << x << ": Hearts" << endl; break;
        default: cout << "Suit " << x <<": Invalid" << endl; break;
    }
}

int main()
{
    cardSuit(4);
}
