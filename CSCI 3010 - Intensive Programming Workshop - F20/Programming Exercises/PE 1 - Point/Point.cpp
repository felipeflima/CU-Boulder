/* CSCI 3010 - IPW
* Felipe Lima
* Programming Exercise 1 - Point
* 08/29/2020
* What it does: Code follows a series of intruction to create points in a 2D plane, calculate 
the distance bewteen them and translate them to different points
* How to run: using Makefile
~make
~./main
*/

#include <iostream>
#include <math.h>
#include "Point.h"
using namespace std;


Point::Point(){ // constructor with no args - creates a point at the origin
    x_ = 0;
    y_ = 0;
}

Point::Point(int x_val, int y_val){ // contructor with args - creates a point at the given coordinate
    x_ = x_val;
    y_ = y_val;
}

int Point::GetXCord(){ // getter funtion returns the value of the x_ coordinate
    return x_;
}

int Point::GetYCord(){ // getter funtion returns the value of the y_ coordinate
    return y_;
}

void Point::SetXCord(int x_point){ // setter function sets the value of the x_ coordinate as the passed argument
    x_ = x_point;
}

void Point::SetYCord(int y_point){ // setter function sets the value of the y_ coordinate as the passed argument
    y_ = y_point;
}

/* Distance function uses the Ecledian formula to calculate the distance between two given points. point 1 being the one used to call the 
function and point 2 passed as an argument
Formula: dist = √[(x_ - a)² + (y_ - b)²]
*/
double Point::Distance(int x2, int y2){ // arguments are the coordinates of point 2
    double dist, x_dist, y_dist;  // creates variable to help calculate distance
    x_dist = x2 - x_; // calculates the distance between xs
    y_dist = y2 - y_; // calculates the distance between ys

    dist = pow(x_dist, 2) + pow(y_dist, 2); // squares and adds both x and y distances
	dist = sqrt(dist);    // tak the square root of the result

    return dist;     // return the calculated distance
}

void Point::Translate(int x_move, int y_move){ //move the point's coordinates by whatever integer value is passed
    x_ += x_move; // move x coordinate
    y_ += y_move; // move y coordinate
}




