#include "util/common.h"

class Solution {
private:
    int len; // len of current subset
    vector<vector<int>> powerset; // solution

    // note perm does not have to be a vector reference
    void backtrack(int start, vector<int>& perm, const vector<int>& nums) {
        // if current perm is filled up (ie valid solution)
        if(perm.size() == len) {
            powerset.push_back(perm);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            // insert nums[i] into current permutation
            perm.push_back(nums[i]);

            // insert more elements (if needed)
            backtrack(i + 1, perm, nums);

            // prune current solution
            perm.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        powerset = vector<vector<int>>{};
        // loop over all lengths of subsets 
        // this is (0 -> n) b/c of emptyset
        vector<int> permutation = {};
        for(len = 0; len <= nums.size(); len++)
            backtrack(0, permutation, nums);

        return powerset;
    }
};