/* CSCI 3010 - IPW
* Felipe Lima
* Homework 3
* 10/13/2020
* Election program simulator
* How to run: using Makefile
~make
~./election
*/
#ifndef ELECTORALMAP_H
#define ELECTORALMAP_H

#include <iostream>
#include <map>
#include "Election.h"
#include "District.h"


class ElectoralMap{
    public:
        static ElectoralMap& GetInstance(){
            static ElectoralMap instance;
            return instance;
        }
        ElectoralMap(ElectoralMap const&) = delete; // copy constructor
	    void operator=(ElectoralMap const&) = delete; // assignment operator

        void InsertDistrict(District &d);
        District get_district(int id) { return districts_[id];}
        int GetDMapSize() {return dmap_size_;}

        void Campaign(int cand_id, int dist_id, Election &election);

        int TotalConstituents();

        // static const int NUM_DISTRICTS = 4;
        static const int NUM_PARTIES = 4;

        friend std::ostream& operator<<(std::ostream& os, ElectoralMap &e){
            os << std::endl;
            for (e.it_d = e.districts_.begin(); e.it_d != e.districts_.end(); e.it_d++){
                os << e.it_d->second;// << ",";
            }
		    return os;
	    }

    private:
        ElectoralMap();
        std::map<int, District> districts_;
        std::map<int, District> :: iterator it_d;
        int dmap_size_;
};

#endif