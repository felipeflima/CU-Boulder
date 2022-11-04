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
#include "TextUI.h"


/**
 * Test program by creating 4 Districts and adding them to the ElectoralMap.
 * Prints out the ElectoralMap with District name, area and id
 * Also tests get_district(id) individually
*/ 
int main(){
    srand (time(NULL));
    ElectoralMap& electoral = ElectoralMap::GetInstance(); //one electoral map for the totality of the program
    for (int i = 0; i < Election::NUM_DISTRICTS; i++){
        District *temp = new District();
        electoral.InsertDistrict(*temp);
        delete temp;
    }


    TextUI *ui = new TextUI(); //one Text UI
    ui->END = 0;
    while (ui->END == 0){ // a different election for everytime the program runs
        Election *election = new Election();
        RepresentativeElection * rep = new RepresentativeElection();
        ui->ElectionType(*election, electoral, *rep);
    }
}