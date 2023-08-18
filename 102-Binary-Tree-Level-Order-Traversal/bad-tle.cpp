#include "util/common.h"

// TLE and no idea why, big O should be good

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> sol;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            if(sol.size() == depth) {
                sol.push_back({node->val});
            } else {
                sol[depth].push_back(node->val);
            }
            depth++;
            if(node->left) q.push({node, depth});
            if(node->right) q.emplace(node, depth);
        }
        return sol;
    }
};