class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, sub, 0);
        return ans;
    }

    void backtrack(
        vector<int>& nums,
        vector<vector<int>>& ans,
        vector<int>& sub,
        int pos
    ) {
        if(pos == nums.size()) {
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[pos]);
        backtrack(nums, ans, sub, pos + 1);
        sub.pop_back();

        // find next non-duplicate to start new subset
        int next_pos = upper_bound(nums.begin(), nums.end(), nums[pos]) - nums.begin();
        backtrack(nums, ans, sub, next_pos);
    }
};