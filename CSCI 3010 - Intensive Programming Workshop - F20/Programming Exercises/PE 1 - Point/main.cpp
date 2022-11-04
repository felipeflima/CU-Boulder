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
#include "Point.h"
using namespace std;

int main(){
    Point *p1 = new Point(); // creates a point at the origin
    Point *p2 = new Point(3,5); // creates a point at (3,5)
    Point *p3 = new Point(-2,7); // creates a point at (-2,7)
    
    int p1_x = p1->GetXCord(); // get and store the x coordinate of p1
    int p1_y = p1->GetYCord(); // get and store the y coordinate of p1
    int p2_x = p2->GetXCord(); // get and store the x coordinate of p2
    int p2_y = p2->GetYCord(); // get and store the y coordinate of p2
    int p3_x = p3->GetXCord(); // get and store the x coordinate of p3
    int p3_y = p3->GetYCord(); // get and store the y coordinate of p3

    double dist1_2 = p1->Distance(p2_x, p2_y); // calculates and stores the distance between points 1 and 2
    double dist1_3 = p1->Distance(p3_x, p3_y); // calculates and stores the distance between points 1 and 3
    double dist2_3 = p2->Distance(p3_x, p3_y); // calculates and stores the distance between points 2 and 3

    cout << "p1 coordinates: (" << p1_x << "," << p1_y << ")" <<endl; // prints out coordinates of p1
    cout << "p2 coordinates: (" << p2_x << "," << p2_y << ")" << endl; // prints out coordinates of p2
    cout << "p3 coordinates: (" << p3_x << "," << p3_y << ")" << endl; // prints out coordinates of p3

    cout << "---------------------" << endl;

    cout << "Distance between p1 and p2: " << dist1_2 << endl; // prints out the distance between points 1 and 2
    cout << "Distance between p1 and p3: " << dist1_3 << endl; // prints out the distance between points 1 and 3
    cout << "Distance between p2 and p3: " << dist2_3 << endl; // prints out the distance between points 2 and 3

    cout << "---------------------" << endl;

    cout << "Tranlating p1 by (5, 9). Current coordinate: (" << p1_x << "," << p1_y << ")" << endl; // explain and prints old coordinates
    p1->Translate(5, 9); // translates p1 by (5,9)
    p1_x = p1->GetXCord(); // get and store the x coordinate of p1
    p1_y = p1->GetYCord(); // get and store the y coordinate of p1
    cout << "New coordinate: (" << p1_x << "," << p1_y << ")" << endl; // prints out the new coordinates

    dist1_2 = p1->Distance(p2_x, p2_y); // calculates distance between new point 1 and point 2
    dist1_3 = p1->Distance(p3_x, p3_y); // calculates distance between new point 1 and point 3

    cout << "New distance between p1 and p2: " << dist1_2 << endl; // prints out the new distance between points 1 and 2
    cout << "New distance between p1 and p3: " << dist1_3 << endl; // prints out the new distance between points 1 and 3

    cout << "---------------------" << endl;

    cout << "Tranlating p1 by (-3, -2). Current coordinate: (" << p1_x << "," << p1_y << ")" << endl; // explain and prints old coordinates
    p1->Translate(-3, -2); // translates p1 by (-3,-2)
    p1_x = p1->GetXCord(); // get and store the x coordinate of p1
    p1_y = p1->GetYCord(); // get and store the y coordinate of p1
    cout << "New coordinate: (" << p1_x << "," << p1_y << ")" << endl; // prints out the new coordinates

    dist1_2 = p1->Distance(p2_x, p2_y); // calculates distance between new point 1 and point 2
    dist1_3 = p1->Distance(p3_x, p3_y); // calculates distance between new point 1 and point 3

    cout << "New distance between p1 and p2: " << dist1_2 << endl; // prints out the new distance between points 1 and 2
    cout << "New distance between p1 and p3: " << dist1_3 << endl; // prints out the new distance between points 1 and 3

    return 0;
}