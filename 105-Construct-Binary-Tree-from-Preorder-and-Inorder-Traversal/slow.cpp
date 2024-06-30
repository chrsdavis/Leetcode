// The more intuitive logic of what's happening with `precomp_arr.cpp`, which is this but faster

class Solution {
public:
    TreeNode* helper(vector<int>& pre, vector<int>& in, int l, int r, int& k) {
        if(l >= r) return nullptr;
        int i = l;
        // O(n) each call; we can skip this loop by pre-computing, making this O(1)
        for(; i < r; i++) if(in[i] == pre[k]) break; // slow
        TreeNode* root = new TreeNode(pre[k]);
        if(l + 1 == r) return root;
        if(i == l) { // more complicated logic because we are not pre-computing k or i.
            root->left = nullptr;
            root->right = helper(pre, in, i+1, r, ++k);
        } else if (i == r - 1) {
            root->left = helper(pre, in, l, i, ++k);
            root->right = nullptr;
        } else {
            root->left = helper(pre, in, l, i, ++k);
            root->right = helper(pre, in, i+1, r, ++k);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int k = 0;
        return helper(preorder, inorder, 0, preorder.size(), k);
    }
};