#include <iostream>
#include "Point.h"

/*
CSCI 3010, PE 1 example solution, Spring 2020
Felix Muzny
Two dimensional point with Distance and Translate methods.

Use Makefile to compile. "make" will produce executable "main". Run (on unix systems) with "./main"
*/

int main(int argc, char **argv){
	Point p1;
	Point p2(4, 6);

	std::cout << "p1 is: (" << p1.get_x() << ", ";
	std::cout << p1.get_y() <<  ")" << std::endl;

	std::cout << "p2 is: (" << p2.get_x() << ", ";
	std::cout << p2.get_y() << ")" << std::endl;

	Point p3(1, 2);
	std::cout << "p3 is: (" << p3.get_x() << ", ";
	std::cout << p3.get_y() << ")" << std::endl;
	std::cout << "dist p1 & p2: " << p1.Distance(p2) << std::endl;
	std::cout << "dist p1 & p3: " << p1.Distance(p3) << std::endl;
	std::cout << "dist p2 & p3: " << p2.Distance(p3) << std::endl;

    p1.Translate(10);
	std::cout << "p1 after +10 translation is: (" << p1.get_x() << ", ";
	std::cout << p1.get_y() <<  ")" << std::endl;
	std::cout << "dist p1 & p2: " << p1.Distance(p2) << std::endl;
	std::cout << "dist p1 & p3: " << p1.Distance(p3) << std::endl;
    p1.Translate(-73);
	std::cout << "p1 after -73 translation is: (" << p1.get_x() << ", ";
	std::cout << p1.get_y() <<  ")" << std::endl;
	std::cout << "dist p1 & p2: " << p1.Distance(p2) << std::endl;
	std::cout << "dist p1 & p3: " << p1.Distance(p3) << std::endl;

	return 0;
}
