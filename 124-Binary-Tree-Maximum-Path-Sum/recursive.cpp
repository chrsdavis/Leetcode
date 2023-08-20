#include "util/common.h"

class Solution {
private:
    int max_sum;
public:
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        recurse(root);
        return max_sum;
    }
    int recurse(TreeNode* root) {
        if(!root) return 0; // base case
        int left_sum = max(recurse(root->left), 0); // find largest left and right paths
        int right_sum = max(recurse(root->right), 0);
        int subtree_sum = left_sum + right_sum + root->val;
        max_sum = max(subtree_sum, max_sum); // if we use this subtree as whole path, update max
        return root->val + max(left_sum, right_sum); // only use single path, not whole subtree
    }
};
