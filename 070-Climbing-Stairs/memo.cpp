#include "util/common.h"

int table[46] = {0}; // b/c 1 <= n <= 45

class Solution {
public:
    
    int climbStairs(int n) {
        if(n==1) {table[1] = 1; return 1;}
        if(n==2) {table[2] = 2; return 2;}
        if(table[n] != 0) return table[n];
        table[n] = climbStairs(n-1) + climbStairs(n-2);
        return table[n];
    }
};
