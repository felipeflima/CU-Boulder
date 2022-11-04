#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(){
        head = NULL;
    }

LinkedList::~LinkedList(){
	Node* crawler;
	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}

// Add a new Node to the list
void LinkedList::insert(Node* prev, int newKey){

    //Check if head is Null i.e list is empty
    if(head == NULL){
        head = new Node;
        head->key = newKey;
        head->next = NULL;
    }

        // if list is not empty, look for prev and append our Node there
    else if(prev == NULL)
    {
        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = head;
        head = newNode;
    }

    else{

        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = prev->next;
        prev->next = newNode;

    }
}



// Building list
void LinkedList::loadList(int* keys , int length) {

    insert(NULL, keys[0]);

    Node* prev = head;

    for(int i = 1; i < length; i++)
    {
        insert(prev, keys[i]);
        prev = prev->next;
    }

}

// Print the keys in your list
void LinkedList::printList(){
    Node* temp = head;

    while(temp->next != NULL){
        cout<< temp->key <<" -> ";
        temp = temp->next;
    }

    cout<<temp->key<<" -> NULL"<<endl;
}

///////////////////////////////////////////////////////////////
// TODO : Complete the following function
void LinkedList::removeNthFromEnd(int n){

  Node* pres = head;  // creates present pointer that points to head
  Node* prev = head;  // creates previous pointer that points to head
  Node* temp = head; // creates temp pointer that points to head
  int i = 0; // creates integer i to compare  to n
  int counter =  0; //creates counter to know the size of the ll
  while (temp != NULL) // loop to count the size of the LL
  {
    temp = temp->next;
    counter++;
  }
  if (n == counter) //if n is the same as the size of the LL, removes the first node
  {
    head = head->next;
    return;
  }
  while (i <= n) // move the pres pointer, n+1 nodes from the head and prev pointer
  {
    pres = pres->next;
    i++;
  }
  while (pres != NULL) //moves both pres and prev equally until pres reaches the end of the LL
  {
    pres = pres->next;
    prev = prev->next;
  }
  prev->next = prev->next->next; // removes the nth pointer from the end
  delete temp; // dealocates the pointer temp
  delete pres; // dealocates the pointer pres
}
