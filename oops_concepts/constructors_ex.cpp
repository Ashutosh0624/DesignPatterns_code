#include<iostream>
#include<string>
using namespace std;


class Vehicle{
    string brand;
    string model;
    int price;

    public:
    Vehicle(string b, string m, int p);

    //copy constructor 
    Vehicle(const Vehicle &v);

    // move cosntructor
    Vehicle(Vehicle && v);
    
    ~Vehicle(){
        cout<<"Destructor called"<<endl;
    }

    void display();
};


Vehicle::Vehicle(string b, string m, int p): brand{b}, model{m}, price{p} {
    cout<<"Constructor called"<<endl;
}

Vehicle::Vehicle(Vehicle &&v) : brand{std::move(v.brand)}, model{std::move(v.model)}, price{std::move(v.price)} {
    cout<<"Move constructor called"<<endl;
}

Vehicle::Vehicle(const Vehicle &v) : brand{v.brand}, model{v.model}, price{v.price} {
    cout<<"Copy constructor called"<<endl;
}

void Vehicle::display(){
    cout<<"Brand: "<<brand<<endl;
    cout<<"Model: "<<model<<endl;
    cout<<"Price: "<<price<<endl;
}

int main(){
    Vehicle *v1 = new Vehicle("Toyota", "Corolla", 20000);
    v1->display();
    Vehicle v2 = std::move(*v1); // invoking move constructor
    v2.display();
    delete v1; // free the memory allocated for v1
    return 0;
}