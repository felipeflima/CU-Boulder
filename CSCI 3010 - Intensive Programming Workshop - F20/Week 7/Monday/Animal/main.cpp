#include <iostream>

#include "Animal.h"

// Name(s): Felipe Lima

int main() {

  Reptile ralph("alligator");
  std::cout << ralph.MakeSound() << std::endl;

  // 1) Instantiate another animal 
  Animal lion("roar");

  // 2) Call the Fight method of animal
  lion.Fight(ralph);
  std::cout << "---------" << std::endl;

  // 3) Go to the Animal.h file and define some new subclasses of animal
  // Define one class that inherits from Animal and
  // one class that inherits from a child class of Animal

  // 4) Instantiate at least one object of each class you defined for #3
  Mammal Dog("woof");
  Tiger jeff("rawrrr");

  // 5) Have a tournament between the animals that you have instantiated 
  ralph.Fight(lion);
  ralph.Fight(Dog);
  ralph.Fight(jeff);

  lion.Fight(Dog);
  lion.Fight(jeff);

  Dog.Fight(jeff);

  // 6) turn in Animal.h and main.cpp on canvas
    
	return 0;
}