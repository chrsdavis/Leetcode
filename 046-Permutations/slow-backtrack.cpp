class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        backtrack(nums, ans, perm);
        return ans;
    }

    void backtrack(
        vector<int>& nums,
        vector<vector<int>>& ans,
        vector<int>& perm
    ) {
        if(perm.size() == nums.size()) {
            ans.push_back(perm);
            return;
        }
        for(int n: nums) {
            if(std::find(perm.begin(), perm.end(), n) != perm.end()) // very slow, bad
                continue;
            perm.push_back(n);
            backtrack(nums, ans, perm);
            perm.pop_back();
        }
    }
};