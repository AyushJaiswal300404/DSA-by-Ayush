#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition of the Node class
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
    vector<vector<int>> verticalOrder(Node* root) {
        // Map to store nodes by horizontal distance and level
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q; // Queue for level-order traversal
        vector<vector<int>> ans; // Correct return type

        if (root == NULL) {
            return ans; // Return empty vector if root is NULL
        }

        q.push(make_pair(root, make_pair(0, 0))); // Push root with horizontal distance 0 and level 0

        while (!q.empty()) {
            pair<Node*, pair<int, int>> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second.first; // Horizontal distance
            int lvl = temp.second.second; // Level

            // Store the node's data in the map
            nodes[hd][lvl].push_back(frontNode->data);

            // Push left child with updated horizontal distance and level
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            }

            // Push right child with updated horizontal distance and level
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            }
        }

        // Traverse the map and prepare the result
        for (auto i : nodes) {
            vector<int> col; // Temporary vector for each vertical column
            for (auto j : i.second) {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col); // Add the column to the result
        }

        return ans;
    }
};

// Helper function to build a binary tree
Node* buildTree() {
    int data;
    cout << "Enter data (-1 for NULL): ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);
    cout << "Enter left child of " << data << endl;
    root->left = buildTree();
    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}

// Main function
int main() {
    Solution sol;

    cout << "Build the binary tree:" << endl;
    Node* root = buildTree();

    vector<vector<int>> result = sol.verticalOrder(root);

    cout << "Vertical Order Traversal:" << endl;
    for (auto col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}