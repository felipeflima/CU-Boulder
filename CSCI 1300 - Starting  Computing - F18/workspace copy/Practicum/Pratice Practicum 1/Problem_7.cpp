#include <iostream>
#include <string>
using namespace std;

string shapeName (int x)
{
    switch (x)
    {
        case 2: return "CONE"; break;
        case 3: return "CYLINDER"; break;
        case 4: return "TRIANGULARPYRAMID"; break;
        case 6: return "CUBOID"; break;
        default: return "UNKNOWN"; break;
    }
}

int main()
{
    cout << shapeName(2);
}