#include<iostream>
#include<string>
using namespace std;

class Rectangle{
    int x, y;

    public:

    Rectangle(){}
    Rectangle(int l, int w): x{l}, y{w} {
        cout<<"rectangle object constructed!1"<<endl;
    }

    // copy constructor 
    Rectangle(const Rectangle& r){
        this->x = r.x;
        this->y = r.y;
    }

    friend Rectangle duplicate(const Rectangle& r);
    // copy assignment 

    Rectangle& operator=(const Rectangle& r){
        if(this!= &r){
            this->x = r.x;
            this->y = r.y;
         }
        return *this;

   }

  // move constructor 

    Rectangle(Rectangle&& r)
        : x{std::move(r.x)}, y{std::move(r.y)}
    {
        r.x = 0;
        r.y = 0;
        cout<<"move constructor called !!"<<endl;
    }

    // move assignment 

    Rectangle& operator=(Rectangle&& r){
        if(this!=&r){
            x = std::move(r.x);
            y = std::move(r.y);
       }
        r.x = 0;
        r.y = 0;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Rectangle& r){
        return os<<r.x<<" "<<r.y;

 }
    int getx() const{
        return this->x;
    }

    int gety() const{
        return this->y;
      }

};



Rectangle duplicate(const Rectangle& r){
    Rectangle r2;
    r2.x = r.x;
    r2.y = r.y;
    return r2;
}

int main(){
    Rectangle r{12, 14};
    Rectangle r3 = duplicate(r);
    cout<<"length of rectnagle r3 is : "<<r3.getx()<<" "<<"breadth : "<<r3.gety()<<endl;
    return 0;
 }
