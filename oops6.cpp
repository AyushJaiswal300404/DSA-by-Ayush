#include<iostream>
#include<string>
using namespace std;
//PolyMorphism

class A{
    public:
        void func(){
            cout<<"Function A"<<endl;
        }
        void func(string str){
            cout<<"Function A "<< str <<endl;
        }
        int func(int a){
            return a;
        }
};
class B{
    public:
    int a;
    int b;

    public :
    int add(int a, int b){
        return a+b;
    }

    void operator+ (B obj){
        int val1 = this->a;
        int val2 = obj.a;
        cout<<val2-val1<<endl;
    }

};
   



int main(){
    //A obj1;
    //obj1.func();
    //obj1.func("Overloaded");
    //cout<<obj1.func(5)<<endl;
    B obj1;
    obj1.a = 10;
    B obj2;
    obj2.a = 20;
    obj1+obj2;
    return 0;
}