// Author: Felipe Lima
// Recitation: 123 – Your TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/…
// Homework 2 - Problem # ...

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cout << "Enter a radius: " << endl;
    float radius;
    cin >> radius;
    float volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "volume: " << volume << endl;
    
    float surface_area; //set the variable surface_area
    surface_area = (4 * M_PI * pow(radius, 2)); // assigns a value to surface_area using the formula 4π^2
    cout << "surface area: " << surface_area << endl; // displays the result for surafce area based on the surface_area variable
    
}
