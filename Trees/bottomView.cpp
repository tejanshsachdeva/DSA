#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> bottomView(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            mpp[line] = node->data;

            if (node->left != nullptr) {
                q.push({node->left, line - 1});
            }
            if (node->right != nullptr) {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main() {
    // Create a sample tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    Solution solution;
    vector<int> result = solution.bottomView(root);

    // Print the bottom view of the tree
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // Clean up
    delete root->left->right->right->right;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
