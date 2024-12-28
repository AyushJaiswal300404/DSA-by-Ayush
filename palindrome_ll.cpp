#include<iostream>
#include<map>
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

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast= head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* reverse(Node* head){
    Node* curr= head;
    Node* prev=NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr = next;
    }
    return prev;

}

bool isPalindrome(Node* head){
    //if no or one element then palindrome
    if(head == NULL || head->next==NULL){
        return true;
    }
    //s1: find middle
    Node* middle = getMid(head);
    //s2: reverse ll after middle
    Node* temp = middle->next;
    middle->next= reverse(temp);
    //s3: compare both halves
    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2 != NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }

    //repeat s2
    middle->next=reverse(middle->next);

    return true;
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    cout<<isPalindrome(head)<<endl;
    print(head);
    //delete head;
    return 0;
}