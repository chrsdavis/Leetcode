#include "util/common.h"

// runs O(n*2^n) time and O(n*2^n) space
// note backtracking solution is only linear time

// use a bitmask to record which values in nums should be in set
// so, we just have to generate all binary numbers from 0000... to 111111....
// then, we loop through each bit to check if it's set
// if the ith bit is set, then we push ith element of nums to current subset

class Solution {

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int N = nums.size();
        int nth_bit = 1 << N; // go until nth_bit
        // this is the upper bound
        vector<vector<int>> sol(nth_bit);
        // generate all possible bit masks from
        // 0000...0 to 111...11, with n digits
        for(int i = 0; i < nth_bit; i++) { // loop through bin numbers
            for(int j = 0; j < N; j++) { // loop through bits in current number
                if((i >> j) & 1) { // if jth bit is set
                    // then push jth element to set
                    sol[i].push_back(nums[j]);
                }
            }
        }
        return sol;
    }
};