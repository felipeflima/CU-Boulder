#include <iostream>
#include <string.h> // #include <string>
using namespace std;

string GolfName (int x)
{
    switch (x)
    {
        case -2: return "EAGLE"; break;
        case -1: return "BIRDIE"; break;
        case 0: return "PAR"; break;
        case 1: return "BOGIE"; break;
        case 2: return "DOUBLE BOGIE"; break;
        case 3: return "TRIPLE BOGIE"; break;
        default: return "NO COMMENT"; break;
        
    }
}

int main()
{
    cout << GolfName(-2) << endl;
    cout << GolfName(-1) << endl;
    cout << GolfName(0) << endl;
    cout << GolfName(1) << endl;
    cout << GolfName(2) << endl;
    cout << GolfName(3) << endl;
}