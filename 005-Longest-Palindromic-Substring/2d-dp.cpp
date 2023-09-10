#include "util/common.h"

/*
    T[i][j] = whether s[i to j] is a palindrome
    need to check T[i + 1][j - 1] is correct
    i.e "[a]bab[a]", we get to [0,4]; check that "bab" is a palindrome and
    that "a" == "a"
    So, T[i][j] = T[i + 1][j - 1]
    T[i][i] = true (1 len strings)
    T[i][i + 1] we have to check ourselves since not covered by above recursion

    Runs in O(n^2) time, and O(n^2) memory
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        vector<vector<bool>> dp(N, vector<bool>(N, false));
        pair<int, int> bounds = {0, 0};

        // all single strings are palindromes, so set borders to 1
        for(int i = 0; i < N; i++)
            dp[i][i] = true;
        
        // check all substrs of len 2
        // below recursive step only works for len > 2
        for(int i = 0; i < N - 1; i++) {
            if(s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                bounds = {i, i + 1};
            }
        }
        // go through all possible lengths (sub_len = j - i)
        for(int sub_len = 2; sub_len < N; sub_len++) {
            for(int l = 0; l < N - sub_len; l++) {
                int r = l + sub_len;
                if(s[l] == s[r] && dp[l + 1][r - 1]) {
                    dp[l][r] = true;
                    bounds = {l, r};
                }
            }
        }
        return s.substr(bounds.first, bounds.second - bounds.first + 1);
    }
};
