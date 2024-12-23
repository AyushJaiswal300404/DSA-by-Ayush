#include<iostream>
using namespace std;
//Doubly Linked List
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

void print(Node* head){
    Node* temp =head;

    while(temp != NULL){
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* head){
    int len=0;
    Node* temp =head;

    while(temp != NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail, int d){
    if(head ==NULL){
        head = new Node(d);
        tail = new Node(d);
        return;
    }
    else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev=temp;
        head=temp;
    }
}
    

void insertAtTail(Node* &head,Node* &tail, int d){
    if(tail ==NULL){
        head = new Node(d);
        tail = new Node(d);
        return;
    }
    else{
        Node* temp = new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    if(position==1){
        insertAtHead(head,tail, d);
        return;
    }

    Node* temp = head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }

    //inserting at last position
    if(temp->next==NULL){
        insertAtTail(head,tail, d);
        return;
    }
    //cresaing a new node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;;
    nodeToInsert->prev=temp;
}
void deleteNode(int position, Node* &head){
    //delete at start 
    if(position==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
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

        curr->prev = NULL;
        prev->next= curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout<<"Length of linked list is: "<<getLength(head)<<endl;

    insertAtHead(head, tail,20);
    print(head);

    insertAtHead(head,tail, 30);
    print(head);

    insertAtTail(head,tail, 0);
    print(head);

    insertAtPosition(head, tail, 2, 40);
    print(head);

    deleteNode(1, head);
    print(head);

    deleteNode(3, head);
    print(head);

}