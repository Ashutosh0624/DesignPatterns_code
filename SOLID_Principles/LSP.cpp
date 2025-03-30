/*
 
LSP = Liskov substitution principle 

What?
   LSP says that derived class should behave like base class without surprising the user. 
   LSP checks whether the behaviour is consistent or not across the base classes and derived classes. 

   Hinglish explanation: base class behaviours jo expect kar raha , woh same derive class se bhi expect kiya jaata hai
 
*/

#include<iostream>
using namespace std;

class ISimulator{
    public:
    virtual void simulate() = 0;
    virtual ~ISimulator();
};

class SpeedSimulator: public ISimulator{
    public:
    void simulate() override{
        /*
           This function should behave in the same way as base class's function is expected to behave.
           This follows Liskov substituion principle.
        */
    }
};

class BrokenSimulator: public ISimulator{
    public: 
    void simulate() override{
        throw std::runtime_error{
            "Sensor failed!!"<<endl;  
        }
        /*
            here , the derived class is not following LSP (Liskov substituition principle) as the behaviour is not able to simulate 
            as per the base class simulate function is expected to do 
        */
    }
}
/*
   
  In both the cases, we can see that virtual function concept is applied but in the second case LSP is broken. 
  SO, concept is LSP is implemented using virtual function  concept but condition is that base class and derived classes should behave similarly.

  Final thoughts : 
    1) Every class that overrides virtual functions should also obey LSP for a better software design architecture - i.e should behave like base class without 
    causing surprise. 

    SO haan: 
       1) LSP is built on virtual functions
       2) but it goes beyond - to ensure expected , correct behavior

*/