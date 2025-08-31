#include<iostream>
#include<string>
using namespace std;


class Vehicle{
    string brand;
    string model;
    int price; 
    static int countVehicle;

    public:
    Vehicle(string b, string m, int p)
        : brand{b}, model{m}, price{p}
    {
        cout<<"Vehicle object created!"<<endl;
        ++countVehicle;
    }

    // Rule of 5 
    
    // copy constructor 
    Vehicle(const Vehicle& v){
        this->brand = v.brand;
        this->model = v.model;
        this->price = v.price;
    }

    // move constructor 

    Vehicle(Vehicle&& v)
        : brand{std::move(v.brand)},
          model{std::move(v.model)},
          price{std::move(v.price)}
     {
        v.price = 0;
        cout<<"move constructor called !!"<<endl;
     }


     // copy assignment 

     Vehicle& operator=(const Vehicle& v){
     if(this!= &v){
        this->brand = v.brand;
        this->model = v.model;
        this->price = v.price;
     }
        return *this;
     }

     // move assignment

     Vehicle& operator=(Vehicle&& v){
     if(this!=&v){
         brand = std::move(v.brand);
         model = std::move(v.model);
         price = std::move(v.price);
         v.price = 0;
     }  
         return *this;
  }
     // Destructor 

    ~Vehicle(){
        cout<<"Destructor called : "<<endl;
     }
    
     // Methods of this class 
     void showVehicleDetails() const{
         cout<<"Model : "<<this->model<<endl;
         cout<<"Brand : "<<this->brand<<endl;
         cout<<"price of the vehicle :"<<this->price<<endl;
     } 

     void setVehicleDetails(string n, string modeln, int np){
         this->brand = n;
         this->model = modeln;
         this->price = np;
      }

      static int getVehicleCount(){
          return countVehicle;
      }
 };

class Toyota: public Vehicle{
    bool fourGears;
    bool mESIV;

    public:
    Toyota(string brand, string model, int price, bool fourGears, bool mESIV)
        : Vehicle(brand, model, price),
          fourGears{fourGears}, mESIV{mESIV}
    {
       // Vehicle::countVehicle += 1;
        cout<<"Toyota class constructor called!"<<endl;

    }

    void getToyotaDetails()const{
        showVehicleDetails();
        if(fourGears){
            cout<<"modern vehicle "<<endl;
          }
        else{
            cout<<"old model "<<endl;
        }
    }
 };

int Vehicle::countVehicle = 0;

int main(){
    Toyota *t1 = new Toyota{"Toyota", "Elantra", 20000, true, true};
    Toyota *t2 = new Toyota{"Toyota", "Fortuner", 30000, true, false};
    cout<<"total vehicle count : "<<Toyota::getVehicleCount()<<endl;


    return 0;

 }
