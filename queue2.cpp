#include <iostream>
#include <queue>
using namespace std;
//Circular Queue

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    CircularQueue(int n){
        size=n;
        arr = new int[size];
        front=rear=-1;
    }

    bool push(int data){
        if((rear+1)%size==front){
            cout<<"Queue is full"<<endl;
            return false;
        }
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%size;
        arr[rear]=data;
        return true;
    }

    int pop(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int data = arr[front];
        if(front==rear){
            front=rear=-1;
        }else{
            front=(front+1)%size;
        }
        return data;
    }

    bool isempty(){
        return front==-1;
    }

    bool isfull(){
        return (rear+1)%size==front;
    }
};
// Doubly Ended Queue
class Deque{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    Deque(int n){
        size=n;
        arr = new int[size];
        front=rear=-1;
    }

    bool push_front(int data){
        if((rear+1)%size==front){
            cout<<"Queue is full"<<endl;
            return false;
        }
        if(front==-1){
            front=0;
        }
        front=(front-1+size)%size;
        arr[front]=data;
        return true;
    }

    bool push_back(int data){
        if((rear+1)%size==front){
            cout<<"Queue is full"<<endl;
            return false;
        }
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%size;
        arr[rear]=data;
        return true;
    }

    int pop_front(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int data = arr[front];
        if(front==rear){
            front=rear=-1;
        }else{
            front=(front+1)%size;
        }
        return data;
    }

    int pop_back(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int data = arr[rear];
        if(front==rear){
            front=rear=-1;
        }else{
            rear=(rear-1+size)%size;
        }
        return data;
    }

    bool isempty(){
        return front==-1;
    }

    bool isfull(){
        return (rear+1)%size==front;
    }
}; 
