#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

string mileage (int flight_distance)
{
    if (flight_distance >= 0 && flight_distance <= 10000)
    {
        return "Bronze";
    }
    else if (flight_distance > 10000 && flight_distance <= 15000)
    {
        return "Silver";
    }
    else if (flight_distance > 15000 && flight_distance <= 30000)
    {
        return "Gold";
    }
    else if (flight_distance > 30000)
    {
        return "Platinum";
    }
    else
    {
        return "INVALID";
    }
}

int main()
{
    cout << mileage(2648);
}