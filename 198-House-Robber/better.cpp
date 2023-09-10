#include "util/common.h"

/*
    T[i] = max( V[i] + T[i - 2],  T[i - 1] )
*/

class Solution {
public:
    int rob(vector<int>& nums) { 
        int n = nums.size(), pre = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
