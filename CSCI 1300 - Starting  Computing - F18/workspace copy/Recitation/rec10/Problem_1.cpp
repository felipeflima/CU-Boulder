#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

void modifyVector(vector<int>& v)
{
    int input = 1; // creates the variable that is going to store the value of the user input 
    while (input > 0) 
    {
        cout << "Please enter an integer value:" << endl;
        cin >> input;
        if (v.size() == 0 && input > 0)
        {
            v.push_back(input);
        }
        else if (input % 5 == 0 && input > 0)
        {
            v.erase(v.begin());
        }
        else if (input % 3 == 0 && input > 0)
        {
            v.pop_back();
        }
        else if (input > 0)
        {
            v.push_back(input);
        }
    }
    return;
}

int main()
{
    vector<int> v;
    modifyVector(v);
    cout << "size: "<<v.size()<<endl;
    for (int i = 0; i< (int)v.size(); i++)
    {
        cout <<"value at position "<<i<< " in the vector: " <<v[i] << endl;
    }   
    
}