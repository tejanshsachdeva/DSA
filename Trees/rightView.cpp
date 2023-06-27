#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void recursion(TreeNode *root, int level, std::vector<int> &res) {
        if (root == nullptr)
            return;
        if (res.size() == level)
            res.push_back(root->val);
        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }

    std::vector<int> rightSideView(TreeNode *root) {
        std::vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};
