#include <iostream> // predefined header file (defined for you)
using namespace std;

#include "SLL.hpp" // your own header file
// <> vs "" -- compiler looks for the file in the C++ implementation
// vs in the current directory


SLL::SLL(){ // constructor definition
	head = nullptr;
}

SLL::~SLL(){
	Node* crawler;

	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}

Node* SLL::search(int sKey){

	Node* crawler = head;

	while( crawler != nullptr && crawler->key != sKey){
		crawler = crawler->next;
	}

	return crawler;

}

void SLL::displayList(){
	Node* crawler = head;
	while( crawler != nullptr ){
		cout << crawler->key << "->";
		crawler = crawler->next;
	}

	cout << "END\n\n" << endl;
}

void SLL::addAtHead(int newValue){
	if(head == nullptr){
		// first case: empty list
		// add new node and make head point to it
		head = new Node;
		head->key = newValue;
		head->next = nullptr; // what if we forget this line?
	}
	else{
		// This condition implies that the list is not empty
		// add node before the head node
		Node* newNode = new Node;
		newNode->key = newValue;
		newNode->next = head;
		head = newNode;
	}
}


void SLL::deleteNode(Node* deleteNode){
	if( deleteNode != nullptr){
		// check if deleteNode is head
		if( deleteNode == head ){
			head = head->next;
			delete deleteNode;
		}
		//traverse the list:
		else{
			Node* crawler = head;
			// Stop at node prior the node to be deleted
			while(crawler->next != deleteNode){
				crawler = crawler->next;
			}

			// reconnect the LL around the node about to
			// be removed
			crawler->next = crawler->next->next;

			// deallocate
			delete deleteNode;
		}

	}
	else{
		cout << "Node doesn't exist. Nothing to do." << endl;
	}

}


