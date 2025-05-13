#include <iostream>
#include <algorithm>
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
    // Helper function to calculate diameter and height
    pair<int, int> diameterFast(Node* root) {
        if (root == NULL) {
            // Base case: diameter = 0, height = 0
            return make_pair(0, 0);
        }

        // Recursive calls for left and right subtrees
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        // Calculate diameter options
        int op1 = left.first;  // Diameter of left subtree
        int op2 = right.first; // Diameter of right subtree
        int op3 = left.second + right.second + 1; // Diameter passing through root

        // Calculate the final diameter and height
        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3)); // Maximum diameter
        ans.second = max(left.second, right.second) + 1; // Height of the current node

        return ans;
    }

    // Function to calculate the diameter of the tree
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};

int main() {
    // Example tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    cout << "Diameter of the tree: " << sol.diameter(root) << endl;

    return 0;
}