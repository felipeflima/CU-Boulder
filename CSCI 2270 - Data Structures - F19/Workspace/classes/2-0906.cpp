#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;


void foo(int *z)
{
  cout << "z:" << z << endl << *z << endl; // printing the adress and then the integer
  *z = 22; // changes the value store in *z, *p and x
  cout << z << endl;
}

int main ()
{
  int x = 2, *p;
  p = &x;

  cout << x << endl << &x << endl; // x =  value of x // &x = adress of x
  cout << p << endl; // adress of p
  cout << *p << endl; // *p derefencing p, *p = x = 2

  *p = 5; // changes the value of x
  cout << x << endl; // x is now 5;

  foo(p); // passing a pointer to foo
  cout << x << endl;
  cout << *p << endl;
  cout << p << endl;

  return 0;
}

/* Dinamically Allocated Memory

Automatic variables get allocated on the stack.
Dynamically allocates variables get allocated at run-time and use the heap Memory (freestore)
In order to use the heap in C++ we use "new" and "delete" keywords.
Have to use pointer to allocate memnory on the heap

e.g.
int *p1;
p1 = new int; // nameless variable  allocation
// enough memory to store one int type variable.

delete p1; // deletes the memory in p1 -> free the memory back to the heap.
// does not delete pointer // can resuse pointer for other things

Dinamically Allocate Arrays:
  to alloc` an array on the heap:
  e.g.: length 5 Arrays
  int n;
  int *ptr;
  cin >> n;
  ptr = new int[n]; // allocate
  for (int i = 0; i < n; i++)
  {
    cin >> ptr[i]
  }

  delete [] ptr;
*/

/*
Array Doubling:
  Want an algorithm that will take an N length dynamic array and effectively double its length (so it becomes 2N)
  How:
1. Original array is pointed to by p
2. Create a new array of length 2N. Use new pointer for this (call it temp).
3. Now copy all of the contents of the orignal array (p) to the new array (temp).
4. Deallocate the original memory pointed to by p (delete p)
5. Tell p to point to new array (p=temp)


*/
