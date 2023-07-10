#include "util/common.h"

// Uses the string s as a stack for no extra memory

// correct matchings should have an ASCII literal difference of either 1 or 2
// we don't have to worry about the 0 case (']]') bc we don't push closing parens on stack

class Solution {
public:
    bool isValid(string s) {
        int n = 0; // stack size, goes from s[0,...,n-1]
        for (char c : s)
            if (c % 26 % 3) // if opening parenthesis
                s[n++] = c; // push to stack
            else if (!n || c % s[--n] > 2) // if no matching opening in stack, also pop stack
                return false;
        return !n; // n == 0 means stack is empty
    }
};
