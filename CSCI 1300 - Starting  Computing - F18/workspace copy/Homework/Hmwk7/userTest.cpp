#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "User.h"
using namespace std;

int main()
{
    User u;
    int a[10] = {1,2,3,4,5, 5, -1, -1, -1, -1};
    for (int i = 0; i < 10; i++)
    {
        cout << "setting ratings " << u.setRatingAt(i, a[i]) << endl;
    }
    cout << "getting ratings " << u.getRatingAt(10);

}