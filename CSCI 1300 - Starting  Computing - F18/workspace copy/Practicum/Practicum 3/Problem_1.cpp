#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

void printEligiblePlayers (string names[], float ages[], int size)
{
    int index[size];
    for (int i = 0; i < size; i++)
    {
        if (ages[i] >= 4 && ages[i] <= 6)
        {
            cout << names[i] << " " << ages[i] << endl;
        }
    }
}

int main()
{
    string names[] = {"Joe", "Jack", "Amy", "Bob"};
    float ages[] = {3.4, 5.6, 6.0, 4.2};
    printEligiblePlayers(names, ages, 4);
}