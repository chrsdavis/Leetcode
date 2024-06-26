class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root, INT_MIN});
        while(!q.empty()) {
            auto [tmp, mx] = q.front();
            q.pop();
            if(tmp->val >= mx) ans++;
            mx = max(mx, tmp->val);
            if(tmp->left) q.push({tmp->left, mx});
            if(tmp->right) q.push({tmp->right, mx});
        }
        return ans;
    }
};
