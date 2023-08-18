#include "util/common.h"

class Solution {
private:
    int answer;
public:
    int kthSmallest(TreeNode* root, int& k) {
        if(!root) return 0;
        int x = kthSmallest(root->left, k);
        return k == 0 ? 
            x : k == 1 ? 
                root->val : kthSmallest(root->right, k);
    }
};