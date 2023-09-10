#include "util/common.h"

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 0; i < n - 2; i++) {
            dp[i + 1] += dp[i];
            dp[i + 2] += dp[i];
        }
        dp[n - 1] += dp[n - 2];
        return dp[n - 1];
    }
};
