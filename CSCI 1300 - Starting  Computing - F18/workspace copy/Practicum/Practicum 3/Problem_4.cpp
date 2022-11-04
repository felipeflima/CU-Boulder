#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

double matrixAverage (int array[][2], int size)
{
    double sum = 0;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            count++;
            sum += array[i][j];
        }
    }
    sum = sum/count;
    return sum;
}

int main()
{
    int array[1][2]={{13,15}}; 
    cout << matrixAverage(array, 1);
}