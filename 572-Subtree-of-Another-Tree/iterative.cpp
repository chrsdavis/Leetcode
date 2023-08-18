#include "util/common.h"

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            if(temp->val == subRoot->val && isSameTree(temp, subRoot))
                return true;
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return false;
    }
private:
    bool isSameTree(TreeNode* q, TreeNode* p) {
        if(!q && !p) return true;
        else if(!q || !p || q->val != p-> val) return false;
        return isSameTree(q->left, p->left) && isSameTree(q->right, p->right);
    }
};
