#include <iostream>
// #include <string>
// #include <fstream>
// #include <sstream>
// #include <iomanip>
using namespace std;

class Book
{
    public:
        Book();
        Book(string, float);
        string getTitle();
        void setTitle(string);
        float getSales();
        void setSales(float);
        float sold(float);
    
    private:
        string title;
        float sales;
        float units;
    
};


Book::Book()
{
    title = "";
    sales = 0.0;
}

Book::Book(string s, float f)
{
    title = s;
    sales = f;
}

string Book::getTitle()
{
    return title;
}

void Book::setTitle(string s)
{
    title = s;
}

float Book::getSales()
{
    return sales;
}

void Book::setSales(float f)
{
    sales = f;
}

float Book::sold(float unit)
{
    float avg = 1000;
    //avg = sales/units;
    return avg;
}