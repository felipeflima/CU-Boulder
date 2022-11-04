#include <iostream>
#include "Earth.h"

// Names:
//

int main(int argc, char **argv){
    // 0) Implement your Earth's constructor in Earth.cpp

    // 1) Get an instance of your earth object
    Earth& e0 = Earth::GetInstance();

    // 2) Get another instance of your earth object
    Earth& e1 = Earth::GetInstance();

    // 3) Test to see if the two Earth instances from #1 and #2 are stored at the same
    // location in memory.
    if (&e0 == &e1){
        std::cout << "Same memory location" << std::endl;
    }
    else{
        std::cout << "Different memory location" << std::endl;
    }
    
    // 3) Call IncreasePopulation from one of your Earth instances. Can you see this change
    // from your other Earth instance?
    //yes
    e0.IncreasePopulation();
    std::cout << "e0 population: " << e0.get_population() << " e1 population: " << e1.get_population() << std::endl;

    // 4) Create a public field in your Earth object. Do you need an instance of an Earth object
    // to access this field? 
    // if is static you can access the filed without an object
    // if its not static you need an object
    std::cout << Earth::NUM_CONTINENTS << std::endl;
    std::cout << e0.hello << std::endl;


	return 0;
}
