/* CSCI 3010 - IPW
* Felipe Lima
* Homework 2 - Templating
* 10/06/2020
* Counter<T> class
* How to run: using Makefile
~make
~./test
*/

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Counter.hpp"

TEST_CASE ("Checks if an empty Counter<T> is created correctly", "[Counter<T>::Counter]"){
    SECTION("Counter<T> no param"){
        Counter<int> *c1 = new Counter<int>();
        REQUIRE(c1->PrintMap() == "{}");
    }
    SECTION("Counter<T> vector param int"){
        std::vector<int> v1;
        v1.push_back(10);
        v1.push_back(20);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(40);
        v1.push_back(5);
        Counter<int> *c1 = new Counter<int>(v1);
        REQUIRE(c1->PrintMap() == "{5:1,10:1,20:1,30:1,40:2}");
    }
    SECTION("Counter<T> vector param double"){
        std::vector<double> v1;
        v1.push_back(10.0);
        v1.push_back(20.5);
        v1.push_back(30.234);
        v1.push_back(40.2);
        v1.push_back(40.2);
        Counter<double> *c1 = new Counter<double>(v1);
        REQUIRE(c1->PrintMap() == "{10.000000:1,20.500000:1,30.234000:1,40.200000:2}");
    }
    SECTION("Counter<T> vector param string"){
        std::vector<std::string> v2;
        v2.push_back("cat");
        v2.push_back("dog");
        v2.push_back("lion");
        v2.push_back("tiger");
        v2.push_back("lion");
        v2.push_back("bird");
        Counter<std::string> *c1 = new Counter<std::string>(v2);
        REQUIRE(c1->PrintMap() == "{bird:1,cat:1,dog:1,lion:2,tiger:1}");
    }
}

TEST_CASE ("Checks if an empty Count counts correctly", "[Counter<T>::Count]"){
    SECTION("Checks for Count no param - total of counts"){
        SECTION("INT"){
            std::vector<int> v1;
            v1.push_back(10);
            v1.push_back(20);
            v1.push_back(30);
            v1.push_back(40);
            v1.push_back(40);
            v1.push_back(5);
            v1.push_back(20);
            v1.push_back(30);
            v1.push_back(40);
            v1.push_back(40);
            Counter<int> *c1 = new Counter<int>(v1);
            REQUIRE(c1->Count() == 10);
            v1.push_back(40);
            v1.push_back(5);
            v1.push_back(20);
            v1.push_back(30);
            v1.push_back(40);
            Counter<int> *c2 = new Counter<int>(v1);
            REQUIRE(c2->Count() == 15);
        }
        SECTION("String"){
            std::vector<std::string> v2;
            v2.push_back("cat");
            v2.push_back("dog");
            v2.push_back("lion");
            v2.push_back("tiger");
            v2.push_back("lion");
            Counter<std::string> *c1 = new Counter<std::string>(v2);
            REQUIRE(c1->Count() == 5);
        }
        
    }
    SECTION("Checks for Count key param - counts of an object"){
        SECTION("INT"){
            std::vector<int> v1;
            v1.push_back(10);
            v1.push_back(20);
            v1.push_back(30);
            v1.push_back(40);
            v1.push_back(40);
            v1.push_back(5);
            v1.push_back(20);
            v1.push_back(30);
            v1.push_back(40);
            v1.push_back(40);
            Counter<int> *c1 = new Counter<int>(v1);
            REQUIRE(c1->Count(40) == 4);
            REQUIRE(c1->Count(20) == 2);
            REQUIRE(c1->Count(10) == 1);
        }
        SECTION("DOUBLE"){
            std::vector<double> v1;
            v1.push_back(10.0);
            v1.push_back(20.5);
            v1.push_back(30.234);
            v1.push_back(40.2);
            v1.push_back(40.2);
            Counter<double> *c1 = new Counter<double>(v1);
            REQUIRE(c1->Count(40.2) == 2);
            REQUIRE(c1->Count(10.0) == 1);
        }
    }
    SECTION("Checks for Count two param - counts for objects T given a certain range"){
        SECTION("INT"){
            std::vector<int> v1;
            v1.push_back(20);
            v1.push_back(10);
            v1.push_back(30);
            v1.push_back(40);
            v1.push_back(40);
            v1.push_back(5);
            v1.push_back(20);
            v1.push_back(30);
            v1.push_back(40);
            v1.push_back(40);
            Counter<int> *c1 = new Counter<int>(v1);
            REQUIRE(c1->Count(10,30) == 3);
            REQUIRE(c1->Count(5,10) == 1);
            REQUIRE(c1->Count(20,30) == 2);
            REQUIRE(c1->Count(10,5) == 9);
        }
        SECTION("DOUBLE"){
            std::vector<double> v1;
            v1.push_back(10.0);
            v1.push_back(20.5);
            v1.push_back(30.234);
            v1.push_back(40.2);
            v1.push_back(40.2);
            Counter<double> *c1 = new Counter<double>(v1);
            REQUIRE(c1->Count(10.0, 30.234) == 2);
            REQUIRE(c1->Count(30.234,40.2) == 1);
            REQUIRE(c1->Count(10.0,40.2) == 3);
        }
        SECTION("String"){
            std::vector<std::string> v2;
            v2.push_back("cat");
            v2.push_back("dog");
            v2.push_back("lion");
            v2.push_back("tiger");
            v2.push_back("lion");
            Counter<std::string> *c1 = new Counter<std::string>(v2);
            REQUIRE(c1->Count("cat", "lion") == 2);
            REQUIRE(c1->Count("cat", "tiger") == 4);
            REQUIRE(c1->Count("dog", "tiger") == 3);
        }
    }
}


TEST_CASE ("Checks if an empty Remove removes an element correctly", "[Counter<T>::Remove]"){
    SECTION("int"){
        std::vector<int> v1;
            v1.push_back(32);
            v1.push_back(23);
            v1.push_back(54);
            v1.push_back(32);
            v1.push_back(3);
            v1.push_back(5);
            v1.push_back(50);
            v1.push_back(30);
            v1.push_back(40);
            v1.push_back(40);
            Counter<int> *c1 = new Counter<int>(v1);
            REQUIRE(c1->PrintMap() == "{3:1,5:1,23:1,30:1,32:2,40:2,50:1,54:1}");
            c1->Remove(5);
            REQUIRE(c1->PrintMap() == "{3:1,23:1,30:1,32:2,40:2,50:1,54:1}");
            c1->Remove(32);
            REQUIRE(c1->PrintMap() == "{3:1,23:1,30:1,40:2,50:1,54:1}");
    }
    SECTION("String"){
        std::vector<std::string> v2;
        v2.push_back("cat");
        v2.push_back("dog");
        v2.push_back("lion");
        v2.push_back("tiger");
        v2.push_back("lion");
        Counter<std::string> *c1 = new Counter<std::string>(v2);
        REQUIRE(c1->PrintMap() == "{cat:1,dog:1,lion:2,tiger:1}");
        c1->Remove("cat");
        REQUIRE(c1->PrintMap() == "{dog:1,lion:2,tiger:1}");
        c1->Remove("lion");
        REQUIRE(c1->PrintMap() == "{dog:1,tiger:1}");
    }
}

TEST_CASE ("Checks if an empty Increment increments an element correctly", "[Counter<T>::Increment]"){
    SECTION("int - key param ++"){
        std::vector<int> v1;
        v1.push_back(32);
        v1.push_back(23);
        v1.push_back(54);
        v1.push_back(32);
        v1.push_back(3);
        v1.push_back(5);
        v1.push_back(50);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(40);
        Counter<int> *c1 = new Counter<int>(v1);
        REQUIRE(c1->PrintMap() == "{3:1,5:1,23:1,30:1,32:2,40:2,50:1,54:1}");
        c1->Increment(5);
        REQUIRE(c1->PrintMap() == "{3:1,5:2,23:1,30:1,32:2,40:2,50:1,54:1}");
        c1->Increment(32);
        REQUIRE(c1->PrintMap() == "{3:1,5:2,23:1,30:1,32:3,40:2,50:1,54:1}");
    }  
    SECTION("String + n"){
        std::vector<std::string> v2;
        v2.push_back("cat");
        v2.push_back("dog");
        v2.push_back("lion");
        v2.push_back("tiger");
        v2.push_back("lion");
        Counter<std::string> *c1 = new Counter<std::string>(v2);
        REQUIRE(c1->PrintMap() == "{cat:1,dog:1,lion:2,tiger:1}");
        c1->Increment("cat",3);
        REQUIRE(c1->PrintMap() == "{cat:4,dog:1,lion:2,tiger:1}");
        c1->Increment("lion",5);
        REQUIRE(c1->PrintMap() == "{cat:4,dog:1,lion:7,tiger:1}");
    }     
}

TEST_CASE ("Checks if an empty Increment decrements an element correctly", "[Counter<T>::Decrement]"){
    SECTION("int - key param ++"){
        std::vector<int> v1;
        v1.push_back(32);
        v1.push_back(23);
        v1.push_back(54);
        v1.push_back(32);
        v1.push_back(3);
        v1.push_back(5);
        v1.push_back(50);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(40);
        Counter<int> *c1 = new Counter<int>(v1);
        REQUIRE(c1->PrintMap() == "{3:1,5:1,23:1,30:1,32:2,40:2,50:1,54:1}");
        c1->Decrement(5);
        REQUIRE(c1->PrintMap() == "{3:1,5:0,23:1,30:1,32:2,40:2,50:1,54:1}");
        c1->Decrement(32);
        REQUIRE(c1->PrintMap() == "{3:1,5:0,23:1,30:1,32:1,40:2,50:1,54:1}");
        c1->Decrement(5);
        REQUIRE(c1->Count(5) == 0); //() == "{3:1,5:0,23:1,30:1,32:2,40:2,50:1,54:1}");
    }  
    SECTION("String + n"){
        std::vector<std::string> v2;
        v2.push_back("cat");
        v2.push_back("dog");
        v2.push_back("lion");
        v2.push_back("tiger");
        v2.push_back("lion");
        Counter<std::string> *c1 = new Counter<std::string>(v2);
        REQUIRE(c1->PrintMap() == "{cat:1,dog:1,lion:2,tiger:1}");
        c1->Decrement("cat", 1);
        REQUIRE(c1->PrintMap() == "{cat:0,dog:1,lion:2,tiger:1}");
        c1->Decrement("lion", 2);
        REQUIRE(c1->PrintMap() == "{cat:0,dog:1,lion:0,tiger:1}");
        c1->Decrement("lion", 2);
        REQUIRE(c1->PrintMap() == "{cat:0,dog:1,lion:0,tiger:1}");
        c1->Decrement("lion", 4);
        REQUIRE(c1->PrintMap() == "{cat:0,dog:1,lion:0,tiger:1}");
    }     
}


TEST_CASE ("Checks if an empty MostCommon returns the right elements", "[Counter<T>::MostCommon]"){
    SECTION("int"){
        std::vector<int> v1;
        v1.push_back(32);
        v1.push_back(23);
        v1.push_back(54);
        v1.push_back(32);
        v1.push_back(3);
        v1.push_back(5);
        v1.push_back(50);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(40);
        Counter<int> *c1 = new Counter<int>(v1);
        REQUIRE(c1->PrintMap() == "{3:1,5:1,23:1,30:1,32:2,40:2,50:1,54:1}");
        REQUIRE(c1->MostCommon() == 32);
        c1->Increment(54,10);
        REQUIRE(c1->MostCommon() == 54);

        
    }  
    SECTION("String + n"){
        std::vector<std::string> v2;
        v2.push_back("cat");
        v2.push_back("dog");
        v2.push_back("lion");
        v2.push_back("tiger");
        v2.push_back("lion");
        std::vector<std::string> v3;
        v3.push_back("lion");
        v3.push_back("cat");
        Counter<std::string> *c1 = new Counter<std::string>(v2);
        REQUIRE(c1->PrintMap() == "{cat:1,dog:1,lion:2,tiger:1}");
        REQUIRE(c1->MostCommon(2) == v3);
        v3.push_back("dog");
        REQUIRE(c1->MostCommon(3) == v3);
    }     
}

TEST_CASE ("Checks if an empty leastCommon returns the right elements", "[Counter<T>::LeastCommon]"){
    SECTION("int"){
        std::vector<int> v1;
        v1.push_back(32);
        v1.push_back(23);
        v1.push_back(54);
        v1.push_back(32);
        v1.push_back(3);
        v1.push_back(5);
        v1.push_back(50);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(40);
        Counter<int> *c1 = new Counter<int>(v1);
        REQUIRE(c1->PrintMap() == "{3:1,5:1,23:1,30:1,32:2,40:2,50:1,54:1}");
        REQUIRE(c1->LeastCommon() == 3);
        c1->Decrement(54);
        REQUIRE(c1->LeastCommon() == 54);

        
    }  
    SECTION("String + n"){
        std::vector<std::string> v2;
        v2.push_back("cat");
        v2.push_back("dog");
        v2.push_back("lion");
        v2.push_back("tiger");
        v2.push_back("lion");
        std::vector<std::string> v3;
        v3.push_back("cat");
        v3.push_back("dog");
        Counter<std::string> *c1 = new Counter<std::string>(v2);
        REQUIRE(c1->PrintMap() == "{cat:1,dog:1,lion:2,tiger:1}");
        REQUIRE(c1->LeastCommon(2) == v3);
        v3.push_back("tiger");
        REQUIRE(c1->LeastCommon(3) == v3);
    }     
}

TEST_CASE ("Checks if an empty Normalized returns the right elements", "[Counter<T>::Normalized]"){
    SECTION("int"){
        std::map<int, double> compare;
        compare.insert(std::pair<int, double>(3, 0.1));
        compare.insert(std::pair<int, double>(5, 0.1));
        compare.insert(std::pair<int, double>(23, 0.1));
        compare.insert(std::pair<int, double>(30, 0.1));
        compare.insert(std::pair<int, double>(32, 0.2));
        compare.insert(std::pair<int, double>(40, 0.1));
        compare.insert(std::pair<int, double>(50, 0.1));
        compare.insert(std::pair<int, double>(54, 0.1));
        compare.insert(std::pair<int, double>(153, 0.1));
        std::vector<int> v1;
        v1.push_back(32);
        v1.push_back(23);
        v1.push_back(54);
        v1.push_back(32);
        v1.push_back(3);
        v1.push_back(5);
        v1.push_back(50);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(153);
        Counter<int> *c1 = new Counter<int>(v1);
        REQUIRE(c1->PrintMap() == "{3:1,5:1,23:1,30:1,32:2,40:1,50:1,54:1,153:1}");
        REQUIRE(c1->Normalized() == compare);
    }
    SECTION("string"){
        std::map<std::string, double> compare;
        compare.insert(std::pair<std::string, double>("cat", 0.2));
        compare.insert(std::pair<std::string, double>("dog", 0.2));
        compare.insert(std::pair<std::string, double>("lion", 0.4));
        compare.insert(std::pair<std::string, double>("tiger", 0.2));
        std::vector<std::string> v1;
        v1.push_back("cat");
        v1.push_back("dog");
        v1.push_back("lion");
        v1.push_back("tiger");
        v1.push_back("lion");
        Counter<std::string> *c1 = new Counter<std::string>(v1);
        REQUIRE(c1->PrintMap() == "{cat:1,dog:1,lion:2,tiger:1}");
        REQUIRE(c1->Normalized() == compare);
    }
}

TEST_CASE ("Checks if an empty Keys returns the right elements", "[Counter<T>::Keys]"){
    SECTION("int"){
        std::set<int> s1;
        s1.insert(3);
        s1.insert(5);
        s1.insert(23);
        s1.insert(30);
        s1.insert(32);
        s1.insert(40);
        s1.insert(50);
        s1.insert(54);
        std::vector<int> v1;
        v1.push_back(32);
        v1.push_back(23);
        v1.push_back(54);
        v1.push_back(32);
        v1.push_back(3);
        v1.push_back(5);
        v1.push_back(50);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(40);
        Counter<int> *c1 = new Counter<int>(v1);
        REQUIRE(c1->PrintMap() == "{3:1,5:1,23:1,30:1,32:2,40:2,50:1,54:1}");
        REQUIRE(c1->Keys() == s1);
    }

    SECTION("String"){
        std::set<std::string> s1;
        s1.insert("cat");
        s1.insert("dog");
        s1.insert("lion");
        s1.insert("tiger");
        std::vector<std::string> v2;
        v2.push_back("cat");
        v2.push_back("dog");
        v2.push_back("lion");
        v2.push_back("tiger");
        v2.push_back("lion");
        Counter<std::string> *c1 = new Counter<std::string>(v2);
        REQUIRE(c1->PrintMap() == "{cat:1,dog:1,lion:2,tiger:1}");
        REQUIRE(c1->Keys() == s1);
    }     
}


TEST_CASE ("Checks if an empty Values returns the right elements", "[Counter<T>::Values]"){
        SECTION("int"){
        std::vector<int> s1;
        s1.push_back(1);
        s1.push_back(1);
        s1.push_back(1);
        s1.push_back(1);
        s1.push_back(2);
        s1.push_back(2);
        s1.push_back(1);
        s1.push_back(1);
        std::vector<int> v1;
        v1.push_back(32);
        v1.push_back(23);
        v1.push_back(54);
        v1.push_back(32);
        v1.push_back(3);
        v1.push_back(5);
        v1.push_back(50);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(40);
        Counter<int> *c1 = new Counter<int>(v1);
        REQUIRE(c1->PrintMap() == "{3:1,5:1,23:1,30:1,32:2,40:2,50:1,54:1}");
        REQUIRE(c1->Values() == s1);
    }

    SECTION("String"){
        std::vector<int> s1;
        s1.push_back(1);
        s1.push_back(1);
        s1.push_back(2);
        s1.push_back(1);
        std::vector<std::string> v2;
        v2.push_back("cat");
        v2.push_back("dog");
        v2.push_back("lion");
        v2.push_back("tiger");
        v2.push_back("lion");
        Counter<std::string> *c1 = new Counter<std::string>(v2);
        REQUIRE(c1->PrintMap() == "{cat:1,dog:1,lion:2,tiger:1}");
        REQUIRE(c1->Values() == s1);
    }     
}