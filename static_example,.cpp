#include<iostream>
using namespace std;

class shape{
    public:
    shape() {}
    static int count;
    virtual void shape_type(){
        cout<<"this is shape type "<<endl;
    }
    virtual ~shape(){
        cout<<endl<<"destructor called"<<endl;
    }
};

int shape::count = 0;

class rectangle: public shape{
    public:
    int length;
    int breadth;
    rectangle(int l, int b): shape(), length{l}, breadth{b} {
        cout<<"constructor created :"<<endl;
        count++;
    }
    void shape_type(){
        cout<<"this is rectangle shape type"<<endl;
    }
    int area(){
        return length * breadth;
    }
};

int main(){
    rectangle r1{10, 20};
    r1.shape_type();
    cout<<endl<<r1.area()<<endl;
    rectangle r2{10, 20};
    rectangle r3{10, 20};
    rectangle r4{10, 20};
    cout<<shape::count<<endl;
    return 0;
    
}
