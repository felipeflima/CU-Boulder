#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

int insertIntoSortedArray (int myArray[], int numEntries, int newValue)
{
  //cout << numEntries << endl;
  if (numEntries == 0)
  {
    myArray[0] = newValue;
    //cout << newValue << endl;
    return numEntries+1;
  }
  else
  {
    myArray[numEntries] = newValue;
    for (int i = 0; i < numEntries+1; i++)
    {
      for (int j = i+1; j < numEntries+1; j++)
      {
        if (myArray[i] > myArray[j])
        {
          int temp = myArray[i];
          myArray[i] = myArray[j];
          myArray[j] = temp;
        }
      }
    }
  }
    return numEntries+1;
}


int main(int argc, char* argv[])
{
  //cout << argc << argv[1] << endl;
  int array[100];
  ifstream myfile;
  string s;
  myfile.open(argv[1]);
  if (myfile.is_open())
  {
    int numberOfElements = 0;
    int j = 0;
    while (getline (myfile, s))
    {
      insertIntoSortedArray (array, numberOfElements, stoi(s));
      numberOfElements++;
      for (int j = 0; j < numberOfElements; j++)
      {
        cout << array[j];
        if (j != numberOfElements-1)
        {
            cout << ",";
        }
      }
      cout << endl;
    }
  }
  else
  {
      cout << "Failed to open the file." << endl;
  }
}
