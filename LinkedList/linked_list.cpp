#include<iostream>
using namespace std;
//Singly Linked List
class Node{
    public:
    int data;
    Node* next; // pointer to the next node

    //constructor
    Node (int data){
        this->data=data;
        this->next=NULL;
    }

    //destructor
    ~Node(){
        int value =this->data;
        if(this->data != 0){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for data "<<value<<endl;

    }
};

void insertAtHead(Node* &head, int d){
    //new node create
    Node* temp= new Node(d);

    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail, int d){
    //new node create
    Node* temp= new Node(d);

    tail->next=temp;
    tail= tail->next;
}

void insertAtPosition(Node* &head,Node* &tail,int position, int d){
    //insert at start
    if(position==1){
        insertAtHead(head, d);
        return;
    }
   
    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    //insert at end
    if(temp->next == NULL){
        insertAtTail(temp, d);
        return;
    }

    //create a new node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;


}

void print(Node* &head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;

}

void deleteNode(int position, Node* &head){
    //delete at start 
    if(position==1){
        Node* temp=head;
        head=head->next;
        //memory free start node
        temp->next=NULL;
        delete temp;
        return;
    }
    else{
        //deleting any node at middle or end
        Node* curr = head;
        Node* prev = NULL;

        int count=1;
        while(count < position){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next= curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    Node *node1 = new Node(10);
    //cout<< node1->data <<endl;
    //cout<<node1->next<<endl;

    //head and tail point to node 1
    Node* head=node1;
    Node* tail=node1;
    print(head);

    insertAtHead(head, 5);
    print(head);

    //insertAtHead(head, 15);
    //print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(head,tail, 2, 20);
    print(head);
    cout<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl;
    deleteNode(1,head);
    print(head);
    cout<<"tail: "<<tail->data<<endl;
    deleteNode(3,head);
    print(head);
    cout<<"tail: "<<tail->data<<endl;


}
