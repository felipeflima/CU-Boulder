#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

void pt ()
{
    int *p; // pointer
    int x = 3;
    cout << &x << endl; // prints the adress of the variable
    p=&x; //assigns pointer to address of x
    cout << x << endl; //prints x
    cout << *p << endl; //prints x / p == x / wothout the * prints adress

}

// pass by pointer
void myPBP (int *p) //adress is being passed // must call with a pointer type
// by passing a piner to a function, the fucntion has access to original variable
{

}

int main()
{
    pt();
    int *myPtr;
    myPBP(myPtr);
    // alternative
    // int x;
    // myPBP(&x);
}

// pass by value
    // - reference
        // caller gives access to original variable; change made inside of function will persist in the callers variable space
    // - array
        // passing the adress of the first elemnt of the array
    // - pointer
