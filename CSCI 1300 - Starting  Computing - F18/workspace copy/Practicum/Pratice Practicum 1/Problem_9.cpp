#include <iostream>
using namespace std;

string DayOfWeek (int d)
{
    switch (d)
    {
        case 1: return "MONDAY"; break;
        case 2:
        case 3:
        case 4:
                return "WORKDAY"; break;
        case 5: return "FUNDAY"; break;
        case 6:
        case 0: 
                return "SLEEPDAY"; break;
        default: return "INVALID"; break;
    }
}

int main()
{
    cout << DayOfWeek(1);
}