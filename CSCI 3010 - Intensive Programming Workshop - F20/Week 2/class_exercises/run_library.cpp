#include <iostream>
#include <vector>
#include "Library.h"

// Name(s): Felipe Lima
//
// Complete numbered coding tasks.
// Answer the questions with "Answer: " in the comments by writing your answer in the comments.
// some experiments might result in non-running/non-compiling code. Leave these experiments in, but
// comment them out.
// Turn in run_library.cpp, Library.h, and Library.cpp on Canvas before the end of class.
// make sure to leave a comment here and on canvas with your name and the name(s) of your partners.

int main() {
    // 1) Instantiate a couple Books. Set their fields equal to some values.
    // Print out the values of the books' fields.
    Book b1;
    Book b2;
    b1.author = "J.K. Rolling";
    b1.title = "Harry Potter";
    b2.author = "Jules Verne";
    b2.title = "Journey to the Center of the Earth";

    std::cout << "Book 1 title: " << b1.title << "; written by: " << b1.author << std::endl;
    std::cout << "Book 2 title: " << b2.title << "; written by: " << b2.author << std::endl;
    std::cout << "------------------------" << std::endl;


    // 2) Instantiate a Library.

    Library * l1 = new Library();
   
    // 3) Add a void Donate(Book b) method to your Library class.
    // Your Library should store the new book at the end of its shelf.
    // Done

    // 4) Donate one of the Books that you instantiated to your Library.

    l1->Donate(b1);

    // 5) Print out the books in the Library (use the given PrintBooks method)

    std::cout << "Printing out library: " << std::endl;
    l1->PrintBooks();

    // 6) Change the title and/or author of the book that you donated to
    // something different.
    // Print out the new book information, then print out the books in your
    // Library. Did changing the Book information change it in your Library?
    // Answer (and your hypothesis for why/why not): No it did not change the informatino of the book in the Library. It 
    // hasn't yet been updated in the vector once vector recive information by value.
    b1.author = "William Shakespere";
    b1.title = "Romeo and Juliet";
    std::cout << "------------------------" << std::endl;
    std::cout << "New book 1 title: " << b1.title << "; written by: " << b1.author << std::endl;
    std::cout << "Printing out library: " << std::endl;
    l1->PrintBooks();
    
    // 7) Create two Books that are separate structs (not pointers or references)
    // but that have the same information.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer: CANNOT make this comparison
    Book b3;
    b3.author = "Jules Verne";
    b3.title = "Journey to the Center of the Earth";
    // if (b2 == b3){ // CANNOT make this comparison
    //     std::cout<< "equal" << std::endl;
    // }
    // else{
    //     std::cout<< "not equal" << std::endl;
    // }


    // 8) Create two Book references to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer: // CANNOT make this comparison

    // Book &b2_ref = b2;
    // Book &b3_ref = b3;
    // if (b2_ref == b3_ref){ // CANNOT make this comparison
    //     std::cout<< "equal" << std::endl;
    // }
    // else{
    //     std::cout<< "not equal" << std::endl;
    // }


    // 9) Create two Book pointers to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer: //not equal memory spaces
    Book *b2_ptr = &b2;
    Book *b3_ptr = &b3;
    if (b2_ptr == b3_ptr){ 
        std::cout<< "equal" << std::endl;
    }
    else{
        std::cout<< "not equal" << std::endl;
    }



    // 10) Add a void Donate(Book b, int num_copies) method to your Library class.
    // your Library should add num_copies of Book b to its shelf. 
    // Done
    l1->Donate(b1, 5);
    l1->PrintBooks();



    // 11) Finally, if you reach this far, work on finding a solution to making it so
    // that you would be able to do any of the comparisons from # 7, 8, and 9
}
