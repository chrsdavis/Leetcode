// NOTE: this works for any binary tree, so it doesn't exploit the fact
// that the input is a BST. This means it is O(n) instead of O(logn), so
// others should be used.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        else if (root->val == p->val || root->val == q->val) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l == nullptr && r == nullptr) return nullptr;
        else if(l != nullptr && r != nullptr) // common ancestor
            if(l->val != r->val) return root;
            else return l;
        else
            return l ? l : r;
    }
};