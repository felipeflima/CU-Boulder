#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cout << "Enter a radius: " << endl; // dispaly "Enter a radius:"
    float radius; // set the variable radius
    cin >> radius; //allows the user to inoput a value for the radius
    float sphereSurfaceArea; // set the variable sphereSurfaceArea
    sphereSurfaceArea = (4.0) * M_PI * pow(radius, 2); // assigns a value to sphereSurfaceArea using the formula 4π^2
    cout << "surface area: " << sphereSurfaceArea << endl; // displays the volume based on the sphereSurfaceArea variable
    
    
}
