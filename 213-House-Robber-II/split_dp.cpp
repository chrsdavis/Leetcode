#include "util/common.h"

/*
    Basically, we either choose to include nums[0] or nums[n - 1]
    since we can't have both as they neighbour each other
    Thus, we basically do the original DP question (House Robber I) 
    but with the two new lists and return the max answer:
    max( DP(nums[1:]),  DP(nums[:-1]) )

    We can either do T[i] = max(T[i-2], T[i-3]) + nums[i] w/ 3 temp vals
    Or T[i] = max(T[i - 2] + nums[i],  T[i-1]) w/ 2 temp vals
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        // tj = T[i - j]
        // T[i] represents max possible sum until i
        int t1 = 0, t2 = 0, N = nums.size();
        if(N == 1) return nums[0];

        for(int i = 0; i < N - 1; i++) { // exclude nums[N - 1]
            int temp = max(t2 + nums[i], t1);
            t2 = t1, t1 = temp;
        }
        int l_max = t1;

        t1 = 0, t2 = 0;
        for(int i = 1; i < N; i++) { // exclude nums[0]
            int temp = max(t2 + nums[i], t1);
            t2 = t1, t1 = temp;
        }
        int r_max = t1;

        return max(l_max, r_max);
    }
};