#include <iostream>
#include <vector>

// scope: "what can we see right here"
// - what variables/functions/other can we access from inside x, where x is a function, method, etc.

// 1) what happens in c++ if you try to acces a variable out of scope?  compile error - segmentation fault

// 2) what happens if we make everything global? // namespace pollution -- changed to easily


// Summary:
// pass-by-value vs. pass-by-reference
// pass-by-value: give the function a copy of the value
// pass-by-reference: give the address of the location of the value


// *************************************************


// When you are done: turn in your file on canvas

// Names (be sure to include the initial of your last name(s)!):
// FELIPE LIMA

// 1) Write a function that demonstrates whether ints are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:
void integer(int x){
    x+=10;
    std::cout << "Inside: " << x << std::endl;
}


// 2) Write a function that tests demonstrates whether strings (std::string) are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:
void string(std::string str){
    str = "World";
    std::cout << "Inside: " << str << std::endl;
}


// 3) Write a function that demonstrates whether arrays are pass-by-value or pass-by-reference
// recall: to initialize an array-- type name[] = {comma separated elements};
// (do not use pointers or c++ references in this function)
// Answer:
void array(int arr[]){
    arr[0] = 4;
    arr[1] = 5;
    std::cout << "Inside: ";
    for (int i =0; i < 2; i++ ){
         std::cout <<  arr[i] << " ";
    }
    std::cout << std::endl;
}


// 4) Write a function that demonstrates whether vectors are pass-by-value or pass-by-reference
// Answer:
void vector(std::vector<int> vec)
{
    vec = {3,2,1};
    std::cout << "Inside: ";
    for (int i =0; i < 3; i++ ){
         std::cout <<  vec[i] << " ";
    }
    std::cout << std::endl;

}


int main() {
    // code to call your functions goes here.
    int x = 5;
    std::cout << "Integer" << std::endl;
    std::cout << "Before: " << x << std::endl;
    integer(x);
    std::cout << "After: " << x << std::endl;
    std::cout << "Therefore pass by value" << std::endl;

    std::cout << "-------" << std::endl;

    std::string str = "Hello";
    std::cout << "String" << std::endl;
    std::cout << "Before: " << str << std::endl;
    string(str);
    std::cout << "After: " << str << std::endl;
    std::cout << "Therefore pass by value" << std::endl;

    std::cout << "-------" << std::endl;

    int arr[2] = {1,2};
    std::cout << "Array" << std::endl;
    std::cout << "Before: ";
    for (int i =0; i < 2; i++ ){
         std::cout <<  arr[i] << " ";
    }
    std::cout << std::endl;
    array(arr);
    std::cout << "After: ";
    for (int i =0; i < 2; i++ ){
         std::cout <<  arr[i] << " ";
    }
    std::cout << "Therefore pass by reference" << std::endl;

   std::cout << "-------" << std::endl;

   std::vector<int> vec = {1,2,3};
   std::cout << "Vector" << std::endl;
   std::cout << "Before: ";
    for (int i =0; i < 3; i++ ){
         std::cout <<  vec[i] << " ";
    }
    std::cout << std::endl;
    vector(vec);
    std::cout << "After: ";
    for (int i =0; i < 3; i++ ){
         std::cout <<  vec[i] << " ";
    }
    std::cout << std::endl << "Therefore pass by value" << std::endl;



    

    // you may find it useful to print out values in main as well as inside your functions
    // to appropriately demonstrate whether the given type is pass-by-value or 
    // pass-by-reference

}
