// Basically, use two (implicit) stacks to keep track of the options
// If s[i] == (, then we must add an open. Similarly, if s[i] == ), then we must remove an open.
// But, if s[i] == *, we have three options: set it to (, ), or ''. To account for these branches, have two counters.
// One takes the * := ( path, and the other the * := ). The latter gives the minimum possible value of unfilled open parentheses.
// If it goes negative, then reset it to 0, since we could have just done * := ''. If the * := ( counter goes negative, return false.
// This accounts for when the min_open counter is "forced" to be negative; otherwise, we chose to do a * := ), meaning we can just 
// "undo" that choice by resetting the counter to 0.

class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0, max_open = 0;
        for (char c: s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else {
                min_open--; // set * := ')'
                max_open++; // set * := '('
            }
            if (max_open < 0) return false;
            min_open = max(min_open, 0); // undo * := ')'
        }
        return min_open == 0;
    }
};

// ((**)