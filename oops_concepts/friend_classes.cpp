#include<iostream>
using namespace std;


class A{
    int x;

    friend class B;

    public:
    A(int n): x{n} {}
    void display(){
        cout<<"x : "<<x<<endl;
    }
 };

class B{
    int z;

    public:
  //  A obj2(46);
    B(int m): z{m} {}
    void revealAclass(A& obj){
        obj.display();
        cout<<"private member of the class A: "<<obj.x<<endl;
      }
    
    void show(){
        cout<<"z "<<z<<endl;
        cout<<" ** "<<endl;
    }
};

int main(){
    A a1(34);
    B b1(45);
    b1.revealAclass(a1);
    b1.show();
    return 0;
 }
