#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Misfortunes.h"
using namespace std;

Misfortunes::Misfortunes
{
    misfortuneNumber = 0;
}

int Misfortunes::randomChance()
{
    //determines whether or not a misfortune is going to occur at the end of a turn and which one it is going to be
    // determines whether characters die after a misfortune
    // return a number representing the misfortune, then whether a chatracter dies or not
}

bool sick()
{
    //Print a message announcing the misfortune
    //calls th random chance generator to evaluate whether or not a charater die dependeing on the users choices
    // return 1 if a character died and 0 if no one died
}

bool oxenmis()
{
    //Print a message announcing the misfortune
    //If the player has spare wagon parts, one will be used to fix the wagon. The number of spare Parts goes down by 1.
    //● If the player does not have spare wagon parts, the travelling party will become unable to continue their journey
    // return 1 if a character died and 0 if no one died
}

bool Misfortunes::RaiderAttackChance()
{
    //calculates the chnace fo a raider attack based on the postion of the family on the trail
    //return 1 if attack is happening and 0 if it is not happening
}

void Misfortunes::RaiderAttackChoice(bool RaiderAttack)
{
    //lets the player choose between running fightring or surredering
}