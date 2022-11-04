#include <iostream>

#include "Tree.h"

// Names: Felipe Lima
//


int main() {
    Tree oak;
    std::cout << "Number of trees: " << oak.get_number_seeds() << std::endl;

    // 0) Attempt to directly access the number_seeds_ static field here. Can you do so? why/why not?
    // std::cout << oak.number_seeds_ << std::endl; // inaccessible - private variable

    // 1) Instantiate another Tree object here
    Tree palmtree;

    // 2) Call get_number_seeds() from your tree object instantiated at #1
    std::cout << palmtree.get_number_seeds() << std::endl;
    std::cout << "-----------" << std::endl;

    // 3) Test to see whether pointers to your two Tree objects are equal.
    Tree *ptr_oak = &oak;
    Tree *ptr_palmtree = &palmtree;

    if(*ptr_oak == *ptr_palmtree){
        std::cout << "They are equal" << std::endl;
    }
    else{
        std::cout << "Not equal" << std::endl;
    }
    std::cout << "-----------" << std::endl;

    // 4) Call Seed() from the Tree object oak and Seed() from the Tree object instantiated at #1
    // Does changing the value of number_seeds_ from one tree object affect what you see from the
    // other Tree object by calling get_number_seeds()?
    oak.Seed();
    std::cout << "Oak: " << oak.get_number_seeds() << std::endl;
    std::cout << "Palmtree: " << palmtree.get_number_seeds() << std::endl;
    palmtree.Seed();
    std::cout << "Oak: " << oak.get_number_seeds() << std::endl;
    std::cout << "Palmtree: " << palmtree.get_number_seeds() << std::endl;
    std::cout << "-----------" << std::endl;

    // changing the value of number_seeds_ from one tree object affects the other one because number_seeds_ is static.


    // 5) Add a subclass of the Tree object. Your subclass should overwrite the Seed() method so that
    // when your subclass uses Seed(), the number_seeds_ should increase by two. Write adequate code
    // to experiment how the static field changes when calling Seed() with your regular Trees versus with the
    // derived class that you implemented. Don't forget the keyword virtual and remember that you shouldn't
    // add a new field to your Tree subclass to accomplish this!

    Coconut coco;

    oak.Seed();
    std::cout << "Oak: " << oak.get_number_seeds() << std::endl;
    std::cout << "Palmtree: " << palmtree.get_number_seeds() << std::endl;
    std::cout << "Coconut: " << coco.get_number_seeds() << std::endl;
    palmtree.Seed();
    std::cout << "Oak: " << oak.get_number_seeds() << std::endl;
    std::cout << "Palmtree: " << palmtree.get_number_seeds() << std::endl;
    std::cout << "Coconut: " << coco.get_number_seeds() << std::endl;
    coco.Seed();
    std::cout << "Oak: " << oak.get_number_seeds() << std::endl;
    std::cout << "Palmtree: " << palmtree.get_number_seeds() << std::endl;
    std::cout << "Coconut: " << coco.get_number_seeds() << std::endl;



    // 6) Add a public static variable to your Tree class that counts how many Trees (and Tree subclasses)
    // have been instantiated. Can you access this via a Tree instance? Can you access it without an instance of Tree?
    // e.g.
    //std::cout << Tree::variable_name << std::endl;
    //std::cout << instance.variable_name << std::endl;
    // can't access if it is private. you would have to use a getter function.

}
