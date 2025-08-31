#include<iostream>
#include<string>
using namespace std;

class Complex{
    int real;
    float imag;
    static int objectCount;

    public:
    Complex():real(0),imag(0.0){
        objectCount++;  
    }

    // copy constructor 
    Complex( const Complex &c){
        real = c.real;
        imag = c.imag;
        objectCount++;
    }

    // move constructor 
    Complex( Complex &&c) noexcept {
        real = c.real;
        imag = c.imag;
        objectCount++;
        c.real = 0;
        c.imag = 0.0;
    }
    
    ~Complex(){
        objectCount--;
    }
    // copy assignment operator
    Complex& operator=( const Complex &c){
        if(this != &c){
            real = c.real;
            imag = c.imag;      
        }
        return *this;
    }
    
    // move assignment operator
    Complex& operator=( Complex &&c) noexcept {
        if(this != &c){
            real = c.real;
            imag = c.imag;  
            c.real=0;
            c.imag=0.0;
        }
        return *this;
    }

    // operator overloading for +
    Complex operator+( const Complex &c) const {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // operator overloading for <<
    friend ostream& operator<<(ostream &out, const Complex &c){
        out << c.real << " + " << c.imag << "i";
        return out;     
    }

    static int getObjectCount(){
        return objectCount;
    }
    
};

int Complex::objectCount = 0;

int main(){
    Complex c1; // default constructor
    Complex c2; // default constructor
    Complex c3 = c1; // copy constructor
    Complex c4 = std::move(c2); // move constructor

    c1 = c3; // copy assignment operator
    c2 = std::move(c4); // move assignment operator

    Complex c5 = c1 + c2; // operator +

    cout << "c1: " << c1 << endl; // operator <<
    cout << "c2: " << c2 << endl; // operator <<
    cout << "c5: " << c5 << endl; // operator <<

    cout << "Total Complex objects created: " << Complex::getObjectCount() << endl;

    return 0;
    }   