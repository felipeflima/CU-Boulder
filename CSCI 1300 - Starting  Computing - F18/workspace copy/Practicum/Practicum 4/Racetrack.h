// #ifndef RACETRACK_H
// #define RACETRACK_H
// #include <iostream>
// using namespace std;

class RaceTrack
{
    public:
        RaceTrack();
        RaceTrack(string);
        void initDataMembers();
        bool addCar(float, string);
        float calcAvgSpeed();
        int countAvailable(float);
        int countAvailableModels(string);
    private:
        string name;
        float speeds[100];
        string models[100];
        int nCars;
        
        
};

// #endif