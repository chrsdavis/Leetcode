#include "util/common.h"

// Note that all vals are positive, so as soon as current sum
// is greater than target, we know that branch is invalid

class Solution {
private:
    int target_;
    vector<vector<int>> ans;
    void backtrack(const vector<int>& candidates, vector<int>& summands, int sum, int idx) {
        if(sum == target_) { // found ans
            ans.push_back(summands);
        }else if(sum > target_) { // defintely wrong answer
            // ignore this path
            return;
        }

        // loop through possible next values
        for(int i = idx; i < candidates.size(); i++) {
            // check if it's already wrong
            // note all vals are positive, so done as soon as over
            if(candidates[i] + sum > target_) continue;

            summands.push_back(candidates[i]);
            backtrack(candidates, summands, sum + candidates[i], i);
            summands.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        target_ = target;
        ans = vector<vector<int>>{};
        vector<int> summand;
        backtrack(candidates, summand, 0, 0);
        return ans;
    }
};
