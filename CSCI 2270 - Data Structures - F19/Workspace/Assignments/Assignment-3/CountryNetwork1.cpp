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
 void CountryNetwork::insertCountry(Country* previous, string countryName) {
   Country *newNode = new Country;
   newNode->name = countryName;
   if(head == NULL)
   {
     head = newNode;
     cout << "adding: " << countryName << " (HEAD) " << endl;
     newNode->next = NULL;
   }
   else if(previous == NULL)
   {
       newNode->next = head;
       cout << "adding: " << countryName << " (HEAD) " << endl;
       head = newNode;
   }
   else
   {
     newNode->next = previous->next;
     cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
     previous->next = newNode;
   }
 }

 void CountryNetwork::loadDefaultSetup() {
   if (head == NULL){
     insertCountry(NULL, "United States");
     insertCountry(searchNetwork("United States"), "Canada");
     insertCountry(searchNetwork("Canada"), "Brazil");
     insertCountry(searchNetwork("Brazil"), "India");
     insertCountry(searchNetwork("India"), "China");
     insertCountry(searchNetwork("China"), "Australia");
   }

 }

 Country* CountryNetwork::searchNetwork(string countryName) {
   Country* cname = head;
   while (cname != NULL && cname->name.compare(countryName) != 0)
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


void CountryNetwork::printPath() {
   Country *temp = head;
   if (head == NULL)
   {
     cout << "== CURRENT PATH ==" << endl;
     cout << "nothing in path" << endl;
     cout << "===" << endl;
   }
   else
   {
     cout << "== CURRENT PATH ==" << endl;
     while (temp != NULL)
     {
       cout << temp->name << " -> ";
       temp = temp->next;
     }
     cout << "NULL" << endl;
     cout << "===" << endl;
   }
 }
