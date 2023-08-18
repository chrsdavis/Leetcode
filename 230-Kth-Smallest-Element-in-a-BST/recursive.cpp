#include "util/common.h"

class Solution {
private:
    int answer;
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        recurse(root, k, count);
        return answer;
    }

    void recurse(TreeNode* root, int k, int& c) {
        // in order traversal
        if(!root || c >= k) return;
        recurse(root->left, k, c);
        if(++c == k) {
            answer = root->val;
            return;
        }
        recurse(root->right, k, c);
    }
};