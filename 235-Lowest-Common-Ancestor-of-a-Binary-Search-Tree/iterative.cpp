#include "util/common.h"

// Note this version is O(1) space

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* mn = p->val > q->val ? q : p;
        TreeNode* mx = p == mn ? q : p;
        while(root != mn && root != mx) {
            // if the root is in middle, then it must be LCA
            if(mx->val > root->val && root->val > mn->val) break;

            // at this point, LCA is in either left or right subtree, so recurse
            if(mx->val < root->val) root = root->left;
            else root = root->right;
        }
        return root;
    }
};
