#include <iostream>
using namespace std;

void LeavesPerTree(double p)
{
    double l = (p/1031) / 0.001;
    cout << l << endl;
    if (l > 10000)
    {
        cout << "More leaves than last year";
    }
}

int main ()
{
    LeavesPerTree(10000);
}