#include "CountryNetwork.hpp"
// add any other includes you need that aren't already included in CountryNetwork.hpp

using namespace std;

// implementation of class functions goes here
CountryNetwork::CountryNetwork()
{
  while (head != NULL)
  {
    head = head->next;
  }
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
 void CountryNetwork::insertCountry(Country* previous, string countryName)
 {
   Country* newNode = new Country;
   newNode->name = countryName;
   if(head == NULL)
   {
     head = new Country;
     head->name = countryName;
     cout << "adding: " << countryName << " (HEAD) " << endl;
     head->next = NULL;
   }
   else if(previous == NULL)
   {
       newNode->next = head;
       cout << "adding: " << countryName << " (HEAD) " << endl;
       head = newNode;
   }
   else
   {
     newNode->name = countryName;
     newNode->next = previous->next;
     cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
     previous->next = newNode;
   }

 }

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
 void CountryNetwork::loadDefaultSetup()
 {
   insertCountry(NULL, "United States");
   insertCountry(head, "Canada");
   insertCountry(head->next, "Brazil");
   insertCountry(head->next->next, "India");
   insertCountry(head->next->next->next, "China");
   insertCountry(head->next->next->next->next, "Australia");

 }

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
 Country* CountryNetwork::searchNetwork(string countryName)
 {
   Country* cname = head;
   while (cname != NULL && cname->name != countryName)
   {
       cname = cname->next;
   }
   if (cname != NULL)
   {
       return cname;
   }
   else
   {
       return NULL;
   }
 }
/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
 void CountryNetwork::transmitMsg(string receiver, string message)
 {
   Country* rec = head;
   if (rec == NULL)
   {
     cout << "Empty List" << endl;
   }
   else if (searchNetwork(receiver) == NULL)
   {
       cout << "Country not found" << endl;
   }
   else
   {
     while (rec != NULL && rec->name != receiver)
     {
       rec->message = message;
       rec->numberMessages = rec->numberMessages+1;
       cout << rec->name << " [# messages received: " << rec->numberMessages << "] received: " << rec->message << endl;
       rec  = rec->next;
     }
     if (rec->name == receiver)
     {
       rec->message = message;
       rec->numberMessages = rec->numberMessages+1;
       cout << rec->name << " [# messages received: " << rec->numberMessages << "] received: " << rec->message << endl;
     }
   }
 }

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
  if (head == NULL)
  {
    cout << "nothing in path" << endl;
  }
  else
  {
    while (head != NULL)
    {
      cout << head->name << " -> ";
      head = head->next;
    }
    cout << "NULL" << endl;
  }
}

// main and any other functions from main.cpp go here

void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    int option;
    string to;
    string me;
    while (option != 5)
    {
      displayMenu();
      cin >> option;
      switch (option) {
        case 1:
          CountryNet.loadDefaultSetup();
          cout << "== CURRENT PATH ==" << endl;
          CountryNet.printPath();
          cout << "===" << endl;
          break;
        case 2:
          cout << "== CURRENT PATH ==" << endl;
          CountryNet.printPath();
          cout << "===" << endl;
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
