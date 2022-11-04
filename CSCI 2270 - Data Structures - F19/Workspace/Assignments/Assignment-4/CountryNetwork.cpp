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
  * Purpose: Check if list is empty
  * @return true if empty; else false
  */
 bool CountryNetwork::isEmpty()
 {
   if (head == NULL)
   {
     return true;
   }
   else
   {
     return false;
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


 /*
  * Purpose: delete the country in the network with the specified name.
  * @param countryName name of the country to delete in the network
  * @return none
  */
  void CountryNetwork::deleteCountry(string countryName) {
    Country *pres = head->next;
    Country *prev = head;
    if (head->name == countryName)
    {
      head = head->next;
      return;
    }
    while (pres->name != countryName)
    {
      pres = pres->next;
      prev = prev->next;
      if (pres == NULL)
      {
        cout << "Country does not exist." << endl;
        return;
      }
    }
    prev->next = pres->next;
    delete pres;
  }

 /*
  * Purpose: populates the network with the predetermined countries
  * @param none
  * @return none
  */
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


 /*
  * Purpose: Search the network for the specified country and return a pointer to that node
  * @param countryName name of the country to look for in network
  * @return pointer to node of countryName, or NULL if not found
  * @see insertCountry, deletecountry
  */
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


 /*
  * Purpose: deletes all countries in the network starting at the head country.
  * @param none
  * @return none
  */
  void CountryNetwork::deleteEntireNetwork() {
    if (head == NULL)
    {
      return;
    }
    while (head != NULL)
    {
      cout << "deleting: " << head->name << endl;
      head = head->next;
    }
    cout << "Deleted network" << endl;


  }
 /*
  * Purpose: Rotate the linked list i.e. move 'n' elements from
  * the back of the the linked to the front in the same order.
  * @param number elements to be moved from the end of the list to the beginning
  * @return none
  */
  void CountryNetwork :: rotateNetwork(int n) {
    if (head == NULL)
    {
      cout << "Linked List is Empty" << endl;
      return;
    }
    int count = 0;
    Country* temp = head;
    while (temp != NULL)
    {
      temp = temp->next;
      count++;
    }
    if (n < 1 || n > count)
    {
      cout << "Rotate not possible" << endl;
      return;
    }
    count = 1;
    Country* pres = head;
    while (count != n && pres != NULL)
    {
      pres = pres->next;
      count++;
    }
    Country* nth = pres;
    while (pres->next != NULL)
    {
      pres = pres->next;
    }
    pres->next = head;
    head = nth->next;
    nth->next = NULL;
    cout << "Rotate Complete" << endl;
 }

 /*
  * Purpose: reverse the entire network
  * @param ptr head of list
  */
 void CountryNetwork::reverseEntireNetwork() {
   Country* prev = NULL;
   Country* pres = head;
   Country* nxt;
   while (pres != NULL)
   {
     nxt = pres->next;
     pres->next = prev;
     prev = pres;
     pres = nxt;
   }
   head = prev;
 }

 /*
  * Purpose: prints the current list nicely
  * @param ptr head of list
  */
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
