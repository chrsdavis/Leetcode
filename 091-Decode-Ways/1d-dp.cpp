#include "util/common.h"

// T[i] = { T[i - 1] (if S[i] == 0 or S[i-1] too big)
//        { T[i - 1] + 1 if S[i] != 0

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        if(s.size() == 1) return 1;

        int N = s.size();
        int t1 = 1, t2 = 1;
        for(int i = 1; i < N; i++) {
            int temp = 0; // start as zero
            if(s[i] != '0') // single digit is valid
                temp += t1; // add T[i - 1]
            
            int double_digit = stoi(s.substr(i - 1, 2));
            // check if double_digit = 0X or is > 26
            // dd < 10 means s[i -1] == 0, so disregard
            if(double_digit >= 10 && double_digit <= 26) {
                temp += t2; // add T[i - 2]
            }
            // update
            t2 = t1;
            t1 = temp;
        }
        return t1;
    }
};
