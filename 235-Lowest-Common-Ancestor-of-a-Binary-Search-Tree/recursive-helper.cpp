#include "util/common.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* mn = p->val > q->val ? q : p;
        TreeNode* mx = p == mn ? q : p;
        return helper(root, mn, mx);
    }

    TreeNode* helper(TreeNode* root, TreeNode* mn, TreeNode* mx) {
        if(!root) return nullptr;
        if(root == mn || root == mx) return root;
        // if the root is in middle, then it must be LCA
        if(mx->val > root->val && root->val > mn->val) return root;

        // at this point, LCA is in either left or right subtree, so recurse
        if(mx->val < root->val) return helper(root->left, mn, mx);
        else return helper(root->right, mn, mx);
    }
};
