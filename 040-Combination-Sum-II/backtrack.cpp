// Similar to Combination Sum (39), except I have to check for duplicate answers now
// candidates to sum up to target are not unique, and I can only use each one once.
// Cannot use duplicate answers
// Now, I explicitly check if an answer was a duplicate (I might be able to optimize this away...?)
// Since I add all answers in sorted order (descending), the answer is in descending lexicographic order
// Can check for duplicate in O(log n) with no additional space for hash map

// I also skip adding the same element to do early pruning of duplicate solutions
// E.g. ..., a, n, n, n, n, n, n, c
// I get to the first n, backtrack it, then skip all subsequent n's and go straight to c

// NOTE: see better.cpp
// The explicit check for duplicates is unnecessary; the early pruning is enough

class Solution {
private:
    vector<int> nums;
    vector<vector<int>> ans;
    vector<int> cur;

    void backtrack(int target, int idx) {
        if (target == 0) {
            auto sol = std::lower_bound(ans.begin(), ans.end(),
                                        cur, std::greater{});
            if (sol == ans.end() || *sol != cur) // check for duplicate answer (i think this is redundant)
                ans.emplace_back(cur);
            return;
        } else if (target < 0) {
            return;
        }

        auto it = std::lower_bound(nums.begin() + idx, nums.end(),
                                   target, std::greater{});
        int prev = -1;
        for (int i = it - nums.begin(); i < nums.size(); i++) {
            if (nums[i] == prev) continue; // skip duplicates (may guarantee uniqueness?)
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