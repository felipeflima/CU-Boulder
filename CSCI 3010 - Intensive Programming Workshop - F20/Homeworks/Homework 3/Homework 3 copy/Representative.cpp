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
#include <math.h>
#include <map>
#include <iomanip>
#include "Representative.h"


/**
 * Function calculates and prints the candidate winners for each district
 * @param a district , the elctoral map, and the current election
*/ 
void RepresentativeElection::CalculateVotes(District d, ElectoralMap &electoral, Election &election){
    double const_all_districts = electoral.TotalConstituents();
    int votes = floor( ((d.GetTotalConstituents()*1.0)/const_all_districts) *  total_votes_ ); //formula to calculate votes per district
    d.AddVotesToDistrict(votes);
    if (election.WinnerInDistrict(d).votes > winner_.votes){
        winner_ = election.WinnerInDistrict(d);
    }
    std::cout << d.GetDistrictName() << ": " << election.WinnerInDistrict(d).name <<  " with " << election.WinnerInDistrict(d).votes << " votes!" << std::endl;
}


/**
 * Function prints the election winner
 * @param the elctoral map, and the current election
*/ 
void RepresentativeElection::TotalWinner(ElectoralMap &electoral, Election &election){
    std::cout << "============================= RESULTS =============================" << std::endl;
    std::cout << "Winner: " << winner_.name << std::endl;
}