#include <iostream>
using namespace std;

// any file that uses the SLL class must include this header file
#include "SLL.hpp"

int main(){

	SLL S0;

	Node* ptr;

	int arr[] = {2,7,0,1,9};
	int N = 5;

	for(int i = 0; i<N; i++){
		S0.addAtHead(arr[i]);
	}

	// NOTE: YOU WILL LIKELY NOT SEE THE TEST CASES UNTIL YOU SEE YOUR
	// STARTER CODE IN THE EXAM (will not be a part of the pre-24-hour code)

	// Pre-test:
	cout << "\nLinked list prior to tests: " << endl;
	S0.displayList();
	// Expected: 9->1->0->7->2->END

	// TEST CASE A - call function with 0
	cout << "Test case A:" << endl;
	/*
		Your function call here
	*/ 

	cout << " Expected: \n9->1->0->8->7->2->END \n Result: \n";
	S0.displayList();

	// TEST CASE B - call function with 8
	cout << "Test case B:" << endl;
	/*
		Your function call here
	*/ 
	cout << " Expected: \n9->1->0->8->7->7->2->END \n Result: \n";
	S0.displayList();

	return 0;
}
