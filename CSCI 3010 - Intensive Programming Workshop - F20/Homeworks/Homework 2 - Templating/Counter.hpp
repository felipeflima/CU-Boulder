/* CSCI 3010 - IPW
* Felipe Lima
* Homework 2 - Templating
* 10/06/2020
* Counter<T> class
* How to run: don't run this file. Use test.cpp for testing
*/

#ifndef COUNTER_H
#define COUNTER_H
#include <iostream>
#include <vector>
#include <map>
#include <set> 
#include <string>

template <class T>
class Counter {
public:
    Counter();
    Counter(const std::vector<T> vals);

    void Erase(int n){
        counter.erase(n);
    }

    std::string PrintMap();

    int Count();
    int Count(const T key);
    int Count(const T min, const T max);

    void Remove(const T key);

    void Increment(const T key);
    void Increment( const T key, const int n);
    void Decrement(const T key);
    void Decrement(const T key, const int n);

    T MostCommon();
    std::vector<T> MostCommon(const int n);

    T LeastCommon();
    std::vector<T> LeastCommon(const int n);

    std::map<T, double> Normalized();

    std::set<T> Keys();

    std::vector<int> Values(); 

    //template <typename U>
    friend std::ostream& operator<<(std::ostream& os,  Counter<T> &b){
        os << "{";
        for (b.it = b.counter.begin(); b.it != b.counter.end(); b.it++){
            // if (b.it != b.counter.begin()){  // to us to not have a comma at the end.
            //     os << ",";
            // }
            os << b.it->first << ":" 
            << b.it->second << ",";
        }
        os << "}\n";
        //os << b.PrintMap();
        return os; 
    }

private:
    std::map<T, int> counter;
    typename std::map<T, int> :: iterator it;
    int count;
};


#endif


/**
 * Constructor - makes sure counter is empty
*/
template <class T>
Counter<T>::Counter(){
    counter.clear();
}

/**
 * Constructor -i nitialize a Counter<T> appropriately from a vector or array that contains type T
 * @param vector of values to be initiated
*/
template <class T>
Counter<T>::Counter(const std::vector<T> vals){
    bool repeated = 0;
    for (int i = 0; i < vals.size(); i++){ //for all the values in the vector
        repeated = 0;
        for (it = counter.begin(); it != counter.end(); it++){ //check if the value is already in counter
            if(vals[i] == it->first){
                repeated = 1;
            }
        }
        if (repeated == false){
            counter.insert(std::pair<T, int>(vals[i], 1)); //insert value 
        }
        else{
            Increment(vals[i]); //increment if already in counter
        }
    }
}

/**
 * Helper function to Print map in case type is a string
*/
template <>
std::string Counter<std::string>::PrintMap(){
    std::string map, key, value;
    map += "{";
    for (it = counter.begin(); it != counter.end(); it++){
        if (it != counter.begin()){
            map += ",";
        }
        key = (it->first);
        value = std::to_string(it->second);
        map += key + ":" + value;
    }
    map += "}";
    return map;

}

/**
 * Helper function to Print map
*/
template<class T>
std::string Counter<T>::PrintMap(){
    // std::cout << "KEY\tELEMENT\n"; 
    // for (it = counter.begin(); it != counter.end(); it++) { 
    // std::cout << it->first 
    //           << '\t' << it->second << '\n'; 
    // } 
    std::string map, key, value;
    map += "{";
    for (it = counter.begin(); it != counter.end(); it++){
        if (it != counter.begin()){
            map += ",";
        }
        key = std::to_string(it->first);
        value = std::to_string(it->second);
        map += key + ":" + value;
    }
    map += "}";
    return map;
}


/**
 * access the total of all counts so far
*/
template <class T>
int Counter<T>::Count(){
    count = 0;
    for (it  = counter.begin(); it != counter.end(); it++){
        count += it->second;
    }
    return count;
}

/**
 * access the count associated with any object T, even for values of T that have not been counted
 * @param a key
*/
template <class T>
int Counter<T>::Count(const T key){
    return counter[key];
}

/**
 * access the total of all counts for objects T given a certain range (an inclusive minimum T and an exclusive maximum T element)
 * @param min and max to count
*/
template <class T>
int Counter<T>::Count(const T min, const T max){
    count = 0;
    it = counter.begin();
    while(it != counter.end() && it->first != min){ // when it reached the min key
        it++;
    }
    while(it->first != max && it != counter.end()){ // when it reached the max key
        count += it->second;
        it++;
    }
    return count;
}

/**
 * remove the object T from the Counter
 * @param object to be removed
*/
template <class T>
void Counter<T>::Remove(const T key){
    counter.erase(key);
}

/**
 * increment the count of an object T by one
 * @param key to be incremented
*/
template <class T>
void Counter<T>::Increment(const T key){
    counter[key]++;
}

/**
 * increment the count of an object T by n
 * @param key to be incremented and by how much 
*/
template <class T>
void Counter<T>::Increment(const T key, const int n){
    counter[key] += n;
}

/**
 * decrement the count of an object T by one
 *  @param key to be decremented
*/
template <class T>
void Counter<T>::Decrement(const T key){
    if (counter[key] > 0){
        counter[key]--;
    }
}

/**
 * decrement the count of an object T by on
 * @param key to be decremented and by how much 
*/
template <class T>
void Counter<T>::Decrement(const T key, const int n){
    if (counter[key] < n){
        counter[key] = 0;
    }
    else{
        counter[key] -= n;
    }
}

/**
 * get the most commonly occurring object of type T (the object with the highest count)
*/
template <class T>
T Counter<T>::MostCommon(){
    if(counter.empty()){
        try
        {
            throw std::domain_error( "Your domain is in error!" );
        }
        catch (std::exception &e)
        {
            std::cerr << "Caught: " << e.what( ) << std::endl;
            std::cerr << "Type: " << typeid(e).name( ) << std::endl;
        };
    }
    T most_common;
    most_common = counter.begin()->first;
    for (it = counter.begin(); it != counter.end(); it++){
        if (it->second > counter[most_common]){
            most_common = it->first;            
        }
    }
    return most_common;
}

/**
 * get the n most commonly occurring objects of type T. If the Counter is empty, this method should return a vector of size 0.
 * @param how many objects are going in the vector
*/
template <class T>
std::vector<T> Counter<T>::MostCommon(const int n){
    std::vector<T> most_commons;
    if (counter.empty()){
        return most_commons;
    }
    std::map<T, int> highest;
    highest = counter;
    T high;
    for (int i = 0; i < n; i++){ // number of objects in the vector
        high = highest.begin()->first;
        for (it = highest.begin(); it != highest.end(); it++){ //iterate through map
            if (it->second > highest[high]){ 
            high = it->first;      // store the largest element      
            }
        }
        most_commons.push_back(high); //push it to the vector
        highest.erase(high); // delete from the highest map so it is not taked into account again
    }
    return most_commons;
}

/**
 * get the least commonly occurring object of type T (the object with the highest count)
*/
template <class T>
T Counter<T>::LeastCommon(){
    if(counter.empty()){
        try
        {
            throw std::domain_error( "Your domain is in error!" );
        }
        catch (std::exception &e)
        {
            std::cerr << "Caught: " << e.what( ) << std::endl;
            std::cerr << "Type: " << typeid(e).name( ) << std::endl;
        };
    }
    T least_common;
    least_common = counter.begin()->first;
    for (it = counter.begin(); it != counter.end(); it++){
        if (it->second < counter[least_common]){
            least_common = it->first;            
        }
    }
    return least_common;
}

/**
 * get the n least commonly occurring objects of type T get the n most commonly occurring objects of type T. If the Counter is empty, this method should return a vector of size 0.
 * @param how many objects are going in the vector
*/
template <class T>
std::vector<T> Counter<T>::LeastCommon(const int n){
    std::vector<T> least_commons;
    if (counter.empty()){
        return least_commons;
    }
    std::map<T, int> lowest;
    lowest = counter;
    T low;
    for (int i = 0; i < n; i++){ // number of objects in the vector
        low = lowest.begin()->first;
        for (it = lowest.begin(); it != lowest.end(); it++){ //iterate through map
            if (it->second < lowest[low]){
            low = it->first;            // store the smallest element      
            }
        }
        least_commons.push_back(low); //push it to the vector
        lowest.erase(low);// delete from the lowest map so it is not taked into account again
    }
    return least_commons;
}

/**
 * access normalized weights for all objects of type T seen so far
*/
template <class T>
std::map<T, double> Counter<T>::Normalized(){
    std::map<T, double> normalized;
    double count = Count();
    double avg = 0;
    for (it = counter.begin(); it != counter.end(); it++){
        avg = (it->second)/count;
        normalized.insert(std::pair<T, double>(it->first, avg));
    }
    return normalized;
}

/**
 * access the set of all keys in the Counter
*/
template <class T>
std::set<T> Counter<T>::Keys(){
    std::set<T> keys;
    for (it = counter.begin(); it != counter.end(); it++){
        keys.insert(it->first);
    }
    return keys;
}

/**
 * access the collection of all values in the Counter
*/
template <class T>
std::vector<int> Counter<T>::Values(){
    std::vector<int> values;
    for (it = counter.begin(); it != counter.end(); it++){
        values.push_back(it->second);
    }
    return values;
}