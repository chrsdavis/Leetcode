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

// runs O(nlogn), could be better w/ memoization
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(height(root->left) - height(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int height(TreeNode* root) {
        int h = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int h1 = q.front().second;
            q.pop();
            if (!node) continue;
            q.push({node->left, h1 + 1});
            q.push({node->right, h1 + 1});
            h = max(h, h1);
        }
        return h;
    }
};