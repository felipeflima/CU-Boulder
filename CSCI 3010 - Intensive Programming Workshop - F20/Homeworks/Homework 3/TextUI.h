/* CSCI 3010 - IPW
* Felipe Lima
* Homework 3
* 10/13/2020
* Election program simulator
* How to run: using Makefile
~make
~./election
*/
#ifndef TEXTUI_H
#define TEXTUI_H

#include <iostream>
// #include <map>
// #include "District.h"
#include "ElectoralMap.h"
#include "Representative.h"

class TextUI{
    public:
        TextUI();

        void ElectionType(Election &election, ElectoralMap &electoral, RepresentativeElection &rep);
        void Register(Election &election, ElectoralMap &electoral);
        void CampaignUI(Election &election, ElectoralMap &electoral);
        void CallElection(Election &election, ElectoralMap &electoral, RepresentativeElection &rep);

        bool END;

    private:
        std::string election_type_;
        int candidate_id_;
        std::map<int, Candidate> candidatesUI_;
        std::map<int, Candidate> :: iterator it_cUI;
        bool candidate_camp_done;

        bool ele_end_;
};


#endif