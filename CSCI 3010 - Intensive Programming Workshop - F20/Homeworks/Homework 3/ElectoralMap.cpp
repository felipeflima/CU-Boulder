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
#include <map>
#include <iomanip>
#include "ElectoralMap.h"
#include "Election.h"


ElectoralMap::ElectoralMap(){
    dmap_size_ = 0;
}

/**
 * Function inserts district into map
 * @param a district
*/ 
void ElectoralMap::InsertDistrict(District &d){
    dmap_size_++;
    districts_.insert(std::pair<int, District>(dmap_size_, d));
}

/**
 * Function handles campainging
 * @param the current election, a candidate and a district
*/ 
void ElectoralMap::Campaign(int cand_id, int dist_id, Election &election){
    bool converted = 0;
    Candidate cand = election.GetCandidate(cand_id);
    int P_success_rand = (rand() % 100 + 1);
    std::cout << cand.name << " is campaigning in district " << districts_[dist_id].GetDistrictName() << std::endl;
    double const_none_party = districts_[dist_id].get_constituents()[Party::None]; // const for p none
    double const_cand_party = districts_[dist_id].get_constituents()[cand.party_affiliation]; // const for cand party
    double const_other_party = districts_[dist_id].GetTotalConstituents() - const_none_party - const_cand_party; // const for other parties
    Party most_const = districts_[dist_id].GetPartyMostConstituents(cand.party_affiliation); //party with the most const
    double dist_area = districts_[dist_id].get_area(); 
    double P_success = (((const_cand_party+1)*2) / const_other_party) * (((const_cand_party+1)*2) / dist_area); // formula to calculate p_success as per the write up
    if (P_success >= 1){
        P_success = 100.0;
    }
    else{
        P_success *= 100.0;
    }
    double P_extra = P_success * 0.1;
    std::cout << "Chances to convert: " << std::setprecision(6) << std::fixed << P_success << std::endl;
    std::cout << "Chances to convert from another party: " << std::setprecision(6) << std::fixed << P_extra << std::endl;
    if (P_success_rand <= P_success){ // if the number generated is less then the p_success
        if (districts_[dist_id].get_constituents()[Party::None] > 0){ // if party none has constituents convert from none to candidate's party
            districts_[dist_id].DecreaseConst(Party::None);
            districts_[dist_id].IncreaseConst(cand.party_affiliation);
            std::cout << "Congrats, you have converted someone from [Party:: None] to " << PartyString(cand.party_affiliation) << std::endl;
            converted = 1;
        }
        if (P_success_rand <= P_extra && districts_[dist_id].get_constituents()[most_const] > 0){ //to convert from majosrity to candidate's party
            districts_[dist_id].DecreaseConst(most_const);
            districts_[dist_id].IncreaseConst(cand.party_affiliation);
            std::cout << "Congrats, you have converted someone from " << PartyString(most_const) << " to " << PartyString(cand.party_affiliation) << std::endl;
            converted = 1;
        }
    }
    if (converted == 0){
        std::cout << "Sorry, no one converted" << std::endl;
    }
    std::cout << GetInstance() << std::endl;
}

/**
 * Function calculates the total constituents
*/ 
int ElectoralMap::TotalConstituents(){
    int total = 0;
    for (it_d = districts_.begin(); it_d != districts_.end(); it_d++){
        total += it_d->second.GetTotalConstituents();
    }
    return total;
}