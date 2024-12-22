#include<iostream>
#include<cstring>
using namespace std;

class Human{
    public:
        string name;
        int age;
        int height;
        int weight;
    
    public:
    int getAge(){
        return this->age;
    }
    void setWeight(int weight){
        this->weight = weight;
    }
       

};

class Male: public Human{
    public:
        string color;

        void sleep(){
            cout<<"Male Sleeping"<<endl;
        }
    
};

int main(){
    //Human s;
    //cout<<s.getAge()<<endl;
    //return 0;

    Male obj1;
    cout<<obj1.age<<endl;
    cout<<obj1.getAge()<<endl;
    obj1.sleep();
    obj1.setWeight(50);
    cout<<obj1.weight<<endl;

}
    
