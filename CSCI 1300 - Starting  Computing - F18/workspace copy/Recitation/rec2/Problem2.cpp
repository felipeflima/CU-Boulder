#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cout << "Enter a radius: " << endl; // dispaly "Enter a radius:"
    float radius; // set the variable radius
    cin >> radius; // allows the user to inoput a value for the radius
    float sphereVolume; // set the variable sphereVolume
    sphereVolume = (4.0/3.0) * M_PI * pow(radius, 3); // assigns a value to sphereVolume using the formula (4/3)π^3
    cout << "volume: " << sphereVolume << endl; // displays the volume based on the sphereVolume variable
    
    
}
