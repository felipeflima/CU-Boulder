/*
*Recap Linked Lists
The abstarct Data Type (ADT)
search method
insert method
*/

#include <iostream>
using namespace std;


/*
  Linked Lists:
* A data structure that allows individual elements to ber added and deleted as needed
* Typically, allocades dynamically
* Memory is allocated and deallocated for each individual element as it is added or removed
* Each element:
  * Called a Node
  * Node contains a kew value(s) a pointer to the next node
* Access the LL via the head pointer
* The end of a LL is denoted by a next = nullptr
*/

/*
  Abstract Data Type (ADT)
* Collection of memeber data nad the allowed operations on that Data
* Abstarct, because the use (i. e. the programmer) only has info about the inputs the outputs and aexplanation of the actions
* Can think of it as a pseudocode for a class definition
* Not language specific

*/

/*
  Singly Linked List Generic ADT
private:
    head - ptf to first element in list. Null means empty list.

  public:
    initialize() - set header to null
    nodePtr = serach()
    insertNode(previousPtr, new Value) - given
    a new node right after it
    displayList() - starting at head, transverse the list and display all keys
    deleteNode(nodePtr) - given a  ptr to a node, remove node from the LL

  Rule to keep in mind:
    Every method in the ADT should be designmend such that once it performs its task, the integrity of the data structure is preserved

    example violation: delete a node and forget to reconnect the pointers properly


*/


/*
Implementation in C++

Where to start?
  Contructor definition? - gets called when the object is  instantiated, so not bad place to start
  We want to start building the list, so displayList next? structure

1. constructor  - test compile
2. search - test compile; call seach() from fdriver with same test string, Expect is a null ptr
3. display - test: compile
4. insert
  a. empty list case - test: insert node, display
  b. insert before head - test: insert node, display
  c. insert anywhere else - test : insert node, display
*/
