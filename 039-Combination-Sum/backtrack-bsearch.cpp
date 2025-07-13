// Since all candidates[i] > 0, then we can sort + bin search to find the next possible
// answer after candidates.begin() + idx. This helps with early pruning of blocks of 
// impossinble branches. E.g. candidates is 5 4 3 2 1 and target is 6. If you start at 5, then you can jump to 3.
// Basically integer partitioning.

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
        for (int i = it - nums.begin(); i < nums.size(); i++) {
            cur.push_back(nums[i]);
            backtrack(target - nums[i], i);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), std::greater{});
        nums = std::move(candidates);
        ans.clear();
        cur.clear();
        backtrack(target, 0);
        return ans;
    }
};