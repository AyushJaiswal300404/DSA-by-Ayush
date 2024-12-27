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

Node* kReverse(Node* head, int k) {
    //base case
    if(head==NULL){
        return NULL;
    }
    //step1: reverse first k nodes
    Node* next = NULL;
    Node* curr= head;
    Node* prev=NULL;
    int count =0;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    //step2: recursion aage ka sambhallega
    if (next != NULL) {
        head->next = kReverse(next, k);
    }

    // step3: return head of reverse ll
    return prev;
}

bool isCircularList(Node* head){
    //empty list
    if(head==NULL){
        return true;
    }

    Node* temp=head->next;
    while(temp != NULL && temp!=head){
        temp=temp->next;
    }

    if(temp==head){
        return true;
    }else{
        return false;
    }
}

bool detectLoop(Node* head){
    if(head==NULL){
        return false;
    }
    map<Node*, bool> visited;
    Node* temp=head;
    while(temp!=NULL){
        if(visited[temp]){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

Node* floydDetectLoop(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    Node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

Node* removeLoop(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* start = getStartingNode(head);
    Node* temp = start;
    while(temp->next!= start){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail= node1;
    //print(head);
    insertAtHead(head, 5);
    insertAtHead(head, 15);
    insertAtHead(head, 25);
    /*print(head);
    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    print(head);
    Node* mid= getMiddle(head);
    cout<<mid->data<<endl;
    Node* head2 = kReverse(head, 2);
    print(head2);
    //Node* node3 = new Node(1);
    Node* head3 = NULL;
    cout<<isCircularList(head3)<<endl;
    */
    print(head);
    tail->next=head->next;
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    cout<<detectLoop(head)<<endl;
    cout<<floydDetectLoop(head)->data<<endl;
    cout<<getStartingNode(head)->data<<endl;
    removeLoop(head);
    cout<<detectLoop(head)<<endl;

    return 0;
}