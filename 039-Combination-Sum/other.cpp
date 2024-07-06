class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sol;
        vector<vector<int>> ans;
        backtrack(candidates, sol, ans, target, 0);
        return ans;
    }

    void backtrack(
        vector<int>& candidates,
        vector<int>& sol,
        vector<vector<int>>& ans,
        int target,
        int pos
    ) {
        for(int i = pos; i < candidates.size(); i++) { // we need to track pos to avoid duplicates
            int& c = candidates[i];                    // so, we only want to go left --> right
            if(c > target) continue;
            sol.push_back(c);
            if(c == target) ans.push_back(sol);
            else backtrack(candidates, sol, ans, target - c, i);
            sol.pop_back();
        }
    }
};