#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Status.h"
#include "Store.h"
#include "Turn.h"
#include "Misfortunes.h"
using namespace std;

Status::Status()
{
    yokesS = 0;
    foodS = 0;
    bulletsS = 0;
    wheelsS = 0;
    axlesS = 0;
    tonguesS = 0;
    distanceS = 0;
    healthS = 0;
    moneyS = 0;
}

int Status::getYokesValue()
{
    return yokes;
}
void Status::setYokesValue()
{
    yokesS = store.getYokes();
}

int Status::getFoodValue();
{
    return food;
}

void Status::setFoodValue();
{
    foodS = store.getFood();
}

int Status::getBulletsValue();
{
    return bullets;
}

void Status::setBulletsValue();
{
    bulletsS = store.getBullets();
}

int Status::getAxlesValue();
{
    return axles;
}

void Status::setAxlesValue();
{
    axlesS = store.getAxles();
}

int Status::getTonguesValue();
{
    return tongues;
}

void Status::setTonguesValue();
{
    tonguesS = store.getTongues();
}

// all of the information from the Status class will be written into a file so the Turn class can read from that file and access that information