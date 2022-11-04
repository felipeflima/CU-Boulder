#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

struct Park{
  string parkname;
  string state;
  int area;
};

void addPark(Park parks[], string parkname, string state, int area, int length)
{
    parks[length].parkname = parkname;
    parks[length].state = state;
    parks[length].area = area;
}

void printList(const Park parks[], int length)
{
  for (int i = 0; i < length; i ++)
  {
    cout << parks[i].parkname << " [" << parks[i].state << "] area: "<< parks[i].area << endl;
  }
}

//void addToFile()

int main(int argc, char* argv[])
{
  Park parks[100];
  fstream myfile;
  int minarea, area, count;
  int length = 0;
  string parkname, state, line, output;
  stringstream ss(line);
  minarea = stoi(argv[3]);
  myfile.open(argv[1]);
  if (myfile.is_open())
  {
    while (getline(myfile, line))
    {
      stringstream ss(line);
      string type;
      int select = 0;
      length++;
      while (getline(ss, type, ','))
      {
        if (select == 0)
        {
          parkname = type;
        }
        else if (select == 1)
        {
          state = type;
        }
        else if (select == 2)
        {
          area = stoi(type);
        }
        select++;
      }
    addPark(parks, parkname, state, area, length-1);
    }
    printList(parks, length);
    cout << endl << endl;
    fstream toFile;
    toFile.open(argv[2]);
    if (toFile.is_open())
    {
      for (int i =0; i < length; i++)
      {
        if (parks[i].area >= minarea)
        {
          toFile << parks[i].parkname << "," << parks[i].state << "," << parks[i].area << endl;
        }
      }
    }
    else if (!toFile)
    {
      cout << "Failed to open file." << endl;
    }
    myfile.close();
    toFile.close();
  }

  else if (!myfile)
  {
    cout << "Failed to open file." << endl;
  }
}
