#include <cmath>
#include "Point.h"

/*
CSCI 3010, PE 1 example solution, Spring 2020
Felix Muzny
Two dimensional point with Distance and Translate methods.
*/

/**
  Creates a new Point object with coordinates (0, 0)
*/
Point::Point() {
  x_ = 0;
  y_ = 0;
}

/**
  Creates a new Point object with coordinates x and y
  @param x int x coordinate
  @param y int y coordinate
*/
Point::Point(const int x, const int y) {
  x_ = x;
  y_ = y;
}

/**
  Calculates the distance between this point and another Point.
  @param other Point object to calculate the distance to
*/
double Point::Distance(const Point &other) const {
  // We can access p's x_ and y_ variables either through the
  // get_x(), get_y() accessor functions, or the x_, y_ private
  // member variables directly, since we're in a member function of
  // the same class.
  double distance = (x_ - other.get_x()) * (x_ - other.get_x());
  distance += (y_ - other.y_) * (y_ - other.y_);
  return sqrt(distance);
}

/**
  Moves this Point's coordinates by the amount given.
  @param amt int amount by which to move the coordinates of this Point.
*/
void Point::Translate(const int &amt) {
    x_ += amt;
    y_ += amt;
}
