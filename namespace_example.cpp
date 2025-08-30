#include<iostream>
using namespace std;

namespace utilility_fun{
    void fun(){
        std::cout<<"this is utility fun"<<endl;
    }
    
    int square(int x){
        return x*x;
    }
}


namespace random_ex{
    int square(int x){
        return x*x;
    }
}
int main(){
    int n = 9;
    cout<<"Square of : "<<n<<" is :"<<utilility_fun::square(n)<<std::endl; // calling of function directly without any object 
    cout<<"Square of : "<<n<<" is :"<<random_ex::square(n)<<std::endl;
    return 0;
}
