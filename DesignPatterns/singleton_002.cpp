#include<iostream>
using namespace std;

class Singleton{
    static Singleton * instance;
    static int instanceCount;
    
    Singleton(){
        ++instanceCount;
     }
    public:
    static Singleton* getInstance(){
        if(instance == nullptr){
            instance = new Singleton;
         }
        return instance;
    }

    static int getInstanceCount(){
        return instanceCount;
    }

    ~Singleton(){
        instanceCount--;
     }

     static void resetInstance(){
        delete instance;
        instance = nullptr;
     }


 };

int Singleton::instanceCount = 0;
Singleton* Singleton::instance = nullptr;

int main(){
    Singleton* S1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    Singleton* s3 = Singleton::getInstance();
    cout<<"Object count : "<<Singleton::getInstanceCount()<<endl;

    Singleton::resetInstance();
    cout<<"Object count : "<<Singleton::getInstanceCount()<<endl;
    return 0;

  }
