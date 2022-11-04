#ifndef CHILDGROWTH_H
#define CHILDGROTH_H
#include <iostream>
using namespace std;

class ChildGrowth
{
    public:
        ChildGrowth();
        ChildGrowth(string);
        ChildGrowth(string, int);
        ChildGrowth(string, int, float[10], float[10]);
        string getName();
        void setName(string);
        int getCurrentAge();
        void setCurrentAge (int);
        void setHeight (float[10]);
        void setWeight (float[10]);
        float feetToMeter(float);
        float poundToKg(float);
        float calculateBmi (int);
        string getCategory (int);
        
    private:
        string name;
        int currentAge;
        float weightMetricConversion;
        float weight[10];
        float height[10];
        
        
};

#endif