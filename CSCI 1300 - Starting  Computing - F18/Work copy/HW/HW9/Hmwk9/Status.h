#ifndef STATUS_H
#define STATUSE_H
#include <iostream>
#include "Store.h"
#include "Turn.h"
#include "Misfortunes.h"
using namespace std;

class Status
{
    public:
        int getYokesValue();
        void setYokesValue();
        int getFoodValue();
        void setFoodValue();
        int getBulletsValue();
        void setBulletsValue();
        int getAxlesValue();
        void setAxlesValue();
        int getTonguesValue();
        void setTonguesValue();
        
        

    private:
        Store store;
        Turn turn;
        Misfortune misfortune;
        int yokesS;
        int foodS;
        int bulletsS;
        int wheelsS;
        int axlesS;
        int tonguesS;
        double distanceS;
        double healthS;
        double moneyS;
    
    
};

#endif

// characters
// money
// health
// distance
// yokes
// bullets
// food

// all of the information from the Status class will be written into a file so the Turn class can read from that file and access that information