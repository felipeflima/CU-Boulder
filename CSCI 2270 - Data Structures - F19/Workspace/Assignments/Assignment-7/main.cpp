#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu()
{
  cout << "======Main Menu======" << endl;
  cout << "1. Print the inventory" << endl;
  cout << "2. Delete a movie" << endl;
  cout << "3. Quit" << endl;
}

int main(int argc, char const *argv[])
{
  MovieTree mTree;
  int option, y, rank, year;
  string t, line, title;
  float r, rating;
  ifstream myfile;
  myfile.open(argv[1]);
  if (myfile.is_open())
  {
    while (getline(myfile, line))
    {
      stringstream ss(line);
      string type;
      int select = 0;
      while (getline(ss, type, ','))
      {
        if (select == 0)
        {
          rank = stoi(type);
        }
        else if (select == 1)
        {
          title = type;
        }
        else if (select == 2)
        {
          year = stoi(type);
        }
        else if (select == 3)
        {
          rating = stof(type);
        }
        select++;
      }
    mTree.addMovie(rank, title, year, rating);
    }
    while (option != 3)
    {
      displayMenu();
      cin >> option;
      switch (option)
      {
        case 1:
          mTree.printMovieInventory();
          break;
        case 2:
          cout << "Enter a movie title:" << endl;
          cin.ignore();
          getline(cin, t);
          mTree.deleteMovie(t);
          break;
        case 3:
          cout << "Goodbye!" << endl;
          break;
        default:
          cout << "Invalid input" << endl;
          break;
      }
    }
  }
  else
  {
    cout << "Failed to open file" << endl;
  }
}
