#include<iostream>
using namespace std;
//Circular Linked List
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
    //destructor
    ~Node(){
        int value=this->data;
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for data "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element, int d ){
    //assuming that  the element is present in the list
    //empty list
    if(tail==NULL){
        Node* newNode = new Node(d);
        tail= newNode;
        newNode ->next = newNode;
    }
    //non empty list
    else{
        Node* curr=tail;
        while(curr->data!= element){
            curr=curr->next;
        }
        //element found and curr is representing element wala node
        Node* temp= new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
    
}
void print(Node* tail){
    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!= temp);
    cout <<endl;
}

void deleteNode(Node* &tail, int value){
    //empty list
    if(tail==NULL){
        return;
    }
    //non empty list
    else{
        Node* prev=tail;
        Node* curr= prev->next;
        while(curr->data != value){
            prev=curr;
            curr=curr->next;
        }
        prev->next = curr->next;
        //when 1 element is left
        if(curr==prev){
            tail=NULL;
        }
        //when 2 element are left
        else if(tail == curr){
            tail=prev;
        }
        curr->next = NULL;
        delete curr;
    }

}

int main(){
    Node* tail = NULL;
    insertNode(tail, 5, 3);
    print( tail);
    insertNode(tail, 3, 5); //find element 3 then add 5 after 3
    print(tail);
    deleteNode(tail, 3);
    print(tail);
    deleteNode(tail, 5);
    print(tail);

}

