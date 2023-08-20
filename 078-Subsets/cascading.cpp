# include "util/common.h"

/* *********************
-- Cascading Solution --
Time: O( N x 2^N )
Memo: O( N x 2^N)
********************* */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> power_set;
        power_set.push_back(vector<int>{}); // empty set
        for(int num: nums) // bf add new sets one by one
        {
            // record current size before modifying power set
            int N = power_set.size();
            for(int i = 0; i < N; i++) {
                // copy, not reference
                vector<int> permutation = power_set[i];
                permutation.push_back(num); // append new num
                power_set.push_back(permutation);
            }
        }
        return power_set;
    }
};
