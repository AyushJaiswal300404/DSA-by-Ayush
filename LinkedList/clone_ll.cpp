#include <iostream>
#include <unordered_map>
using namespace std;
//some issue in the code
class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int d) {
        data = d;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        // ISSUE 1: No null check for newNode allocation
        // ISSUE 2: Memory leak possible if allocation fails
        
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            // ISSUE 3: No return needed here, fall through is fine
            return;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node* cloneLinkedList(Node* head) {
        // ISSUE 4: No null check for input head
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        
        // ISSUE 5: No error handling for map allocation
        unordered_map<Node*, Node*> oldToNew;
        
        Node* original = head;
        Node* clone = cloneHead;
        while(original != NULL) {
            oldToNew[original] = clone;
            original = original->next;
            clone = clone->next;
        }
        
        original = head;
        clone = cloneHead;
        while(original != NULL) {
            // ISSUE 6: No null check for original->random
            clone->random = oldToNew[original->random];
            original = original->next;
            clone = clone->next;
        }
        // ISSUE 7: Returns clone instead of cloneHead
        return clone;  // Should return cloneHead
    }
};
void printList(Node* head, string listName) {
    cout << "\n" << listName << ":" << endl;
    if(head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node* temp = head;
    while(temp != NULL) {
        cout << "Node " << temp->data;
        if(temp->random != NULL) {
            cout << " (Random -> " << temp->random->data << ")";
        }
        cout << endl;
        temp = temp->next;
    }
}

int main(){
    // Create original linked list
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    // Connect next pointers
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Connect random pointers
    head->random = third;      // 1 points to 3
    second->random = fourth;   // 2 points to 4
    third->random = second;    // 3 points to 2
    fourth->random = head;     // 4 points to 1

    // Print original list
   printList(head, "Original List");
   Solution solution;
    Node* cloneHead = solution.cloneLinkedList(head);
    printList(cloneHead, "Cloned List");


    return 0;

}