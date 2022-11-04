/* CSCI 3010 - IPW
* Felipe Lima
* Programming Exercise 2 - Generalized Point
* 09/03/2020
* What it does: Code follows a series of intruction to create points in a n-plane, calculates 
the distance bewteen them and translate them to different points
* How to run: using Makefile
~make
~./main
*/

#include <iostream>
#include <math.h>
#include<vector>
#include "Point.h"
using namespace std;

/**
    Creates a point at the origin with n dimensions
    Constructor
    @param num_dimensions number of dimensions
*/
Point::Point(int num_dimensions){
    for (int i = 0; i < num_dimensions; i++){ //through the length of the vector
        coord_.push_back(0); //push "0" to the end of the vector
    }
}

/**
 * Creates a point at the given coordinates
 * Constructor
 * @param temp_coord vector with the coordinates of the new point
*/
Point::Point(vector<int> temp_coord){ 
    coord_ = temp_coord; // sets the class vector equal to the vector passed to the function
}

/**
 * Return the dimensions of a point
 * @return dimensions of the point
*/
int Point::PointDimensions(){ // returns the dimensions of the point by returning the size of the vector
    return coord_.size();
}

/**
 * Getter funtion returns the value of the coordinates, by returning the vector
 * @return vector
*/
vector<int> Point::GetCords(){ 
    return coord_;
}

/**
 * Getter funtion returns the value of one coordinate at the n dimension
 * @param n dimention
 * @return single coordinate
*/
int Point::GetNCord(int n){
    return coord_[n];
}

/**
 * Setter function sets the value of the coordinates as the passed argument
 * @param new_coord vector with new coordinates
*/
void Point::SetCords(vector<int> new_coord){
    coord_ = new_coord;
}


/* Distance function uses the Ecledian formula to calculate the distance between two given points. point 1 being the one used to call the 
function and point 2 passed as an argument
Formula: dist = √[(x - a)² + (y_ - b)² + (z_ - c)² ... ]
*/
double Point::Distance(vector<int> distance_to){ // arguments are the coordinates of point 2
    double dist = 0;  // creates variable to help calculate distance

    if (coord_.size() == distance_to.size()){ // if the points have the same dimensions the distance can be calculated
        for(unsigned int i = 0; i < coord_.size(); i ++){ // for every entry in the vector
                dist += pow(coord_[i] - distance_to[i], 2); // formula
        }
        return sqrt(dist);    // take the square root of the result and return the calculated distance
    }
    else {return 0;} // if the distance can't be calculated return 0
    
}

/**
 * Move the point's coordinates by whatever integer value is passed
 * @param move value to be added to the ponint
*/
void Point::Translate(int move){ 
    for (unsigned int i = 0; i < coord_.size(); i++){ // for every entry in the vector
        coord_[i] += move; // move that coordinate by "move"
    }
}
