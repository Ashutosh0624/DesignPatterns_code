#include<iostream>
#include<string>
using namespace std;

class Vehicle{
    string brand;
    string model;
    string engine_type;
    static int objectCount;
    int price;
    string *engine_data;

    public:
    //  Rule of 5 : copy constructor, move constructor , copy assignment operator, move assignment operator , destructor.
    
    // constructor 
    Vehicle(string b, string m, string eType, int p, string message)
        : brand{b},
          model{m},
          engine_type{eType},
          price{p},
          engine_data{new string{message}}
    {
        cout<<"Vehicle object created"<<endl;
        objectCount++;
    }

    // copy conastructor for deep copy 
    Vehicle(const Vehicle& v)
        : brand{v.brand},
          model{v.model},
          engine_type{v.engine_type},
          price{v.price},
          engine_data{new string{*v.engine_data}}  // deep copy 
    {
        cout<<"Copy constructr with deep copy created "<<endl;
        objectCount++;
    }

    // copy assignment 

    Vehicle& operator=(const Vehicle& other){
        if(this != &other){
            brand = other.brand;
            model = other.model;
            engine_type = other.engine_type;
            price = other.price;
            // this is important to avoid memory leak
            // this is doing shallow copy 
            //engine_data = other.engine_data;
            string *ptr = new string(*other.engine_data);
            delete engine_data; // free the existing memory 
            engine_data = ptr;
            //engine_data = new string(*other.engine_data); // deep copy
         }
            return *this;
    }


   // move constructor 

    Vehicle(Vehicle&& other) noexcept
       :brand(std::move(other.brand)),
        model(std::move(other.model)),
        engine_type (std::move(other.engine_type)),
        price(std::move(other.price)),
        engine_data(std::move(other.engine_data))
        {
            other.price = 0;
            other.engine_data = nullptr;
     }
     
    Vehicle& operator=(Vehicle&& other){
        if(this != &other){
            brand = std::move(other.brand);
            engine_type = std::move(other.engine_type);
            price = other.price;

            delete other.engine_data;
            engine_data = std::move(other.engine_data);
            other.price = 0;
            other.engine_data = nullptr;
            
            
}
        return *this;
    }

};

int Vehicle::objectCount = 0;

int main(){
    Vehicle v1("Toyota", "Corolla", "V4", 20000, "Engine data for V1");
    Vehicle v2 = v1; // invokes copy constructor
    Vehicle v3 = std::move(v1); // invokes move constructor

    return 0;
}
