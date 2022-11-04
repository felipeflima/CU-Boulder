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
