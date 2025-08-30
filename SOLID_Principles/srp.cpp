/*

Single Responsibility principle :  a class should have one reason to change, means one class should have just one responsibility

*/
#include<iostream>
using namespace std;

class SensorSimulator{
    public:
    using SensorCallback = std::function<void(float speed, float distance)>;

    explicit SensorSimulator(SensorCallback SensorCallback)
        : callback_(callback) {}

        void simulateStep(){

            float speed = ...;
            float distance = ...;

            callback_(speed, distance);
        }
};

/*
The class just does one responsibility 

no processing, not analysing, just simulating and emitting 
*/