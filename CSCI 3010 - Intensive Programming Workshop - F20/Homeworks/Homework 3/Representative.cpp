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
    // int most = 0;
    bool same = 0;
    Candidate winner_district;
    double const_all_districts = electoral.TotalConstituents();
    int votes = floor( ((d.GetTotalConstituents()*1.0)/const_all_districts) *  total_votes_ ); //formula to calculate votes per district
    d.AddVotesToDistrict(votes);
    winner_district = election.WinnerInDistrict(d);
    // std::cout << "winner: " << winner_district.name << " - winner votes " << winner_district.votes << std::endl;
    if (first_ == 1){
        winners_.insert(std::pair<int, int>(winner_district.id, winner_district.votes)); //in case the map is empty insert the first element
        first_ = 0;
    }
    else{
        for(it_w_ = winners_.begin(); it_w_ != winners_.end(); it_w_++){
            if (it_w_->first == winner_district.id){ // if a candidate is already in the map only add the votes
                it_w_->second += winner_district.votes;
                same  = 1;
            }
        }
        if (same == 0){ //if the candidate isn't on the map insert it
            winners_.insert(std::pair<int, int>(winner_district.id, winner_district.votes));
        }
    }
    winner_ = election.GetCandidate(winners_.begin()->first); //winner is the first candidate on the map
    winner_.votes = winners_.begin()->second; // assign votes
    for(it_w_ = winners_.begin(); it_w_ != winners_.end(); it_w_++){
        std::cout << election.GetCandidate(it_w_->first).name << " : " << it_w_->second << std::endl;
        if(it_w_->second > winner_.votes){
            winner_ = election.GetCandidate(it_w_->first); //makes winner the one with more electoral votes
            winner_.votes = it_w_->second;
        }
    }
    std::cout << std::endl;
}


/**
 * Function prints the election winner
 * @param the elctoral map, and the current election
*/ 
void RepresentativeElection::TotalWinner(ElectoralMap &electoral, Election &election){
    std::cout << "============================= RESULTS =============================" << std::endl;
    std::cout << "Winner: " << winner_.name << " with " << winner_.votes << std::endl;
}