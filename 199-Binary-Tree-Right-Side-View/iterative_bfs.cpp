#include "util/common.h"

// just do level order traversal but only care about right most element
// we make right-most the first node in level by simply always adding right child first

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        if(!root) return sol;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size(); // size of level
            // we make sure right-most node is the
            // first added to queue (at bottom of loop)
            TreeNode* right_most = q.front();
            q.pop();
            sol.push_back(right_most->val);
            if(right_most->right) q.push(right_most->right);
            if(right_most->left) q.push(right_most->left);

            for(int i = 1; i < sz; i++) { // go through a level
                // add other children in next level to queue
                // make sure to add right child first
                TreeNode* non_right_most = q.front();
                q.pop();
                if(non_right_most->right)
                    q.push(non_right_most->right);
                if(non_right_most->left)
                    q.push(non_right_most->left);
            }
        }
        return sol;
    }
};