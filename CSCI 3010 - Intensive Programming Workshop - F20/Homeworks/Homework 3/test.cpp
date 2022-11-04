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
#include "ElectoralMap.h"
#include "District.h"


/**
 * Test program by creating 4 Districts and adding them to the ElectoralMap.
 * Prints out the ElectoralMap with District name, area and id
 * Also tests get_district(id) individually
*/ 
int main(){
    srand (time(NULL));
    ElectoralMap& e1 = ElectoralMap::GetInstance();
    for (int i = 0; i < ElectoralMap::NUM_DISTRICTS; i++){
        District *temp = new District;
        e1.InsertDistrict(*temp);
        delete temp;
       
    }
    std::cout << ElectoralMap::GetInstance() << std::endl;
    std::cout << "------------" << std::endl << std::endl;
    // std::cout << e1.get_district(3) << std::endl;
}


// #include <iostream>
// #include "ElectoralMap.h"
// #include "District.h"

// int main(){
//     // ElectoralMap& e1 = ElectoralMap::GetInstance();
//     // srand (time(NULL));
//     // for (int i = 0; i < ElectoralMap::NUM_DISTRICTS; i++){
//     //     District *temp = new District;
//     //     e1.InsertDistrict(*temp);
       
//     // }
//     // // District d1;
//     // // std::cout << d1.AreaGenerator() << std::endl;
//     // // std::cout << d1.AreaGenerator() << std::endl;


//     // // District d1;
//     // // ElectoralMap& e1 = ElectoralMap::GetInstance();
//     // // std::cout << d1 << std::endl;
//     // // e1.InsertDistrict(d1);
//     // // std::cout << "------------" << std::endl;
//     // std::cout << e1 << std::endl;
//     // std::cout << "------------" << std::endl;
//     // std::cout << e1.get_district(2) << std::endl;
//     // // std::cout << ElectoralMap::NUM_DISTRICTS << std::endl;


    

// }