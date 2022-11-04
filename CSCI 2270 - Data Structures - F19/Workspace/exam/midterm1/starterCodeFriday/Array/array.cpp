#include<iostream>
#include<string>
using namespace std;

/*
// Split 'arr' into 'even_arr' & 'odd_arr'
//  - 'arr': pointer to original array
//  - 'even_arr': pointer to even array
//  - 'odd_arr': pointer to odd array
*/
void split(int* &arr, int* &even_arr, int* &odd_arr, int size, int &even_size, int &odd_size)
{
	//Implement this function
  int i = 0; //int to keep track of the original array
  int j = 0; // int to keep track of the even array
  int k = 0; // int to keep track of the odd array
  while (i < size)
  {
    if (arr[i]%2 !=0) //if  the number is odd
    {
      odd_size++; //increment the size of the odd array
      odd_arr[k] = arr[i]; // set the i element of the  original array to the k element of the odd array
      k++; // increment
    }
    if (arr[i]%2 == 0) //if the number is even
    {
      even_size++; //increment the size of the even array
      even_arr[j] = arr[i]; // set the i element of the  original array to the k element of the even array
      j++; //increment j
    }
    i++;//increment i
  }
}

void printArray(int* arr, int size) {
    for(int i = 0; i<size; i++)
    {
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;
}

int main(int argc, char* argv[])
{
    if(argc<2)
    {
      cout<<"usage: a.out <#>";
      return -1;
    }

	// Create input array:
    int size = stoi(argv[1]);
    int *arr = new int[size];

    cout<< "original array: ";
    for(int i = 0; i<size; i++)
    {
        arr[i] = rand()%100;
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;

	// Call your function with new arrays:
  int even_size = 0; // creates variable for the size of the even array
  int odd_size = 0; // creates variable for the size of the odd array
  int *odd_arr = new int[odd_size]; // creates new array and pointer to the array
  int *even_arr = new int[even_size]; // creates new array and pointer to the array

	split(arr, even_arr, odd_arr, size, even_size, odd_size); // calls the  split function

	// Output
  cout << "even array: ";
  if (even_size == 0)
  {
    cout << "no even items in the array" << endl;
  }
  else
  {
    printArray(even_arr, even_size); //prints even array
  }
  //printArray(even_arr, even_size); //prints even array

  cout << "odd array: ";
  if (odd_size == 0)
  {
    cout << "no odd items in the array" << endl;
  }
  else
  {
    printArray(odd_arr, odd_size); // prints odd array

  }

	// Clean up (delete)
  delete[] odd_arr;
  delete[] even_arr;

    return 0;
}
