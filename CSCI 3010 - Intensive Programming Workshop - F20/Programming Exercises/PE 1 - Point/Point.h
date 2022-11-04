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

#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;

class Point {
    public:
        Point(); // constructor, no args
        Point(int x_val, int y_val);  // constructor, two args

        int GetXCord();
        int GetYCord();
        void SetXCord(int x_point);
        void SetYCord(int y_point);

        double Distance(int x2, int y2);
        void Translate (int x_move, int y_move);

    private:
        int x_, y_;
};

#endif