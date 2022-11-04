#include<iostream>
#ifndef ANIMAL_H
#define ANIMAL_H

// Name(s):
//

class Animal {
public:
	Animal(std::string sound):
	sound_(sound)
	{}

	std::string MakeSound() const {return sound_; }

	void Fight(Animal &opponent);

	virtual int GetPower() { return 0; };

private:
	std::string sound_;
};

class Reptile : public Animal {
public:
	Reptile(std::string sound):
	Animal(sound + " rawr!")
	{}


	int GetPower() { return 2; };

};

class Mammal : public Animal {
public:
	Mammal(std::string sound):
	Animal(sound + " woo!")
	{}

	int GetPower() { return 3; };

};

class Tiger : public Mammal {
public:
	Tiger(std::string sound):
	Mammal(sound + " miau!")
	{}

	int GetPower() { return 4; };

};


// Define your animals here.
// Define one class that inherits from Animal and
// one class that inherits from a child class of Animal

#endif  // ANIMAL_H
