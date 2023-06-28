#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if (root == NULL || root == p || root == q) {  //if root is null or if root is either p or q, return root
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);  //recursively call left and right
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //result
        if (left == NULL) {
            return right;
        }
        else if (right == NULL) {
            return left;
        }
        else {                      //both left and right are not null, we found our result
            return root;
        }
};

int main() {
    // Create a binary tree for testing
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution solution;

    // Test case 1
    TreeNode* p1 = root->left;
    TreeNode* q1 = root->right;
    TreeNode* lca1 = solution.lowestCommonAncestor(root, p1, q1);
    std::cout << "LCA of " << p1->val << " and " << q1->val << " is: " << lca1->val << std::endl;

    // Test case 2
    TreeNode* p2 = root->left;
    TreeNode* q2 = root->left->right->right;
    TreeNode* lca2 = solution.lowestCommonAncestor(root, p2, q2);
    std::cout << "LCA of " << p2->val << " and " << q2->val << " is: " << lca2->val << std::endl;

    // Test case 3
    TreeNode* p3 = root->left->right;
    TreeNode* q3 = root->left->right->left;
    TreeNode* lca3 = solution.lowestCommonAncestor(root, p3, q3);
    std::cout << "LCA of " << p3->val << " and " << q3->val << " is: " << lca3->val << std::endl;

    // Cleanup: delete the dynamically allocated tree nodes
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
