/*
Interface segregation principle (ISP) : clients should not be forced to use functions which they dont need to do so. 
Simple bhasa me : Apne interfaces ko small , role specific rakho so that client wahi implement kare jo usko chahiye. 
*/
#include<iostream>
using namespace std;

// valid interfaces following ISP 
class IGetSpeed{
    public: 
    virtual float getSpeed() = 0;
    virtual ~IGetSpeed() = default;
};

class SensorSpeed: public IGetSpeed{
    public:
    float getSpeed(){
        return m_speed;
    }
};
/*

In the above example, we can see that the above interface only offers getspeed  behaviour which the client sensorspeed wants and not forced to implement any other
behavior. 
*/
class UGetSpeed{
    public:
    virtual float getSpeed_val() = 0;
    virtual float getDistance() = 0;  // this behavior is not required by the client to use, but this interface will force the client to implement this as weell
    vitual ~UGetSpeed() = default;    // hence , this is not according to the ISP 
};