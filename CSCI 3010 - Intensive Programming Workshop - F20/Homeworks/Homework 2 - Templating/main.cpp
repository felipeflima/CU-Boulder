#include <iostream>
#include <map>
#include "Counter.hpp"

int main (){
    // std::map<std::string, double> words_to_numbers; 
    // words_to_numbers["cat"] = 3.5; 
    // words_to_numbers["dog"] = 5.2; 
    // words_to_numbers["mouse"] = -100.0;

    // words_to_numbers["mouse"] += 5;
    // std::cout << words_to_numbers.at("mouse") << std::endl;

    // std::map<std::string, double> :: iterator it;
    // for (it = words_to_numbers.begin(); it != words_to_numbers.end(); it++) {
    //     std::cout << it->first << std::endl;
    //     std::cout << it->second << std::endl;
    // }
    // std::cout << "---------" << std::endl;

    // it-- = words_to_numbers.end();
    // std::cout << it->first << std::endl;

    // std::cout << "---------" << std::endl;
    // std::string m = "mouse";
    // std::cout << words_to_numbers["mouse"] << std::endl;

    std::vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(40);

    Counter<int> *c1 = new Counter<int>(v1);


    // c1->PrintMap();
    std::cout << *c1 << std::endl;

    // std::cout << "---------" << std::endl;

    // std::cout << c1->Count() << std::endl;
    // std::cout << c1->Count(2) << std::endl;
    // std::cout << c1->Count(1,4) << std::endl;


    // std::cout << "---------" << std::endl;
    // c1->Increment(20);
    // c1->PrintMap();
    // c1->PrintMap();
    // c1->Increment(2, 5);
    // c1->PrintMap();
    // std::cout << c1->MostCommon() << std::endl;

    // std::cout << "---------" << std::endl;
    // c1->Decrement(2);
    // c1->PrintMap();
    // c1->Decrement(2, 5);
    // c1->PrintMap();

    // std::cout << "most common: ";
    // std::cout << c1->MostCommon() << std::endl;

    // std::cout << "---------" << std::endl;
    // c1->Increment(10, 5);

    // std::vector<int> v2;
    // c1->Increment(10,40);
    // c1->Increment(30,9);
    // c1->Increment(40,12);
    //c1->PrintMap();
    // std::cout << c1->MostCommon();
    // v2 = c1->MostCommon(2);
    // v2 = c1->LeastCommon(2);
    // std::cout << "Most common " << std::endl;
    // std::cout << "Least common " << std::endl;
    //std::cout << v2.size() << std::endl;
    // for (int i = 0; i < v2.size(); i++){
        // std::cout << v2[i] << std:: endl;
    // }

    //c1->Increment(10, 5);
    // std::cout << "Least common: ";    
    // std::cout << c1->LeastCommon(3) << std::endl;


    // std::cout << "---------" << std::endl;
    // std::vector<int> v2;
    // v2 = c1->LeastCommon(2);
    // for (int i = 0; i < v2.size(); i++){
    //     std::cout << v2[i] << std:: endl;
    // }
        
    // c1->Normalized();

    //c1->Values();

    // std::cout << *c1 << std::endl;
    //std::cout << c1->PrintMap();





    // std::vector<int> v1;
    // v1.push_back(20);
    // v1.push_back(0);
    // v1.push_back(30);
    // v1.push_back(40);
    // v1.push_back(40);
    // v1.push_back(5);
    // v1.push_back(20);
    // v1.push_back(30);
    // v1.push_back(40);
    // v1.push_back(40);
    // Counter<int> *c1 = new Counter<int>(v1);
    // std::cout << *c1 << std::endl;

    // std::cout << c1->Count(10,5) << std::endl;


}
