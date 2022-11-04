#ifndef STORE_H
#define STORE_H
#include <iostream>
using namespace std;

class Store
{
    public:
        Store();
        void storeInstructions();
        int choiceBuy();
        int buyOxen();
        int buyFood();
        int buyBullets();
        int buyMiscellaneous();
        int getYokes();
        int getFood();
        int getBullets();
        int getWheels();
        int getAxles();
        int getTongues();
    
    private:
        int money;
        double bill;
        int yokes;
        int food;
        int bullets;
        int wheels;
        int axles;
        int tongues;
        int storeVisit;
        
        
        
        
};

#endif