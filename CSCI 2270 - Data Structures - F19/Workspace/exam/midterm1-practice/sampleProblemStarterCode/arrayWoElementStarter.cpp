#include <iostream>
using namespace std;

// Write a C++ function to copy all elements of an array to a new array,
// except for a specified value, and return the new array. 
int *CopyArray(int array[], int &length, int value);


int main(){

    // TEST CASE A - call function with array {1,2,3,4} and value 3
    int lengthA1 = 4;
    int * a1 = new int[lengthA1] {1,2,3,4};
    int value = 3;
    cout << "TEST CASE A:\n";
    cout << "input array: ";
    for(int i = 0; i<lengthA1; i++){
        cout << a1[i] << " ";
    }
    cout << "; value = " << value << "\n";

    int *newArr = CopyArray(a1, lengthA1, value);
    cout << "Expected output: 1 2 4" << endl;
    // Resulting new array
    cout << "Output: ";
    for(int i = 0; i<lengthA1; i++){
        cout << newArr[i] << " ";
    }
    cout << endl;
    cout << "-----------------------------\n\n";
    delete [] a1;
    delete [] newArr;

    // TEST CASE B - call function with array {1,2,3,2,2} and value 2
    lengthA1 = 5;
    a1 = new int[lengthA1] {1,2,3,2,2};
    value = 2;
    cout << "TEST CASE B:\n";
    cout << "input array: ";
    for(int i = 0; i<lengthA1; i++){
        cout << a1[i] << " ";
    }
    cout << "; value = " << value << "\n";

    newArr = CopyArray(a1, lengthA1, value);
    cout << "Expected output: 1 3" << endl;
    // Resulting new array
    cout << "Output: ";
    for(int i = 0; i<lengthA1; i++){
        cout << newArr[i] << " ";
    }
    cout << endl;
    cout << "-----------------------------\n\n";

    return 0;
}

int *CopyArray(int array[], int &length, int value){
  int arr[length-1];
  for (int i = 0; i < length-1; i ++)
  {
    if (array[i] != value)
    {
      arr[i] = array[i];
    }
    if  (array[i] == value)
    {
      arr[i] = array[i+1];
    }

    cout << arr[i] << endl;
  }
  for (int j = 0;j< length;j++)
  {
    array[j] = arr[j];
  }
  return arr;

}
