#ifndef MISFORTUNES_H
#define MISFORNUTES_H
#include <iostream>
using namespace std;

class Misfortunes
{
    public:
        int randomChance();
        bool sick();
        bool oxenmis();
        bool RaiderAttackChance;
        void RaiderAttackChoice(bool);
        

    private:
        int misfortuneNumber;
        bool RaiderAttack;
        
    
};

#endif