#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }

    ~Node(){
        int val= this->data;
        if(next != NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory is free for data "<<val<<endl;
    }
};

void insertAtHead(Node* &head, int d){
    //new node create
    Node* temp= new Node(d);

    temp->next=head;
    head=temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;

}

void reverse(Node* &head, Node* curr, Node* prev){
    //base case
    if(curr==NULL){
        head=prev;
        return;
    }
    //recursive case
    Node* forward=curr->next;
    reverse(head, forward, curr);
    curr->next=prev;
}

int getLength(Node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;

}
    return len;
}

Node* getMiddle(Node* head){
    if(head == NULL || head->next==NULL){
        return head;
    }
    //2 nodes
    if(head->next->next==NULL){
        return head->next;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL){
        fast= fast->next;
        if(fast!=NULL){
            fast=fast->next; 
        }
        slow=slow->next;
    }
    return slow;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    print(head);
    insertAtHead(head, 5);
    insertAtHead(head, 15);
    insertAtHead(head, 25);
    print(head);
    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    print(head);
    Node* mid= getMiddle(head);
    cout<<mid->data<<endl;
    return 0;
}