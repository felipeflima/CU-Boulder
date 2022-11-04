#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;


int countPrimes(int array[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == 1 || array[i] == 2 || array[i] == 3 || array[i] % 2 != 0 || array[i] % 3 != 0 || array[i] % 4 != 0 || array[i] % 5 != 0 || array[i] % 6 != 0 
        || array[i] % 7 != 0 || array[i] % 8 != 0 || array[i] % 9 != 0 )
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 7, 10, 12};
    cout << countPrimes(array, 8);
}