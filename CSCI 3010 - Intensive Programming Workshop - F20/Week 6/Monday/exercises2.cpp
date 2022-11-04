#include <iostream>
#include <string>
#include <vector>

// Names: Felipe Lima & Justin Vuong
//
//

// we'd like to write a function that is applicable to many types but
// we don't want to copy paste everything

struct Str{ 
    int a;
};

Str operator+=(const Str &s, const Str &s2){
    Str b;
    b.a = 0;
    b.a += s.a;
    return b;
}

// For example, here is a templated Add function
template <typename T>
T Add(T v1, T v2) {
    return v1 + v2;
}

// 6) implement a templated version of AddToValues, "AddToValues2".
template <typename A>
std::vector<A> AddToValues2(std::vector<A> v1, A v2){
    for (int i = 0; i < v1.size(); i ++){
        v1[i] += v2;
    }
    return v1;
}


int main() {
    // 7) call AddToValues2, passing in an int vector and another int.
    std::vector<int> vec1 = {1,2,3};
    std::vector<int> r_vec = AddToValues2(vec1, 2);


    // 8) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? 1 versions of AddToValues2 are in the compiled code
    
    
    // Copy + paste the relevant lines here:
    // 0000000000000130 T std::__1::vector<int, std::__1::allocator<int> > AddToValues2<int>(std::__1::vector<int, std::__1::allocator<int> >, int)


    // 9) call AddToValues2, passing in a vector of a non-int type and a value that you can add
    // successfully to the elements
    std::vector<double> vec2 = {1.0, 2.0, 3.5};
    std::vector<double> r_vec2 = AddToValues2(vec2, 3.0);


    // 10) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? 2 versions of AddToValues are in the compiled code
    
    // Copy + paste the relevant lines here:
    // 0000000000000350 T std::__1::vector<double, std::__1::allocator<double> > AddToValues2<double>(std::__1::vector<double, std::__1::allocator<double> >, double)
    // 0000000000000250 T std::__1::vector<int, std::__1::allocator<int> > AddToValues2<int>(std::__1::vector<int, std::__1::allocator<int> >, int)

    // 11) Experiment to find calls to this function that you would like to work but that do
    // not yet work. for each function call that doesn't work, comment about what type of 
    // error is produced.

    // std::vector<double> r_vec3 = AddToValues2(vec2, 3);
    // no matching function call
    // candidate template ignored: deduced conflicting types for parameter 'A' ('double' vs. 'int')

    // 12) Create a struct that has an int field. Instantiate a vector of these structs.
    // Instantiate another instance of this struct.
    
    std::vector<Str> vec_s;
    Str s1;
    s1.a = 5;
    vec_s.push_back(s1);
    Str s2;
    s2.a = 5;
    
    // 13) Call AddToValues2 w/ the vector of structs and single struct from #12
    // Is there an error? If yes, what is it?
    //
    // Answer:
    std::vector<Str> r_vec4 = AddToValues2(vec_s, s2);
    // yes there is an error. the operator += cannot add structs without being overloaded.
    // no viable overload of +=

    // 14) If there was an error, attempt to fix it.

}
