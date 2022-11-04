/* CSCI 3010 - IPW
* Felipe Lima
* Programming Exercise 3 - References and Bash scripting
* 09/011/2020
* What it does: Code follows a series of intruction to create ints, references, and pointer and experiment with them
* How to run: using Makefile
~make
~./main
*/

#include <iostream>

// Name: Felipe Lima
//

#define out
// Write any functions you need here!


/**
 * Position class for exercise 15
 * Creates a class with points x and y
 * Methods to construc, get, compare and add objects
 */
class Position {
    public:
        Position(){
            x_ = 0;
            y_ = 0;
        }
        Position(int x, int y){
            x_ = x;
            y_ = y;
        }
        int GetXCord(){ return x_;}
        int GetYCord(){ return y_;}
        bool operator==(const Position &p){
            return x_ == p.x_ && y_ == p.y_;
        }
        Position operator+(const Position &p){
            Position new_p;
            new_p.x_ = x_ + p.x_;
            new_p.y_ = y_ + p.y_;
            return new_p;
        }
    private:
        int x_;
        int y_;
};


/**
 * prints the pointer passed to the function
 * @param pointer
 */
void pointer(int *ptr){
    std::cout << "*ptr: " << *ptr << std::endl;
}

/**
 * prints the reference passed to the fuction
 * @param int reference\
 */
void integerAnd(int &ref){
    std::cout << "ref: " << ref << std::endl << "&ref: " << &ref << std::endl;
}

/**
 * sets the outpiut paramenter to be equal to the refernce value passed to the function
 * @param constant reference, output param
 */
void func14(const int &ref_14, out int *ptr_14){
    *ptr_14 = ref_14;
}


int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.
    
    // 1) Declare an int
    std::cout << "1)" << std:: endl;
    int a = 0; //declaring
    std::cout << "a: " << a << std::endl;
    std::cout << "------------" << std::endl;

    // 2) Declare a pointer to that int
    std::cout << "2)" << std:: endl;
    int *ptr_a = &a; // declaring
    std::cout << "*ptr_a: " << *ptr_a << std::endl;
    std::cout << "------------" << std::endl;

    // 4) Declare a reference to your int
    std::cout << "4)" << std:: endl;
    int &ref_a = a; //declaring
    std::cout << "ref_a: " << ref_a << std::endl;
    std::cout << "------------" << std::endl;

    // 5) Increment the int via the reference
    std::cout << "5)" << std:: endl;
    ref_a++; //incrementing
    std::cout << "a: " << a << std::endl;
    std::cout << "ref_a: " << ref_a << std::endl;
    std::cout << "*ptr_a: " << *ptr_a << std::endl;
    std::cout << "------------" << std::endl;

    // 6) When you increment the int via the variable declared in #1, which
    // variables will be modified to see the changes? (the pointer , reference or both?)
    // Answer: 
    std::cout << "6)" << std:: endl;
    a++; // increment
    std::cout << "a: " << a << std::endl;
    std::cout << "ref_a: " << ref_a << std::endl;
    std::cout << "*ptr_a: " << *ptr_a << std::endl;
    std::cout << "Answer: Both the pointer and the reference will be modified." << std:: endl;
    std::cout << "------------" << std::endl;

    // 7) When you increment the int via the pointer declared in #2, which
    // variables will be modified to see the changes?
    // Answer: 
    std::cout << "7)" << std:: endl;
    (*ptr_a)++; //increment
    std::cout << "a: " << a << std::endl;
    std::cout << "ref_a: " << ref_a << std::endl;
    std::cout << "*ptr_a: " << *ptr_a << std::endl;
    std::cout << "Answer: Both the pointer and the reference will be modified." << std:: endl;
    std::cout << "------------" << std::endl;
    

    // 8) When you increment the int via the reference declared in #4, which
    // variables will be modified to see the changes?
    // Answer: 
    std::cout << "8)" << std:: endl;
    ref_a++; //increment
    std::cout << "a: " << a << std::endl;
    std::cout << "ref_a: " << ref_a << std::endl;
    std::cout << "*ptr_a: " << *ptr_a << std::endl;
    std::cout << "Answer: Both the pointer and the reference will be modified." << std:: endl;
    std::cout << "------------" << std::endl;

    // 9) Write a function that takes an int * parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and function call below)
    std::cout << "9)" << std:: endl;
    void pointer(int *ptr);
    pointer(&a); //passing the address of the variable
    std::cout << "------------" << std::endl;


    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer:
    std::cout << "10)" << std:: endl;
    //pointer(ref_a);
    std::cout << "Answer: No. The function in #9 is expecting an address as a variable to the pointer." << std:: endl;
    std::cout << "------------" << std::endl;


    // 11) Write a function that takes an int & parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and call below)
    std::cout << "11)" << std:: endl;
    void integerAnd(int &ref);
    integerAnd(a); //passing the variable as an int
    std::cout << "&a: " << &a << std::endl;
    std::cout << "------------" << std::endl;

    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer:
    std::cout << "12)" << std:: endl;
    //integerAnd(ptr_a);
    std::cout << "Answer: No. The function in #11 is expecting an integer value as a variable to the reference." << std:: endl;
    std::cout << "------------" << std::endl;

    // 13) Can you pass your reference from #4 to the function from #11?
    // Answer:
    std::cout << "13)" << std:: endl;
    integerAnd(ref_a);
    std::cout << "Answer: Yes. The function in #11 is expecting an integer value as a variable to the reference. Since the reference from 4 is a reference to an integer, you can pass it to the function in #11." << std:: endl;
    std::cout << "------------" << std::endl;

    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.
    std::cout << "14)" << std:: endl;
    void func14(const int &ref_14, out int *ptr_14); 
    int output = 0;  
    std::cout << "output: " << output << std::endl;
    std::cout << "function call" << std::endl;
    func14(a, &output);
    std::cout << "first output: " << output << std::endl;
    std::cout << "function call" << std::endl;
    func14(2, &output);
    std::cout << "second output: " << output << std::endl;
    std::cout << "function call" << std::endl;
    int random = 78;
    func14(random, &output);
    std::cout << "third output: " << output << std::endl;
    std::cout << "------------" << std::endl;


    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer:
    std::cout << "15)" << std:: endl;
    std::cout << "When you want to return one or more items with a data type then it is better to use an output parameter. Return value has to be unique and can be used to report the succes of the function call." << std:: endl;
    std::cout << "------------" << std::endl;


    // 16) Create a custom class with at least one private field/class attribute. Overload the == and + operator for this class
    // such that == can be used to compare the objects of the class and + can be used to add
    // 2 objects of the class together. Implement an appropriate constructor for your class.
    // When you overload these operators, the resulting return value should make sense.
    // Instantiate at least 2 objects of this class and perform the == and + operations on them.
    // hint: for operator+, the function signature when implemented as a member function of the Object class is:
    // Object operator+(const Object &other)
    // Answer:

    std::cout << "16)" << std:: endl;
    Position p1(1,2); //creating points
    Position p2(1,2);

    //printing coordinates
    std::cout << "p1 coodinates: (" << p1.GetXCord() << "," << p1.GetYCord() << ")" << std::endl;
    std::cout << "p2 coodinates: (" << p2.GetXCord() << "," << p2.GetYCord() << ")" << std::endl; 

    //comparing usinf the overloaded operator ==
    if (p1 == p2){
        std::cout << "p1 and p2 are equal" << std::endl;
    }

    //creating point 3 using the compbination of p1 and p2 by adding with the overloaded operator +
    Position p3 = p1+p2;
    std::cout << "p3 = p1 + p2" << std::endl;
    std::cout << "p3 coodinates: (" << p3.GetXCord() << "," << p3.GetYCord() << ")" << std::endl; 

}
