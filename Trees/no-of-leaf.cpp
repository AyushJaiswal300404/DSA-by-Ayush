#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};

node* buildTree(node * root){
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void inorder(node* root, int &count){
    if(root == NULL){
        return;
    }
    inorder(root->left, count);
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    inorder(root->right, count);
}
int main(){
    node* root = NULL;
    root = buildTree(root);
    int count = 0;
    inorder(root, count);
    cout<<"The number of leaf nodes in the tree is: "<<count<<endl;
    return 0;
}