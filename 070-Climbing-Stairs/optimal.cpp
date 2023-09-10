#include "util/common.h"

// Note this is just Fibonacci, so we only need 2 most recent numbers, not all [1, ..., k - 1]

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;

        int res, j = 1, k = 2;
        for(int i = 2; i < n; i++) {
            res = j + k;
            j = k;
            k = res;
        }
        return res;
    }
};
