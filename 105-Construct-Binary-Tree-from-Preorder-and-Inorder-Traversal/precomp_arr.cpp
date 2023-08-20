#include "util/common.h"

class Solution {
private:
    // could use unordered_map<int, int> instead
    // Note keys go from -3000 -> 3000, so we will just add
    // 3000 so the range becomes 0 -> 6000
    int inorder_idx_table[3000 * 2 + 1] = {0};
    static constexpr int offset = 3000;
    int preorder_idx; // to loop through preorder

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_idx = 0;
        // precalculate inorder order of each key
        for(int i = 0; i < inorder.size(); i++)
            inorder_idx_table[offset + inorder[i]] = i;
        return recurse(preorder, 0, preorder.size() - 1);
    }

    TreeNode* recurse(vector<int>& preorder, int start_idx, int end_idx) {
        if(start_idx > end_idx) return nullptr;
        TreeNode* root = new TreeNode(preorder[preorder_idx++]);
        int root_idx_inorder = inorder_idx_table[offset + root->val];
        root->left = recurse(preorder, start_idx, root_idx_inorder - 1);
        root->right = recurse(preorder, root_idx_inorder + 1, end_idx);
        return root;
    }
};
