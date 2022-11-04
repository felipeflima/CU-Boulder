#ifndef TURNS_H
#define TURNS_H
#include <iostream>
#include "Status.h"
#include "Store.h"
#include "Misfortunes.h"
using namespace std;

class Turns
{
    public:
        bool readInfo(string filename);
        void statusUpdate();
        int choice();
        void rest();
        void continueTrail();
        void hunt();
        void quit();
        bool puzzle();
    
    private:
        int day;
        int month;
        int year;
        double miles;
        double foodT;
        double bulletsT;
        double moneyT;
};

#endif
