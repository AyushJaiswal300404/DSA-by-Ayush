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

void insertAtTail(Node* &head,Node* &tail, int d){
    Node* temp= new Node(d);
    if(head==NULL){
        head= temp;
        tail= temp;
        return;
    }else{
        tail->next=temp;
        tail= tail->next;

    }  
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

Node* add(Node* first, Node* second){
    Node* ansHead= NULL;
    Node* ansTail= NULL;
    int carry=0;
    while(first!=NULL && second!=NULL){
        int sum= first->data + second->data + carry;
        int digit= sum%10;
        Node* temp= new Node(digit);
        //create node and add in answer linked list
        insertAtTail(ansHead,ansTail, digit);
        
        carry= sum/10;
        first=first->next;
        second=second->next;
    }
    while(first!=NULL){
            int sum= first->data + carry;
            int digit= sum%10;
            insertAtTail(ansHead,ansTail, digit);
            carry= sum/10;
            first=first->next;
    }
    while(second!=NULL){
            int sum= second->data + carry;
            int digit= sum%10;
            insertAtTail(ansHead,ansTail, digit);
            carry= sum/10;
            second=second->next;
    }
    if(carry!=0){
            insertAtTail(ansHead,ansTail, carry);
    }

    
    return ansHead;
}

Node* addTwoLists(Node* first, Node* second){
    //reverse both lists
    first= reverse(first);
    second= reverse(second);

    //add two lists
    Node* ans= add(first, second); 
    //reverse the ans
    ans=reverse(ans);
    return ans;
}

int main(){
    /*Node* head = NULL;
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
    */
    Node* head1 = NULL;
    insertAtHead(head1, 1);
    insertAtHead(head1, 2);
    insertAtHead(head1, 3);
    insertAtHead(head1, 4);
    print(head1);

    Node* head2 = NULL;
    insertAtHead(head2, 1);
    insertAtHead(head2, 2);
    print(head2);

    Node* ans = addTwoLists(head1, head2);
    print(ans);
    return 0;
}