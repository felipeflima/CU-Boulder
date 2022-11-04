#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

int sumOfPositiveOdd(string str, int array[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        if (array[i] % 2 != 0 && array[i] >= 0)
        {
            sum += array[i];
        }
    }
    ofstream filename;
    filename.open(str);
    if (filename.is_open())
    {
        filename << sum;
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int array[] = {1,2,3,4,5};
    sumOfPositiveOdd("file.txt", array, 5);
}