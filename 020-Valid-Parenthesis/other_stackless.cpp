#include "util/common.h"

// Note: difference should be exactly 1 or 2, so floor((x+1) / 2) maps 1,2 --> 1, and nothing else to 1

class Solution {
public:
    bool isValid(string s) {
        int n = 0; // size of stack, s[0, ..., n-1]
        for (char c : s) {
            // check that difference is either 1 or 2, meaning they are
            // corresponding brackets
            if (n && (c - s[n-1] + 1) / 2 == 1) n--; //pop stack
            else s[n++] = c; // push to stack
            // NOTE: doesn't fail early for mismatched brackets
        }
        return !n; // if n == 0, stack is empty
    }
};
