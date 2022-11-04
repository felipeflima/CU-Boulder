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
// #include "ElectoralMap.h"
// #include "District.h"
#include "TextUI.h"


TextUI::TextUI(){
    election_type_ = "";
    ele_end_ = 0;
}


/**
 * Function handles election type and rerouting
*/ 
void TextUI::ElectionType(Election &election, ElectoralMap &electoral, RepresentativeElection &rep){
    ele_end_ = 0;
    std::cout << "What kind of election should we have (direct or representative, 0 to stop program)?" << std::endl;
    while (ele_end_ == 0){
        std::cin >> election_type_;
        if (election_type_ == "0"){
            std::cout << "Exiting" << std::endl;
            END = 1;
            break;
        }
        else if (election_type_ != "direct" && election_type_ != "representative"){
            std::cout << "Please enter an election type (direct or representative, 0 to stop program)" << std::endl;
        }
        else{
            Register(election, electoral);
            std::cout << electoral << election << std::endl;
            candidate_camp_done = 0;
            while (candidate_camp_done == 0){
                CampaignUI(election, electoral);
            }
            std::cout << electoral << election << std::endl;
            CallElection(election, electoral, rep);
            ele_end_ = 1;
        }
    }
}

/**
 * Function hanldes the regitration of candidates and user input
*/ 
void TextUI::Register(Election &election, ElectoralMap &electoral){
    bool one = 0;
    while (one == 0){
        candidate_id_ = 0;
        std::string candidate_name = "";
        std::string choice = "";
        bool valid_choice = 0;
        for (int i = 1; i < ElectoralMap::NUM_PARTIES; i ++){
            valid_choice = 0;
            while (valid_choice == 0 && i < ElectoralMap::NUM_PARTIES){
                std::cout << "Do you want to register a candidate for party " << i << " (y or n)? ";
                std::cin >> choice;
                if (choice == "n") {
                    valid_choice = 1;
                }
                else if (choice == "y"){
                    one = 1;
                    candidate_id_++;
                    std::cout << "What is their name? ";
                    std::cin>>candidate_name;
                    election.RegisterCandidates(candidate_name, i, candidate_id_);
                }
            }
        }
        if (one == 0){
            std::cout << "You need to register at least one candidate" << std::endl;
        }
    }
}

/**
 * Function hanldes the campaigning of candidates and user input
*/ 
void TextUI::CampaignUI(Election &election, ElectoralMap &electoral){
    int campaing_candidate = -1;
    int campaing_district = -1;
    bool cand_found = 0;
    bool dist_found = 0;
    while (campaing_candidate != 0){
        cand_found = 0;
        std::cout << "Which candidate is campaigning (id) (0 to stop campaigning)? ";
        std::cin >> campaing_candidate;
        if(campaing_candidate == 0){
            candidate_camp_done = 1;
            break;
        }
        while (campaing_candidate != 0 && cand_found == 0){
            if (campaing_candidate > 0 && campaing_candidate <= election.GetCMapSize()){
                cand_found = 1;
                break;
            }
            else if (cand_found == 0){
                std::cout << "Candidate not found. Please insert a candidate id (0 to stop campaigning)" << std::endl;
                std::cin >> campaing_candidate;
            }
        }
        campaing_district = -1;
        while (campaing_district != 0){
            dist_found = 0;
            std::cout << "Where is candidate " << campaing_candidate << " campaigning (id) (0 to stop)? ";
            std::cin >> campaing_district;
            while (dist_found == 0 && campaing_district != 0){
                if (campaing_district > 0 && campaing_district <= electoral.GetDMapSize()){
                    dist_found = 1;
                    electoral.Campaign(campaing_candidate, campaing_district, election);
                }
                else if (dist_found == 0){
                    std::cout << "District not found. Please insert a district id (0 to stop campaigning)" << std::endl;
                    std::cin >> campaing_district;
                }
            }
        }
    }
}

/**
 * Function hanldes the election based on type and user input
*/ 
void TextUI::CallElection(Election &election, ElectoralMap &electoral, RepresentativeElection &rep){
    if (election_type_ == "direct"){
        for (int i = 0; i < Election::NUM_DISTRICTS; i++){
            election.Voting(electoral.get_district(i+1));
        }
        election.CalculateWinner();
    }
    else if (election_type_ == "representative"){
        for (int i = 0; i < Election::NUM_DISTRICTS; i++){
            rep.CalculateVotes(electoral.get_district(i+1), electoral, election);
        }
        rep.TotalWinner(electoral, election);
    }
}