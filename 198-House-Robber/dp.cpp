#include "util/common.h"

/*
    T[i] = max(T[i - 2], T[i - 3]) + V[i]
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if(N == 1) return nums[0];
        if(N == 2) return max(nums[0], nums[1]);

        // tj = T[i - j]
        // we need to keep track of 3 most recent
        // we need to store t1 as it's otherwise not included
        int t3 = nums[0], t2 = nums[1];
        int t1 = nums[2] + nums[0];
        int temp = max(t2, t3); 

        for(int i = 3; i < N; i++) {
            temp = max(t2, t3) + nums[i];
            t3 = t2;
            t2 = t1;
            t1 = temp;
        }

        return max(t1, t2);
    }
};
