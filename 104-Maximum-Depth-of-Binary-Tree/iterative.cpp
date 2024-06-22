/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 0});
        int max_depth = 0;
        while(!stk.empty()) {
            auto tmp = stk.top();
            stk.pop();
            if(tmp.first) {
                int depth = tmp.second + 1;
                max_depth = max(max_depth, depth);
                stk.push({tmp.first->left, depth});
                stk.push({tmp.first->right, depth});
            }
        }
        return max_depth;
    }
};