/* CSCI 3010 - IPW
* Felipe Lima
* Homework 3
* 10/13/2020
* Election program simulator
* How to run: using Makefile
~make
~./election
*/

#ifndef REPRESENTATIVE_H
#define REPRESENTATIVE_H

#include <iostream>
#include <map>
#include "ElectoralMap.h"
#include "Election.h"

class RepresentativeElection: public Election{
    public:
        RepresentativeElection():
        Election(){
            total_votes_ = 5 * Election::NUM_DISTRICTS;
            winner_.votes = 0;
            first_ = 1;
        }

        void CalculateVotes(District d, ElectoralMap &electoral, Election &election);
        int GetTotalVotes(){return total_votes_;}

        void TotalWinner(ElectoralMap &electoral, Election &election);



    private:
        int total_votes_;
        int first_;
        // std::map<District, int> votes_district_;
        // std::map<District, int> :: iterator it_votes;

        std::map<int, int> winners_;
        std::map<int, int> :: iterator it_w_;

        Candidate winner_;

};

#endif