#include "util/common.h"

// beats 100%

class Solution {
public:
    int findMin(vector<int>& nums) {
        int upper = nums.size() - 1, lower = 0;

        while(upper > lower) {
            int mid = lower + (upper - lower) / 2;
            if(nums[mid] > nums[upper]) { // not on left
                lower = mid + 1;
            } else if(nums[mid] < nums[lower]){ 
                // note can't be equal bc of problem
                upper = mid;
            } else return nums[lower];
        }
        return nums[upper];
    }
};