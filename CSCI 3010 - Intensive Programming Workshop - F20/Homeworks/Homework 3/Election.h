/* CSCI 3010 - IPW
* Felipe Lima
* Homework 3
* 10/13/2020
* Election program simulator
* How to run: using Makefile
~make
~./election
*/
#ifndef ELECTION_H
#define ELECTION_H

#include <iostream>
#include <map>
#include "District.h"


struct Candidate{
    std::string name;
    Party party_affiliation;
    int id;
    int votes;
    bool print = 1;

    friend std::ostream& operator<<(std::ostream& os, Candidate &c){
        os << c.name << " " << PartyString(c.party_affiliation);
        return os;
	}
};

class Election{
    public:
        void RegisterCandidates(std::string candidate_name, int party_num, int candidate_id);
        int GetCMapSize() {return cmap_size_;}

        Party GetPartyMostConstituentsVote(Party p);

        // std::map<int, Candidate> GetCandidates() {return candidates_;}
        void Campaign(int cand_id, int dist_id);

        Candidate GetCandidate(int candidate_id) {return candidates_[candidate_id];}

        void Voting(District d);

        void CalculateWinner();

        Candidate WinnerInDistrict(District d);

        static const int NUM_DISTRICTS = 4;

        friend std::ostream& operator<<(std::ostream& os, Election &e){
            os << "======== Candidates ========" << std::endl;
            for (e.it_c = e.candidates_.begin(); e.it_c != e.candidates_.end(); e.it_c++){
                os << e.it_c->first << ": " << e.it_c->second << std::endl;
            }
		    return os;
	    }
        
    private:
        std::map<int, Candidate> candidates_;
        std::map<int, Candidate> :: iterator it_c;
        std::map<int, Candidate> :: iterator it_cmost;
        int cmap_size_;

        std::map<Party, int> votes_;
        std::map<Party, int> :: iterator it_v; 
        std::map<Party, int> :: iterator it_most; 
};


#endif