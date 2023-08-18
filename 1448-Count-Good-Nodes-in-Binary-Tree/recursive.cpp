#include "util/common.h"

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        // if(!root) return 0;
        recurse(root, root->val, count);
        return count;
    }

    void recurse(TreeNode* root, int path_max, int& count) {
        if(!root) return;
        path_max = max(root->val, path_max);
        if(root->val >= path_max) count++;
        recurse(root->left, path_max, count);
        recurse(root->right, path_max, count);
    }
};
