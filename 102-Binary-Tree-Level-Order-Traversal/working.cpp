#include "util/common.h"

// this one works

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> sol;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size(); // number in current level
            vector<int> temp_vec;
            temp_vec.reserve(n);
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp_vec.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            sol.push_back(temp_vec);
        }
        return sol;
    }
};
