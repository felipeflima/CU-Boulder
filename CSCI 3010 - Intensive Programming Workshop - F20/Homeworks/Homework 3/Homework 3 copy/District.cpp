/* CSCI 3010 - IPW
* Felipe Lima
* Homework 3
* 10/13/2020
* Election program simulator
* How to run: using Makefile
~make
~./election
*/

#include <iostream>
#include "District.h"
#include "ElectoralMap.h"
// #include "TextUI.h"

std::string PartyString(Party pt){
    std::string none = "[Party:: None]";
    std::string one = "[Party:: One]";
    std::string two = "[Party:: Two]";
    std::string three = "[Party:: Three]";

    switch(pt){
        case Party::None: return none; break;
        case Party::One: return one; break;
        case Party::Two: return two; break;
        case Party::Three: return three; break;
    }
}

District::District(){
    ElectoralMap& elect = ElectoralMap::GetInstance();
    district_name_ = "District " + std::to_string(elect.GetDMapSize()+1);
    district_id = elect.GetDMapSize()+1;
    area_ = AreaGenerator();

    constituents_.insert(std::pair<Party, int>(Party::None, ConstituentsGenerator()));
    constituents_.insert(std::pair<Party, int>(Party::One, ConstituentsGenerator()));
    constituents_.insert(std::pair<Party, int>(Party::Two, ConstituentsGenerator()));
    constituents_.insert(std::pair<Party, int>(Party::Three, ConstituentsGenerator()));
}

/**
 * Function generates area for district
*/ 
int District::AreaGenerator(){
    int random = (rand() % 25 + 5);
    return random;
}

/**
 * Function generates const for district
*/ 
int District::ConstituentsGenerator(){
    int random = (rand() % 10);
    return random;
}

/**
 * Function gets total const for district
*/ 
int District::GetTotalConstituents(){
    int total = 0;
    for (it_co = constituents_.begin(); it_co != constituents_.end(); it_co++){
        total += it_co->second;
    }
    return total;
}

/**
 * Function gets party with most const for district
*/ 
Party District::GetPartyMostConstituents(Party p){
    Party p_most;
    int most = 0;
    for (it_co = constituents_.begin(); it_co != constituents_.end(); it_co++){
        if (it_co->second > most && it_co->first != p && it_co->first != Party::None){
            most = it_co->second;
            p_most = it_co->first;
        }
    }
    return p_most;
}