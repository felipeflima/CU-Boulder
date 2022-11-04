void displayMenu();

int main(int argc, char* argv[])
{
    int option = 0;
    //int value = 0;
    string deleteC;
    string countryName;
    string prevCountry = "";
    Country *temp;

    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;

    while (option != 8)
    {
      displayMenu();
      cin >> option;
      switch (option) {
        case 1:
          CountryNet.loadDefaultSetup();
          CountryNet.printPath();
          break;
        case 2:
            CountryNet.printPath();
            break;
        case 3:
          cout << "hello" << endl;
          break;
        case 4:
          cout << "Enter a country name:" << endl;
          cin.ignore();
          getline(cin, deleteC);
          CountryNet.deleteCountry(deleteC);
          CountryNet.printPath();
          break;
        case 5:
          break;
        case 6:
          cout << "Enter the count of values to be rotated:" << endl;
          int n;
          cin >> n;
          CountryNet.rotateNetwork(n);
          CountryNet.printPath();
          break;
        case 7:
          cout << "Network before deletion" << endl;
          CountryNet.printPath();
          CountryNet.deleteEntireNetwork();
          cout << "Network after deletion" << endl;
          CountryNet.printPath();
          break;
        case 8:
          cout << "Quitting... cleaning up path: " << endl;
          CountryNet.printPath();
          CountryNet.deleteEntireNetwork();
          if (CountryNet.isEmpty() == true)
          {
            cout << "Path cleaned" << endl;
          }
          else if (CountryNet.isEmpty() == false)
          {
            cout << "Error: Path NOT cleaned" << endl;
          }
          cout << "Goodbye!" << endl;
          break;
        default:
          cout << "Invalid input" << endl;
          break;
      }


    return 0;
  }

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
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network" << endl;
    cout << " 6. Rotate Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
