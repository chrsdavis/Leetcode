#include "util/common.h"

// Uses the string s as a stack for no extra memory


class Solution {
public:
    bool isValid(string s) {
        int n = 0; // stack size, goes from s[0,...,n-1]
        for (char c : s)
            if (c % 26 % 3) // if opening parenthesis
                s[n++] = c; // push to stack
            else if (!n || c%s[--n]>2) // if no matching opening in stack, also pop stack
                return false;
        return !n; // n == 0 means stack is empty
    }
};