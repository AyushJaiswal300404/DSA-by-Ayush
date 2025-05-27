#include<iostream>
#include<queue>
using namespace std;
//Queue is a FIFO data structure
//delete from front and insert at rear

class Queue{
    int* arr;
    int front;
    int rear;
    int size;

  public:
    Queue(){
        size=10001;
        arr = new int[size];
        front=0;
        rear=0;
    }

    bool isempty(){
        return front==rear;
    }

    bool isfull(){
        return rear==size;
    }

    void push(int data){
        if(isfull()){
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[rear]=data;
        rear++;
    }

    int pop(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            int data = arr[front];
            arr[front]=-1;
            front++;
            if(front==rear){
                front=0;
                rear=0;
            }
            return data;
        } 
    }

    int front(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            return arr[front];
        }
    }

};

int main(){
    /*
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    return 0;
    */
    
}