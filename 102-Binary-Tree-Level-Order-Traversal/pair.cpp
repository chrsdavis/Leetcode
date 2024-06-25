// Push depth of every node; technically not necessary
// At the end of every level, we will have already pushed the next level
// to the queue. Thus, we just check the size of the queue and continuosly loop through that
// see "working.cpp"

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;
        q.push({root,0});
        vector<int> level;
        int depth = 0;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if(!p.first) continue;
            if(p.second != depth) {
                ans.push_back(level);
                level.clear();
                depth++;
            }
            level.push_back(p.first->val);
            q.push({p.first->left, p.second + 1});
            q.push({p.first->right, p.second + 1});
        }
        if(level.size() > 0)
            ans.push_back(level);
        return ans;
    }
};