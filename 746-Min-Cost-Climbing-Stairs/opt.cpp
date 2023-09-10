#include "util/common.h"

/*
    T[i] = min(T[i - 1], T[i - 2])

    So, just like Fibonacci, we only need 2 most recent vals
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int t1 = cost[1], t2 = cost[0];
        int temp = min(t1, t2);
        int N = cost.size();

        for(int i = 2; i < N; i++) {
            temp = min(t1, t2) + cost[i];
            t2 = t1;
            t1 = temp;
        }

        return min(t1, t2);
    }
};
