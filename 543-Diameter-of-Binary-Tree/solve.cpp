#include "util/common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        d = 0;
        helper(root);
        return d;
    }
private:
    int d = 0; // diameter

    int helper(TreeNode* root) {
        if(!root) return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        d = max(d, l + r);
        return 1 + max(l,r);
    }
};

// Note that diameter is just max of left subtree height + right subtree height