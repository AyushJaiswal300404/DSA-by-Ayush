#include<iostream>
#include<cstring>
using namespace std;

class Hero{
    //properties
    
    private:
    int health;

    public:
    char *name; //name[100]
    static int timetoComplete; //static member variable

    static int random(){
        return 5;
    }
    //constructor
    Hero(){
        cout<<"Constructor called"<<endl;
        name= new char[100];
    }
    /// parameterized constructor
    Hero(int health){
        cout<<"this= "<<this<<endl;
        this ->health= health;

    }
    void print(){
        cout<<"health "<<this->health<<endl;
        cout<<"name "<<this->name<<endl;
    }
    //copy constructor
    Hero(Hero &temp){
        //deep copy
        char* ch = new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;

        cout<<"copy constructor called"<<endl;
        this->health=temp.health;
    }
    char level;
    //getter
    int getHealth(){
        return health;
    }
    //setter 
    void setHealth(int h){
        health = h;
    }

    void setName(char *n){
        strcpy(this->name,name);
    }

    //destructor
    ~Hero(){
        cout<<"Destructor called"<<endl;
        delete [] name;
    }

};

int Hero::timetoComplete = 5;

int main(){
    //object is an entity which has some properties and behaviour
    //object is an instance of a class
    //class is a user defined datatype
    //class is a blueprint of an object
    /*
    Hero harry;
    harry.setHealth(100);
    harry.level ='A';
    cout<< "size " << sizeof(harry) << endl; //in case of object based on empty class, size is 1 byte
    cout<< "level "<< harry.level <<endl;
    cout<< "health "<< harry.getHealth() <<endl;

    */

    // Hero a;
   //  cout<< "level"<< a.level <<endl;
    
   //  Hero *b = new Hero;
    // b->setHealth(80);
    //cout<< "level "<<(*b).getHealth()<<endl;
 //    cout<< "level "<< b->getHealth()<<endl;
  //   Hero zayn(80);
  //   cout<<"address of zayn= "<<&zayn<<endl;

    /*Hero liam(70);
    liam.print();
    Hero niall(liam);
    niall.print();
    */

   //Hero S(70);
   //S.print();

   //copy constructor(but it stores shallow copy)
   //Hero R(S);

  

   

    //copy assignment operator
    /*
    Hero h1;
    h1.setHealth(12);
    char name[6] ="Harry";
    h1.setName(name);
    //h1.print();
    Hero h2;
    h2.print();
    h2=h1;
    h2.print();
    */

   //for static object, destructor is called when the object goes out of scope automatically
   //for dynamic object, destructor is called when we delete the object
   Hero a;
   Hero *h = new Hero();
   delete h;

   cout<<Hero::timetoComplete<<endl;
    cout<<Hero::random()<<endl;
   return 0;
   


}