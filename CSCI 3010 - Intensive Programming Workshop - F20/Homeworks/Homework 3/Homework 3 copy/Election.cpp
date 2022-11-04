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
#include "Election.h"

/**
 * Function register new candidates 
 * @param candidates name, party and id
*/ 
void Election::RegisterCandidates(std::string candidate_name, int party_num, int candidate_id){
    cmap_size_++;
    Candidate *temp = new Candidate();
    temp->name = candidate_name;
    temp->id = candidate_id;
    switch (party_num) //add paryty affiliation depending on param
    {
    case 1:
        temp->party_affiliation = Party::One;
        break;
    case 2:
        temp->party_affiliation = Party::Two;
        break;
    case 3:
        temp->party_affiliation = Party::Three;
        break;
    // case 4:
    //     temp->party_affiliation = Party::Four;
    default:
        std::cout << party_num << "Failed to add candidate to party" << std::endl;
        break;
    }
    candidates_.insert(std::pair<int, Candidate>(cmap_size_, *temp)); //inserts into candidates map
    delete temp;
}

/**
 * Function calculates the party with most constituents
 * @param a party that will be expluded from the equation
*/ 
Party Election::GetPartyMostConstituentsVote(Party p){
    Party most_p;
    int most = 0;
    for(it_most = votes_.begin(); it_most != votes_.end(); it_most++){
        if (it_most->second > most && it_most->first != p && it_most->first != Party::None){
            most_p = it_most->first;
            most = it_most->second;
        }
    }
    return most_p;
}


/**
 * Function calculates and reareges constituents based on the write up
 * @param a district
*/ 
void Election::Voting(District d){
    bool candidate_in_party = 0;
    votes_ = d.get_constituents();
    for (it_v = votes_.begin(); it_v != votes_.end(); it_v++){ // for all the parties in the district
        candidate_in_party = 0;
        if (it_v->first == Party::None){
            votes_[GetPartyMostConstituentsVote(Party::None)] += votes_[Party::None]; //move const from party none to majority
            votes_[Party::None] = 0;
        }
        else{
            for (it_c = candidates_.begin(); it_c != candidates_.end(); it_c++){ //checks for a candidate in the party
                if (it_v->first == it_c->second.party_affiliation){
                    candidate_in_party = 1;
                }
            }
            if (candidate_in_party == 0){
                votes_[GetPartyMostConstituentsVote(it_v->first)] += votes_[it_v->first]; ////move const from party with no candidate to majority
                votes_[it_v->first] = 0;
            }
        }
    }
    for (it_v = votes_.begin(); it_v != votes_.end(); it_v++){ //adds the votes from the party to candidates on the party
        for (it_c = candidates_.begin(); it_c != candidates_.end(); it_c++){
            if (it_v->first == it_c->second.party_affiliation){
                it_c->second.votes += it_v->second;
            }
        }
    }
}

/**
 * Function calculates the winner of the direct election
*/ 
void Election::CalculateWinner(){
    int random = (rand() % 2 + 1);
    Candidate cand;
    int most_votes = 0;
    std::cout << "============================= RESULTS =============================" << std::endl;
    for (it_c = candidates_.begin(); it_c != candidates_.end(); it_c++){ //for all the candidates
        for (it_cmost = candidates_.begin(); it_cmost != candidates_.end(); it_cmost++){ //compare to check if there are two or more candidates from the same party and resolve conflicts
            if (it_c->second.party_affiliation == it_cmost->second.party_affiliation && it_cmost->second.id != it_c->second.id && it_cmost->second.print == 1 && it_c->second.print == 1){
                random = (rand() % 2 + 1);
                if (random == 1){
                    it_cmost->second.print = 0;
                }
                else{
                    it_c->second.print = 0;
                } 
            }
        }
        if (it_c->second.print == 1){
            std::cout << it_c->second.name << " had " << it_c->second.votes << " votes across the districts!" << std::endl;
        }
        if (it_c->second.votes > most_votes){
            cand = it_c->second;
            most_votes = it_c->second.votes;
        }
    }

    std::cout << "Winner: ";
    std::cout << cand.name << " from " << PartyString(cand.party_affiliation) << " with " << cand.votes << " total votes!" << std::endl;


}

/**
 * Function calculates the candidate who won on a specific distric
 * @param a district
 * @return the winner candidate
*/ 
Candidate Election::WinnerInDistrict(District d){
    int random;
    Candidate winner;
    int most = 0;
    bool candidate_in_party = 0;
    votes_ = d.get_constituents();
    for (it_v = votes_.begin(); it_v != votes_.end(); it_v++){
        candidate_in_party = 0;
        if (it_v->first == Party::None){
            votes_[GetPartyMostConstituentsVote(Party::None)] += votes_[Party::None];
            votes_[Party::None] = 0;
        }
        else{
            for (it_c = candidates_.begin(); it_c != candidates_.end(); it_c++){
                if (it_v->first == it_c->second.party_affiliation){
                    candidate_in_party = 1;
                }
            }
            if (candidate_in_party == 0){
                votes_[GetPartyMostConstituentsVote(it_v->first)] += votes_[it_v->first];
                votes_[it_v->first] = 0;
            }
        }
    }
    for (it_v = votes_.begin(); it_v != votes_.end(); it_v++){
        for (it_c = candidates_.begin(); it_c != candidates_.end(); it_c++){
            if (it_v->first == it_c->second.party_affiliation && it_v->second > most){
                if (it_c->second.votes == winner.votes && it_cmost->second.id != it_c->second.id && it_cmost->second.print == 1 && it_c->second.print == 1){
                random = (rand() % 2 + 1);
                    if (random == 1){
                        it_cmost->second.print = 0;
                    }
                    else{
                        it_c->second.print = 0;
                    } 
                }
                if (it_c->second.print == 1){
                    winner = it_c->second;
                    winner.votes = d.GetVotesDistrict();
                    most = it_v->second;
                }
            }
        }
    }
    return winner;
}