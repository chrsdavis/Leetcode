#include "util/common.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0, upper = nums.size() - 1;
    }
};

//  4 5 1 2 3
// 4 > 2, so drop in [0, 3] (@ 2) and [4,5] is sorted
// so if target < nums[3], then it CAN'T be to right,
// meaning it must be from [0,3], so we go left.

// otherwise, the right half is sorted, and the left contains
// the switch point. Then, if mid < target < nums[0], then it
// must be to the right as if target > nums[0] > mid, then since [0, mid] must contain the switch point (i.e. min/max), then the 
// target has to be towards the left side since it increases.

// if in turn target < mid < nums[0], then it simply can't be on the right since [mid, end] is sorted ascending.

// thus, we go left if: 
/*
    nums[0] < target < mid // bc [0,mid] sorted
        target < mid < nums[0] // bc [mid,end] sorted
            mid < nums[0] < target

*/

// 4 5 1 |2| 3