// Same as backtrack.cpp solution, except I realized that explicitly checking for duplicates is not necessary
// Ie the early pruning of repeated values in the for-loop is enough to guarantee uniqueness

class Solution {
private:
    vector<int> nums;
    vector<vector<int>> ans;
    vector<int> cur;

    void backtrack(int target, int idx) {
        if (target == 0) {
            ans.emplace_back(cur);
            return;
        } else if (target < 0) {
            return;
        }

        auto it = std::lower_bound(nums.begin() + idx, nums.end(),
                                   target, std::greater{});
        int prev = -1;
        for (int i = it - nums.begin(); i < nums.size(); i++) {
            if (nums[i] == prev) continue;
            prev = nums[i];
            cur.push_back(nums[i]);
            backtrack(target - nums[i], i+1);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), std::greater{});
        swap(nums, candidates);
        ans.clear();
        cur.clear();
        backtrack(target, 0);
        return ans;
    }
};