#include "util/common.h"

// Note, we cuold just make min and max the integer value of the node, 
// but the problem is we're forced to use ints, so the input root can actually 
// be equal to INT_MAX, so it is impossible to check. If we could use long or floating point, 
// or anything else it would be ok.

// I.e. root = {INT_MAX, nullptr, nullptr} means the root->val >= max_val would fail

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return recurse(root, nullptr, nullptr);
    }

    bool recurse(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(!root) return true;
        if((max && root->val >= max->val) || 
           (min && root->val <= min->val))
            return false;
        return recurse(root->left, min, root) && recurse(root->right, root, max);
    }
};