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

#ifndef POINT_H
#define POINT_H
#include <iostream>
#include<vector>
using namespace std;

class Point {
    public:
        Point(int num_dimensions); // constructor, one args
        Point(vector<int> temp_coord);  // constructor, two args

        int PointDimensions(); // returns the dimensions of a point

        vector<int> GetCords(); // getter function
        int GetNCord(int n); // getter function that returns one coordinate of the n dimension
        void SetCords(vector<int> new_coord); // setter function

        double Distance(vector<int> distance_to); // returns the distance between two points
        void Translate (int move); // translates a point

    private:
        vector<int> coord_; // private vector with coordinates
};

#endif
