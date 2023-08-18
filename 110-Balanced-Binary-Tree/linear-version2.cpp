#include "util/common.h"

// in this version I fix the weird h = -1 thing in version 1
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true; // empty tree w/ height 0 
        // so make height start at 1
        int h = 1;
        return dfs(root, h);
    }
private:
    bool dfs(TreeNode* root, int& h) {
        if(!root) {
            h = 0; // empty tree must have height 0
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
