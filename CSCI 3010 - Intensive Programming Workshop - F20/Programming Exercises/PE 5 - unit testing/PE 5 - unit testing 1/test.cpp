/** CSCI 3010 - IPW
* Felipe Lima
* Programming Exercise 5 - unit testing
* 09/29/2020
* What it does: Test cases for the Reactangle.cpp file
* How to run: using Makefile
~ make
~ ./test
*/
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Rectangle.h"
//#include "Rectangle.o"


// TEST_CASE ( "Factorials are computed", "[factorial]") {
//   REQUIRE( Factorial(2) == 2 );
//   REQUIRE( Factorial(3) == 6 );
// }

/**
 * checks the Rectangle contrusctor
*/
TEST_CASE ("Checks if a Rectangle is created correctly", "[Rectangle::Rectangle]"){
  Point p1 = {2,5};
  Point p2 = {3,7};
  Rectangle r1(p1,p2);
  int p1_x = r1.get_p1().x;
  int p1_y = r1.get_p1().y;
  int p2_x = r1.get_p2().x;
  int p2_y = r1.get_p2().y;
  REQUIRE(p1_x <= p2_x); // checks if points are in the right order
  REQUIRE(p1_y <= p2_y); // checks if points are in the right order
  REQUIRE(p1_x == p1.x); // check if they were assigned correclty
  REQUIRE(p1_y == p1.y);
  REQUIRE(p2_x == p2.x);
  REQUIRE(p2_y == p2.y);

  p1 = {234,34};
  p2 = {3,7};
  Rectangle r2(p1,p2);
  p1_x = r2.get_p1().x;
  p1_y = r2.get_p1().y;
  p2_x = r2.get_p2().x;
  p2_y = r2.get_p2().y;
  CHECK(p1_x <= p2_x);
  CHECK(p1_y <= p2_y);
  CHECK(p1_x == p2.x);
  CHECK(p1_y == p2.y);
  CHECK(p2_x == p1.x);
  CHECK(p2_y == p1.y);
}

/**
 * checks the GetWidth
*/
TEST_CASE ( "Test the witdh of the rectangles", "[Rectangle::GetWidth]" ){
  Point p1 = {2,5};
  Point p2 = {3,7};
  Rectangle r1(p1,p2);
  REQUIRE (r1.GetWidth() == (p2.x - p1.x)); // requires it to use the right param to calculate

  Rectangle r2(p2,p1);
  CHECK (r2.GetWidth() == (p2.x - p1.x));

  p1 = {29,-38};
  p2 = {22,95};
  Rectangle r3(p1,p2);
  REQUIRE (r3.GetWidth() == 7); //check using actual value
}

/**
 * checks the GetWidth
*/
TEST_CASE ( "Test the height of the rectangles", "[Rectangle::GetHeight]" ){
  Point p1 = {2,5};
  Point p2 = {3,7};
  Rectangle r1(p1,p2);
  REQUIRE ( r1.GetHeight() == (p2.y - p1.y)); // requires it to use the right param to calculate

  Rectangle r2(p2,p1);
  CHECK ( r2.GetHeight() == (p2.y - p1.y));

  p1 = {29,95};
  p2 = {23,-38};
  Rectangle r3(p1,p2);
  REQUIRE ( r3.GetHeight() == 133); //check using actual value
}

/**
 * checks the Overlaps
*/
TEST_CASE ( "Testing if rectangles overlap", "[Overlaps]"){
  Point p1 = {2,5};
  Point p2 = {5,10};
  Rectangle r1(p1,p2);
  Rectangle r2(p1,p2);
  CHECK (r1.Overlaps(r2) == true);

  Rectangle r3(p2,p1);
  CHECK (r1.Overlaps(r3) == true);

  Point p3 = {0,0};
  Point p4 = {1,1};
  Rectangle r4(p1,p2);
  Rectangle r5(p3,p4);
  CHECK (r4.Overlaps(r5) == false);

  Rectangle r6(p3,p3);
  CHECK (r6.Overlaps(r5) == true);

  Point p5 = {1,4};
  Point p6 = {3,7};
  Rectangle r7(p5,p6);
  CHECK (r7.Overlaps(r1) == true);

  CHECK (r7.Overlaps(r5) == false);
}

/**
 * checks the CalculateArea
*/
TEST_CASE ( "Testing if calculate area is correct", "[CalculateArea]"){
  Point p1 = {2,5};
  Point p2 = {3,7};
  Rectangle r1(p1,p2);
  CHECK (r1.CalculateArea() == 2);

  Rectangle r2(p1,p2);
  CHECK (r2.CalculateArea() == 2);

  Point p3 = {-1,0};
  Rectangle r3(p1,p3);
  CHECK (r3.CalculateArea() == 15);

  Point p4 = {-5,12};
  Rectangle r4(p3,p4);
  CHECK (r4.CalculateArea() == r4.GetHeight() * r4.GetWidth());
}

/**
 * checks the Expand
*/
TEST_CASE ( "Testing if the rectangle expands correctly", "[Expand]"){
  Point p1 = {2,5};
  Point p2 = {3,7};
  Rectangle r1(p1,p2);
  r1.Expand();
  int p1_x = r1.get_p1().x;
  int p1_y = r1.get_p1().y;
  int p2_x = r1.get_p2().x;
  int p2_y = r1.get_p2().y;
  CHECK (p1_x == 1); 
  CHECK (p1_y == 4);
  CHECK (p2_x == 4);
  CHECK (p2_y == 8);


  p1 = {2,5};
  p2 = {1,1};
  Rectangle r2(p1,p2);
  r2.Expand();
  p1_x = r2.get_p1().x;
  p1_y = r2.get_p1().y;
  p2_x = r2.get_p2().x;
  p2_y = r2.get_p2().y;
  CHECK (p1_x == 0); //inverted values because Rectangle() should invert them
  CHECK (p1_y == 0);
  CHECK (p2_x == 3);
  CHECK (p2_y == 6);
}

/**
 * checks the Shrink
*/
TEST_CASE ( "Testing if the rectangle shrinks correctly", "[Shrink]"){
  Point p1 = {2,5};
  Point p2 = {3,7};
  Rectangle r1(p1,p2);
  r1.Shrink();
  int p1_x = r1.get_p1().x;
  int p1_y = r1.get_p1().y;
  int p2_x = r1.get_p2().x;
  int p2_y = r1.get_p2().y;
  CHECK (p1_x == 3);
  CHECK (p1_y == 6);
  CHECK (p2_x == 2);
  CHECK (p2_y == 6);


  p1 = {2,5};
  p2 = {1,1};
  Rectangle r2(p1,p2);
  r2.Shrink();
  p1_x = r2.get_p1().x;
  p1_y = r2.get_p1().y;
  p2_x = r2.get_p2().x;
  p2_y = r2.get_p2().y;
  CHECK (p1_x == 2);
  CHECK (p1_y == 2);
  CHECK (p2_x == 1);
  CHECK (p2_y == 4);
}