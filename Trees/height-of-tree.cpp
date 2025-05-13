#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // Function to calculate the height of a binary tree
    int height(Node* root) {
        if (root == NULL) {
            return 0; // Base case: height of an empty tree is 0
        }

        // Recursively calculate the height of left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Return the maximum of the two heights plus 1 for the current node
        return max(leftHeight, rightHeight) + 1;
    }
};

// Helper function to build a binary tree from an array representation
Node* buildTree(vector<int>& arr, int& index) {
    if (index >= arr.size() || arr[index] == -1) {
        index++;
        return NULL;
    }

    Node* root = new Node(arr[index++]);
    root->left = buildTree(arr, index);
    root->right = buildTree(arr, index);

    return root;
}

int main() {
    // Example 1
    vector<int> arr1 = {12, 8, 5, -1, -1, 11, -1, -1, 18, -1, -1};
    int index1 = 0;
    Node* root1 = buildTree(arr1, index1);

    Solution sol;
    cout << "Height of the tree: " << sol.height(root1) << endl; // Output: 2

    // Example 2
    vector<int> arr2 = {1, 2, 4, -1, -1, -1, 3, -1, 5, 6, -1, -1, 7, -1, -1};
    int index2 = 0;
    Node* root2 = buildTree(arr2, index2);

    cout << "Height of the tree: " << sol.height(root2) << endl; // Output: 3

    return 0;
}