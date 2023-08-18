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
    bool isBalanced(TreeNode* root) {
        int h = 0;
        return dfs(root, h);
    }
private:
    bool dfs(TreeNode* root, int& h) {
        if(!root) {
            h = -1; // we say empty tree has height -1 since we +1 later
            return true;
        }
        int l,r;
        if(dfs(root->left, l) && dfs(root->right, r) && abs(l - r) < 2) {
            h = 1 + max(l, r); // this updates l and r in call above
            return true; // we know it's balanced
        }
        return false;
    }
};