// SLL.h - interface file (header file)
#ifndef SLL_H
#define SLL_H

struct Node{
	int key;
	Node *next;
};

class SLL{
private:
	Node* head;

public:
	SLL(); // constructor declaration

	~SLL(); // destructor declaration

	Node* search(int sKey);
	// Precondition: sKey parameter is a int type

	// Postcondition:  if found, returns a pointer to the node containing sKey value.
	// If not found, returns a null pointer.

	void displayList();
	// Precondition: the head node is defined.

	// Post condition: display the key values of the entire list, starting with
	// first node and ending with last node.

	void addAtHead(int newValue);
	// Precondition: newValue is a valid int.

	// Postcondition: a new node is created and newValue is stored as its key.
	// The new node is added before the head of the linked list.
	
	void deleteNode(Node* deleteNode);
	// Precondition: head pointer is set.

	// Post condition: node pointed to by deleteNode is removed from linked list.

};





#endif
