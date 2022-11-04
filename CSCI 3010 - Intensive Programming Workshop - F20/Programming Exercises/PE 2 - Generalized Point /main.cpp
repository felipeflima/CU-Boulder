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
#include<vector>
#include "Point.h"
using namespace std;

int main(){
    Point *p1 = new Point(4); // creates a point at the origin
    vector<int> point2 { 1, 2, 3, 4 }; // creates and initialize vector with coordinates for point2
    Point *p2 = new Point(point2); // creates a new point the "point2" coordiantes
    vector<int> point3 { 44, 57, 29, 425, 393 }; // creates and initialize vector with coordinates for point3
    Point *p3 = new Point(point3); // creates a new point the "point3" coordiantes

    vector<int> p1_coords = p1->GetCords(); // get and store the coordinates of p1
    vector<int> p2_coords = p2->GetCords(); // get and store the coordinates of p2
    vector<int> p3_coords = p3->GetCords(); // get and store the coordinates of p3

    // prints out dimension and coordinates of p1     
    cout << "p1 has " << p1->PointDimensions() << " dimensions and " << "p1 coordinates are: (";
    for (unsigned int i = 0; i < p1_coords.size()-1; i ++){
        cout << p1_coords[i] << ",";
    }
    cout << p1_coords[p1_coords.size()-1] << ")" <<endl;

    // prints out dimension and coordinates of p2
    cout << "p2 has " << p2->PointDimensions() << " dimensions and " << "p2 coordinates are: (";
    for (unsigned int i = 0; i < p2_coords.size()-1; i ++){
        cout << p2_coords[i] << ",";
    }
    cout << p2_coords[p2_coords.size()-1] << ")" <<endl;  

    // prints out dimension and coordinates of p3
    cout << "p3 has " << p3->PointDimensions() << " dimensions and " << "p3 coordinates are: (";
    for (unsigned int i = 0; i < p3_coords.size()-1; i ++){
        cout << p3_coords[i] << ",";
    }
    cout << p3_coords[p3_coords.size()-1] << ")" <<endl;  
    
    cout << "---------------------" << endl;


    //calculates distance between all the points and store them into variables
    double dist1_2 = p1->Distance(p2_coords);
    double dist1_3 = p1->Distance(p3_coords);
    double dist2_3 = p2->Distance(p3_coords);

    /**
     *  prints out the distance between points
     * if the points don't have the same dimensinos, display an error message
    */
    if (dist1_2 != 0){
        cout << "Distance between p1 and p2: " << dist1_2 << endl; 
    }
    else{cout << "Distance cannot be calculated because points have different dimensions" << endl;}

    if (dist1_3 != 0){
        cout << "Distance between p1 and p3: " << dist1_3 << endl; 
    }
    else{cout << "Distance between p1 and p3 cannot be calculated because points have different dimensions" << endl;}

    if (dist2_3 != 0){
        cout << "Distance between p2 and p3: " << dist2_3 << endl;
    }
    else{cout << "Distance between p2 and p3 cannot be calculated because points have different dimensions" << endl;}
    
    cout << "---------------------" << endl;

    
    /**
     * Translates point 15 and prints out new coordinates and distances
    */
    cout << "Tranlating p1 by (+15). Current coordinates: ("; 
    for (unsigned int i = 0; i < p1_coords.size()-1; i ++){ //prints coordinates
        cout << p1_coords[i] << ",";
    } 
    cout << p1_coords[p1_coords.size()-1] << ")" <<endl;
    p1->Translate(15); // translates p1 by (15)
    p1_coords = p1->GetCords(); // get and store the coordinates of p1
    cout << "New coordinates: ("; //prints new coordinates
    for (unsigned int i = 0; i < p1_coords.size()-1; i ++){
        cout << p1_coords[i] << ",";
    } 
    cout << p1_coords[p1_coords.size()-1] << ")" <<endl;
    dist1_2 = p1->Distance(p2_coords); // get and store the distance of p1 to p2
    dist1_3 = p1->Distance(p3_coords); // get and store the distance of p1 to p3
    if (dist1_2 != 0){ // if points match dimensions
        cout << "New distance between p1 and p2: " << dist1_2 << endl; // prints out the distance between points 1 and 2
    }
    else{cout << "New distance cannot be calculated because points have different dimensions" << endl;} // if points don't match dimensions
    if (dist1_3 != 0){ // if points match dimensions
        cout << "New distance between p1 and p3: " << dist1_3 << endl; // prints out the distance between points 1 and 3
    }
    else{cout << "New distance between p1 and p3 cannot be calculated because points have different dimensions" << endl;}

    cout << "---------------------" << endl;

    /**
     * Translates point -45 and prints out new coordinates and distances
    */
    cout << "Tranlating p1 by (-45). Current coordinates: ("; 
    for (unsigned int i = 0; i < p1_coords.size()-1; i ++){ //prints coordinates
        cout << p1_coords[i] << ",";
    } 
    cout << p1_coords[p1_coords.size()-1] << ")" <<endl;
    p1->Translate(-45); // translates p1 by (15)
    p1_coords = p1->GetCords(); // get and store the coordinates of p1
    cout << "New coordinates: ("; //prints new coordinates
    for (unsigned int i = 0; i < p1_coords.size()-1; i ++){
        cout << p1_coords[i] << ",";
    } 
    cout << p1_coords[p1_coords.size()-1] << ")" <<endl;
    dist1_2 = p1->Distance(p2_coords); // get and store the distance of p1 to p2
    dist1_3 = p1->Distance(p3_coords); // get and store the distance of p1 to p3
    if (dist1_2 != 0){ // if points match dimensions
        cout << "New distance between p1 and p2: " << dist1_2 << endl; // prints out the distance between points 1 and 2
    }
    else{cout << "New distance cannot be calculated because points have different dimensions" << endl;} // if points don't match dimensions
    if (dist1_3 != 0){ // if points match dimensions
        cout << "New distance between p1 and p3: " << dist1_3 << endl; // prints out the distance between points 1 and 3
    }
    else{cout << "New distance between p1 and p3 cannot be calculated because points have different dimensions" << endl;}

    return 0;
}
