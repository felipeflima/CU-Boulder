#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu()
{
  cout << "======Main Menu======" << endl;
  cout << "1. Find a movie" << endl;
  cout << "2. Query movies" << endl;
  cout << "3. Print the inventory" << endl;
  cout << "4. Average Rating of movies" << endl;
  cout << "5. Quit" << endl;
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
    mTree.addMovieNode(rank, title, year, rating);
    }
    while (option != 5)
    {
      displayMenu();
      cin >> option;
      switch (option)
      {
        case 1:
          cout << "Enter title:" << endl;
          cin.ignore();
          getline(cin, t);
          mTree.findMovie(t);
          break;
        case 2:
          cout << "Enter minimum rating:" << endl;
          cin >> r;
          cout << "Enter minimum year:" << endl;
          cin >> y;
          mTree.queryMovies(r, y);
          break;
        case 3:
          mTree.printMovieInventory();
          break;
        case 4:
          mTree.averageRating();
          break;
        case 5:
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
