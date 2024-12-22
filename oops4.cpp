#include <iostream>
using namespace std;
//Already studied- Single Inheritance, Multiple Inheritance, Multilevel Inheritance, Hierarchical Inheritance
// Inheritance Ambiguity
class A {
    public:
    void func(){
        cout<<"Function A"<<endl;
    }
};
class D {
    public:
    void func(){
        cout<<"Function D"<<endl;
    }
};


class C: public A, public D {
    
};

int main(){
    C obj1;
    //obj1.func(); //Error: Ambiguity
    obj1.A::func();
    return 0;
}