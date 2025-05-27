#include<iostream>
#include<cstring>
using namespace std;
//Run Time Polymorphism or Dynamic Polymorphism
class Animal{
    public:
    void speak(){
        cout<<"Animal Speaking"<<endl;
    }
};

class Dog: public Animal{
    public:
    void speak(){
        cout<<"Dog Barking"<<endl;
    }
};

int main(){
    Dog d;
    d.speak();
    return 0;
}