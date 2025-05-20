#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* &root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d>root->data){
        root->right = insertIntoBST(root->right, d);
    }else{
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        insertIntoBST(root, data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
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

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void searchInBST(Node* root, int key){
    if(root == NULL){
        cout<<"Key not found"<<endl;
        return;
    }
    if(root->data == key){
        cout<<"Key found: "<<key<<endl;
        return;
    }
    if(key > root->data){
        searchInBST(root->right, key);
    }else{
        searchInBST(root->left, key);
    }
}

Node* minVal(Node* root){
    if(root == NULL){
        return NULL;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromNode(Node* root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->data == val){
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromNode(root->right, mini);
            return root;
        }
    }
    else if(val < root->data){
        root->left = deleteFromNode(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromNode(root->right, val);
        return root;
    }
    return root;
}

int main(){
    Node* root=NULL;
    cout<<"Enter data to create BST: ";
    takeInput(root);
    cout<<"Level Order Traversal of BST: "<<endl;
    levelOrderTraversal(root);
    cout<<"Inorder Traversal of BST: "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal of BST: "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal of BST: "<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Enter key to search in BST: ";
    int key;
    cin>>key;
    searchInBST(root, key);
    cout<<"Minimum value in BST: "<<minVal(root)->data<<endl;
    cout<<"Maximum value in BST: "<<maxVal(root)->data<<endl;
    cout<<"Enter value to delete from BST: ";
    int val;
    cin>>val;
    root = deleteFromNode(root, val);
    cout<<"Level Order Traversal after deletion: "<<endl;
    levelOrderTraversal(root);
    cout<<"Inorder Traversal after deletion: "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal after deletion: "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal after deletion: "<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}