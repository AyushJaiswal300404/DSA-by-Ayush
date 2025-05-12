#include <iostream>
#include <queue>
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


void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void buildFromLevelOrder(node* &root){
    queue <node*> q;
    cout<<"Enter the data for root node"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<"Enter the data for left of "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter the data for right of "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }

    }
}


void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    // node* root = NULL;
    // root = buildTree(root);
    // cout<<"Printing the level order traversal of the tree"<<endl;
    // levelOrderTraversal(root);
    // cout<<"Done"<<endl;
    // cout<<"Printing the inorder traversal of the tree"<<endl;
    // inorder(root);
    // cout<<endl;
    // cout<<"Printing the preorder traversal of the tree"<<endl;
    // preorder(root);
    // cout<<endl;
    // cout<<"Printing the postorder traversal of the tree"<<endl;
    // postorder(root);
    // cout<<endl;
    node* root = NULL;
    buildFromLevelOrder(root);
    cout<<"Printing the level order traversal of the tree"<<endl;
    levelOrderTraversal(root);
    return 0;
}