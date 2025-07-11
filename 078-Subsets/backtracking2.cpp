class Solution {
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums,
                   vector<int>& candidate, int i) {
        for (; i < nums.size(); i++) {
            candidate.push_back(nums[i]);
            ans.push_back(candidate);
            backtrack(ans, nums, candidate, i + 1);
            candidate.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(1, vector<int>{});
        vector<int> candidate;
        backtrack(ans, nums, candidate, 0);
        return ans;
    }
};