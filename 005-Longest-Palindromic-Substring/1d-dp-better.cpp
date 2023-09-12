#include "util/common.h"

// Loop through all centers and expand around them
// consider even and odd centers by starting at either a single element, or neighboring elements
// O(n^2) runtime, O(1) memory

class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size();
        int count = 0;
        for(int i = 0; i < N; i++) {
            count += helper(s, i, i); // odd length
            count += helper(s, i, i + 1); // even
        }
        return count;
    }

    int helper(const string&s, int left, int right) {
        int count = 0;
        while(left >= 0 && right < s.size()) {
            if(s[left--] != s[right++]) {
                break;
            }
            count++;
        }
        return count;
    }
};