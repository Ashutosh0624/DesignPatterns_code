#include<iostream>
#include<memory>
using namespace std;

/* Dependency Inversion principle ( DIP )


High level module should not depend on level modules. 

Simple bhasa me: Client code hamesha interface (abstraction) ke throuh concrete classes se interact kare
Bascially , virtual function ka concepts apply kare in a broadshell 


*/
class ISensor{
    public:
    virtual float getSpeed() = 0;
    virtual ~ISensor() = default;
};

class RandomSensor : public ISensor{
    public:
    float getSpeed() override{
        return 56.89f;
    }
};
class SonarSensor: public ISensor{
    public:
    float getSpeed() override{
        return 23.88f;
    }
};

// client code 
class SensorPresenter{
    std::unique_ptr<ISensor>sensor;
    public:
    void setStrategy(std::unique_ptr<ISensor>newstrategy){
        sensor = std::move(newstrategy);
    }
    void getSensorSPeed(){
        cout<<sensor->getSpeed()<<endl;
    }
};