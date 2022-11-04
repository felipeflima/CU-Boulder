/* CSCI 3010 - IPW
* Felipe Lima
* Programming Exercise 5 - unit testing
* 09/29/2020
* What it does: Creates a rectangle in a 2D plan and execute funcitons in it
* How to run: 
~ g++ -std=c++17 Rectangle.cpp -o rec
~ ./rec
*/
#include <iostream>
#include "Rectangle.h"

/**
 * Rectangle contrusctor. creates a new rectangle
 * @param two points in a 2d plan
 * @bug Rectangle did not check for the order of the positions and did not rearrenge
*/
Rectangle::Rectangle(Point p1, Point p2){
    if (p1.x > p2.x && p1.y > p2.y){ //if p1 and p2 have inverted roles, i.e. p1 is the upper right corner, invert them
        Point temp;
        temp = p1;
        p1 = p2;
        p2 = temp;
    }
    if (p1.x > p2.x && p1.y <= p2.y){ // reposition p1 and p2 if p1 is the bottom right corner.
        int temp;
        temp = p1.x;
        p1.x = p2.x;
        p2.x = temp;
    }
    if (p1.x <= p2.x && p1.y > p2.y){ // reposition p1 and p2 if p1 is the upper left corner
        int temp;
        temp = p1.y;
        p1.y = p2.y;
        p2.y = temp;
    }
    p1_ = p1;
    p2_ = p2;
}

/**
 * Returns the width of the rectangle by calculating the distance between the x coordinates
 * @bug because the order of the points was not corrected, when the points are passed in the worng order, it returned a wrong value
*/
int Rectangle::GetWidth(){
    return (p2_.x - p1_.x);
}

/**
 * Returns the height of the rectangle by calculating the distance between the y coordinates
 * @bug because the order of the points was not corrected, when the points are passed in the worng order, it returned a wrong value
*/
int Rectangle::GetHeight(){
    return (p2_.y - p1_.y);
}

/**
 * Check if any of the points in two recgtangles overlap
 * @param the rectangle to compare to
 * @bug function didn't check if the points passed to the rectangle overlap
 *      the same rectangle returned false
 *      random point in the rectangle preimeter overlaping returned false
*/
bool Rectangle::Overlaps(Rectangle& other){
    if (p1_.x > other.p2_.x || other.p1_.x > p2_.x){ // If one rectangle is on left side of other 
        return false;
    } 
    if (p1_.y > other.p2_.y || other.p1_.y > p2_.y){ // If one rectangle is above other
        return false;
    } 
    return true; 
}

/**
 *  Calculates area of the rectangle
*/
int Rectangle::CalculateArea(){
    return GetHeight() * GetWidth();
}

/**
 * Expand the rectangle by one point in each direction
 * @bug because the order of the points was not corrected, when the points are passed in the worng order, it returned a wrong value
*/
void Rectangle::Expand(){
    p1_.x--;
    p1_.y--;
    p2_.x++;
    p2_.y++;
}

/**
 * Shrinks the rectangle by one point in each direction
 * @bug because the order of the points was not corrected, when the points are passed in the worng order, it returned a wrong value
*/
void Rectangle::Shrink(){
    if (p1_.x != p2_.x && p1_.y != p2_.y){
        p1_.x++;
        p1_.y++;
        p2_.x--;
        p2_.y--;
    }
}

// int main(){
//     Point p1 = {2,5};
//     Point p2 = {5,10};
//     Rectangle r1(p1,p2);
//     p1 = r1.get_p1();
//     p2 = r1.get_p2();
//     std::cout << "p1: (" << p1.x << "," << p1.y << ")" << std::endl;
//     std::cout << "p2: (" << p2.x << "," << p2.y << ")" << std::endl;
//     // std::cout << r1.CalculateArea() << std::endl;
//     // r1.Expand();
//     // p1 = r1.get_p1();
//     // p2 = r1.get_p2();
//     // std::cout << "p1: (" << p1.x << "," << p1.y << ")" << std::endl;
//     // std::cout << "p2: (" << p2.x << "," << p2.y << ")" << std::endl;
//     // r1.Shrink();
//     // p1 = r1.get_p1();
//     // p2 = r1.get_p2();
//     // std::cout << "p1: (" << p1.x << "," << p1.y << ")" << std::endl;
//     // std::cout << "p2: (" << p2.x << "," << p2.y << ")" << std::endl;
//     Point p3 = {1,4};
//     Point p4 = {3,7};
//     Rectangle r3(p3,p4);
//     std::cout << r3.GetHeight() << std::endl;


//     std::cout << "-------------" << std::endl;
//     std::cout << r1.Overlaps(r3) << std::endl;


// }