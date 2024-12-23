#include <iostream>
using namespace std;
//Already studied- Single Inheritance, Multiple Inheritance, Multilevel Inheritance, Hierarchical Inheritance
//Hybrid Inheritance
class A {
    public:
    void funcA(){
        cout<<"Function A"<<endl;
    }
};
class D {
    public:
    void funcD(){
        cout<<"Function D"<<endl;
    }
};

class B: public A {
    public:
    void funcB(){
        cout<<"Function B"<<endl;
    }
};

class C: public A, public D {
    public:
    void funcC(){
        cout<<"Function C"<<endl;
    }
};

int main(){
    B obj1;
    obj1.funcA();
    obj1.funcB();
    C obj2;
    obj2.funcA();
    obj2.funcD();
    obj2.funcC();
    return 0;
}