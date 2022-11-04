#include <iostream>
using namespace std;

double PaintHouse (int width, int depth, int dw)
{
    double p = (2 * (width + depth));
    double pdw = dw * 6.75;
    if (width < 0 || depth < 0 || dw < 0)
    {
        return -1;
    }
    else if (p >= 0 && p <= 100)
    {
        double t = ((p * 8) + pdw);
        return t;
    }
    else if  (p > 100 && p <= 200)
    {
        double t2 = ((100 * 8) + ((p - 100) * 10) + pdw);
        return t2;
    }
    else if (p > 200)
    {
        double t3 = ((100 * 8) + (100 * 10) + ((p - 200) * 15) + pdw);
        return t3;
    }
}

int main ()
{
    cout << PaintHouse(-15,25,8) << endl;
}