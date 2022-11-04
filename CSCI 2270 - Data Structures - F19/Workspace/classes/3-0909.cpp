/*
* Finish up with dynamic memory allocation
* Array doubling coding example (all in main)
* C++ classes reviews
* Multiple files compilation
*/

#include <iostream>
using namespace std;

/*
Array doubling recap

Dynamic memory allows us to request new memory space at runtime.
We can use this fact to expand our arrays at program runtime (as needed)
*/

int a ()
{
  int x;
  int *p = &x;
  x = 9;
  int *p0;
  p0 = new int;

  cout << x << endl;
  cout << p0 << endl;

  cout << *p0 << endl;
  *p0 = 7;
  cout << *p0 << endl;

  delete p0;
  cout << *p0 << endl;
  cout << p0 << endl;

  return 0;
}


void b ()
{
  int n = 5; // allocate on heap

  int *p = new int[n];
  // here we would fill the array with some data
  // p[0] = something

  //let's begin the array doubling algorithm

  int *temp = new int[2*n];
  // copy over first n elements

  for ( int i = 0; i < n; i++)
  {
    temp[i] = p[i];
  }

    //dealocate original Memory
    delete [] p;

    // point p to the new block of memeory that's 2n in length

    p = temp;

}

void arrayDouble (int *&a, int length);

int main ()
{
  int *p = x;
}
