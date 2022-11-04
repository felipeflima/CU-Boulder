/* CSCI 3010 - IPW
* Felipe Lima
* Homework 3
* 10/13/2020
* Election program simulator
* How to run: using Makefile
~make
~./election
*/
#ifndef DISTRICT_H
#define DISTRICT_H

#include <map>
#include <iostream>

enum class Party {None, One, Two, Three};

std::string PartyString(Party pt);

class District{
    public:
        District();
        int AreaGenerator();
        void InsertParty();
        int ConstituentsGenerator();

        const std::string GetDistrictName() {return district_name_;}

        int get_area() {return area_;}
        
        std::map<Party, int> get_constituents() {return constituents_;}
        int GetTotalConstituents();
        Party GetPartyMostConstituents(Party p);

        void DecreaseConst(Party p) {constituents_[p]--;}
        void IncreaseConst(Party p) {constituents_[p]++;}

        void AddVotesToDistrict(int v){votes_district_ = v;}
        int GetVotesDistrict(){return votes_district_;}

        friend std::ostream& operator<<(std::ostream& os, District &d){
		    os << "============================= " << d.district_name_ << " =============================" <<
            std::endl << "district area: " << d.area_ << std::endl << std::endl; //"            district id: " << d.district_id << std::endl;
            for (d.it_co = d.constituents_.begin(); d.it_co != d.constituents_.end(); d.it_co++){
                os << PartyString(d.it_co->first) << " " << d.it_co->second << "            ";
            }
            os << std::endl << std::endl;

            
		    return os;
	    }
        
    private:
        std::string district_name_;
        int district_id;
        int area_;
        std::map<Party, int> constituents_;
        std::map<Party, int> :: iterator it_co; 

        int votes_district_;      
};



#endif