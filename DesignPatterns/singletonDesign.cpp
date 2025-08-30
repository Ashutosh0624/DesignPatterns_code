#include<iostream>
using namespace std;

class Singleton{
    static Singleton *instance;
    static int instanceCount;
    Singleton() {}

    public:
    static Singleton* getInstance(){
        if(instance == nullptr || instanceCount == 0){
            instance = new Singleton;
            instanceCount++;
        }
        return instance;
    }

    static int getInstanceCount(){
        return instanceCount;
    }

    ~Singleton(){
        delete instance;
        instance = nullptr;
        instanceCount--;
    }

    Singleton(const Singleton&) = delete; // copy constructor
    Singleton& operator=(const Singleton&) = delete; // copy assignment operator
    Singleton(Singleton&&) = delete; // move constructor
    Singleton& operator=(Singleton&&) = delete; // move assignment operator
};

int Singleton::instanceCount = 0;
Singleton* Singleton::instance = nullptr; // initialize static member

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    if(s1 == s2){
        cout<<"Both s1 and s2 point to the same instance."<<endl;
    } else {
        cout<<"s1 and s2 are different instances."<<endl;
    }

    cout<<"Instance count: "<<Singleton::getInstanceCount()<<endl;

    delete s1; // calling destructor
    cout<<"Instance count after deleting s1: "<<Singleton::getInstanceCount()<<endl;

    return 0;
}