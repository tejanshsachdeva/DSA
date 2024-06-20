#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node* left, * right;
};

bool isLeaf(node* root) {
    return (root->left == nullptr && root->right == nullptr);
}

void addLeftBoundary(node* root, vector<int>& res) {
    node* curr = root->left;

    while (curr) {
        if (!isLeaf(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addRightBoundary(node* root, vector<int>& res) {
    vector<int> temp;
    node* curr = root->right;

    while (curr) {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

void addLeaves(node* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->data);  //agar root hi leaf hai toh add kr and nikal
        return;
    }

    if (root->left)
        addLeaves(root->left, res);

    if (root->right)
        addLeaves(root->right, res);
}

vector<int> printBoundary(node* root) {
    vector<int> res;
    if (!root) return res;

    if (!isLeaf(root)) res.push_back(root->data);

    addLeftBoundary(root, res);

    // add leaf nodes
    addLeaves(root, res);

    addRightBoundary(root, res);
    return res;
}

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main() {

    struct node* root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(3);
    root->left->left->right = newNode(4);
    root->left->left->right->left = newNode(5);
    root->left->left->right->right = newNode(6);
    root->right = newNode(7);
    root->right->right = newNode(8);
    root->right->right->left = newNode(9);
    root->right->right->left->left = newNode(10);
    root->right->right->left->right = newNode(11);

    vector<int> boundaryTraversal;
    boundaryTraversal = printBoundary(root);

    cout << "The Boundary Traversal is : ";
    for (int i = 0; i < boundaryTraversal.size(); i++) {
        cout << boundaryTraversal[i] << " ";
    }
    return 0;
}
