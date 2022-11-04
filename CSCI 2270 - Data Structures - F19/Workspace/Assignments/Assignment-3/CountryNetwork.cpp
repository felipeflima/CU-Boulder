/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
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
