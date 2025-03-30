/*

Open for extenion but closed for modification

NOt: Strategy pattern is the best tool for implementing OCP principle 
*/
#include<iostream>
using namespace std;

class SensorSimulator{
    public:
    virtual void simulate() = 0;\
    virtual ~SensorSimulator();
};

class SpeedSenor: public SensorSimulator{
    public:
    void simulate(){
        cout<<" Speed simulation going one!!"<<endl;
    }
};

class LaneDetectOffset: public SensorSimulator{
    public:
    void simulate(){
        cout<<"Lane detect offset simulator!!"<<endl;
    }
};
/*
   In this example: we can see that :
       Open for extension but closed for modification : 
       that we can add new features without modifying the older code or base class code 
       SensorSimulator class is the base class which is not be modified and can be extended as well by add new features such as temperature sensor , windspeed detector 
       etc. 


       By doing this , we are making sure that the code is 
       1) maintainable
       2) testable
       3) scalable : by adding new features without touching the older code 
       4) readable
*/