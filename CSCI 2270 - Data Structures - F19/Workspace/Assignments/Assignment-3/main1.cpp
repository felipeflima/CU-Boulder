/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <string>
#include <iostream>
// you may include more libraries as needed

// declarations for main helper-functions
void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    int option;
    string to;
    string me;
    string countryn;
    string newCountry;
    string previous;
    string prevc;
    while (option != 5)
    {
      displayMenu();
      cin >> option;
      switch (option) {
        case 1:
          CountryNet.loadDefaultSetup();
          //cout << "== CURRENT PATH ==" << endl;
          CountryNet.printPath();
          //cout << "===" << endl;
          break;
        case 2:
          //cout << "== CURRENT PATH ==" << endl;
          CountryNet.printPath();
          //cout << "===" << endl;
          break;
        case 3:
          cout << "Enter name of the country to receive the message:" << endl;
          cin.ignore();
          getline(cin, to);
          cout << "Enter the message to send:" << endl;
          getline(cin, me);
          CountryNet.transmitMsg(to, me);
          //cout << to <<  " --- " << me << endl;
          break;
        case 4: 
          cout << "Enter a new country name:" << endl;
          cin.ignore();
          getline(cin, newCountry);
          cout << "Enter the previous country name (or First):" << endl;
          getline(cin, previous);
          if (previous == "First")
          {
            CountryNet.insertCountry(NULL, newCountry);
          }
          else if (CountryNet.searchNetwork(previous) == NULL)
          {
              cout << "INVALID(precious country name)... Please enter a VALID previous country name!" << endl;
          }
          else
          {
            CountryNet.insertCountry(CountryNet.searchNetwork(previous), newCountry);
          }
          CountryNet.printPath();
          break;
        case 5:
          cout << "Quitting..." << endl;
          cout << "Goodbye!" << endl;
          break;
        default:
          cout << "Invalid input" << endl;
          break;

      }
    }
    return 0;
}


/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
