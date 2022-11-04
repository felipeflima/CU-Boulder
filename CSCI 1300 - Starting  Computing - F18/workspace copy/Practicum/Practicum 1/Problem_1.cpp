#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

double calculateCost(double distance, double avgSpeed, double gasPrice)
{
    if (avgSpeed > 62)
    {
        double tripCost = (distance / 26) * gasPrice;
        return tripCost;
    }
    else if (avgSpeed > 0 && avgSpeed <= 62)
    {
        double tripCost2 = (distance / 30) * gasPrice;
        return tripCost2;
    }
}

int main()
{
    cout << calculateCost(600,60,2.5);
}