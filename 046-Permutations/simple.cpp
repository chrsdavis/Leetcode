class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, ans, 0);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int pos) {
        if(pos == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); i++) { // here, we reuse nums instead of making a new vector
            swap(nums[pos], nums[i]); // equivalent to pushing new element
            backtrack(nums, ans, pos + 1);
            swap(nums[pos], nums[i]); // equivalent to popping back
        }
    }
};