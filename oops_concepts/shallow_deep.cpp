#include<iostream>
#include<string>
using namespace std;

class Vehicle{
    string brand;
    string model;
    string *data;
    static int objectCount;

    public:
    Vehicle(string b, string m, string message);
    //Vehicle(const Vehicle &v); // copy constructor
    ~Vehicle(){
        delete data; // free allocated memory
        objectCount--;
        cout<<"Destructor called for "<<brand<<endl;
    } // destructor 
    void display(){
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Data: "<<*data<<endl;
    }

    
    static int getObjectCount(){
        return objectCount;
    }
    Vehicle(const Vehicle &v); // deep copy constructor

};

int Vehicle::objectCount = 0;

Vehicle::Vehicle(string b, string m, string message) : brand{b}, model{m} {
    data = new string; // allocate memory
    *data = message;
    objectCount++;
    cout<<"Constructor called for "<<brand<<endl;
}

/*Vehicle::Vehicle(const Vehicle &v) {
    data = v.data; // allocate new memory and copy the data
    brand = v.brand;
    model = v.model;
    objectCount++;
    cout<<"Copy constructor called for "<<brand<<endl;
}
*/   

// Deep copy constructor
Vehicle::Vehicle(const Vehicle &v){
    data = new string(*v.data);
    brand = v.brand;
    model = v.model;
    objectCount++;
    cout<<"Deep copy constructor called for "<<brand<<endl;
}

int main(){
    Vehicle v1("Toyota", "Corolla", "This is a reliable car.");
    v1.display();
    Vehicle v2 = v1; // invokes copy constructor
    v2.display();
    cout<<"Total objects: "<<Vehicle::getObjectCount()<<endl;
    return 0;
}