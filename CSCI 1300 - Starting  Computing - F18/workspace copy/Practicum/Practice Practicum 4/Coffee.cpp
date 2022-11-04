// #include <iostream>
// #include <string>
// #include <fstream>
// #include <sstream>
// #include <iomanip>
// //#include "Coffee.h"
using namespace std;

class Coffee
{
    public:
        Coffee();
        Coffee(string, float);
        void setRoastType(string);
        string getRoastType();
        void setTemp(float);
        int getTemp();
        string drinkability();
        
    private:
        string roastType;
        float temp;
    
};

Coffee::Coffee()
{
    roastType = "";
    temp = 180.0;
}

// void Coffee::Roast(string roastType)
// {
    
// }

// void Coffee::Temp(float temp)
// {
    
// }

Coffee::Coffee(string s, float f)
{
    roastType = s;
    temp = f;
}

void Coffee::setRoastType(string s)
{
    roastType = s;
}

string Coffee::getRoastType()
{
    return roastType;
}

void Coffee::setTemp(float f)
{
    temp = f;
}

int Coffee::getTemp()
{
    return temp;
}

string Coffee::drinkability()
{
    if (temp < 100.0)
    {
        return "Too Cold";
    }
    else if (temp >= 100.0 && temp <160.0)
    {
        return "Just Right";
    }
    else if (temp >= 160.0 && temp < 180.0)
    {
        return "Hot";
    }
    else if (temp >= 180.0)
    {
        return "Too hot";
    }
}






























class Coffee{
    public:
        Coffee();
        Coffee(string, float);
        string getRoastType();
        void setRoastType(string);
        int getTemp();
        void setTemp(float);
        string drinkability();
    private:
        string roastType;
        float temp;
};

Coffee::Coffee()
{
    temp = 180.0;
    roastType = "";
}
Coffee::Coffee(string s, float f){
    roastType = s;
    temp = f;
}

string Coffee::drinkability()
{
            if (temp < 100.0)
                return "Too Cold";
            else if (temp >= 100.0 && temp < 160.0)
                return "Just Right";
            else if (temp >= 160.0 && temp <180.0)
                return "Hot";
            else return "Too Hot";
}
string Coffee::getRoastType()
{
    return roastType;
}
int Coffee::getTemp()
{
    return temp;
}
void Coffee::setTemp(float f)
{
    temp = f;
}
void Coffee::setRoastType(string s)
{
    roastType = s;
}