class Solution {
private:
    bool recurse(string_view s, int i, int num_open,
                 vector<vector<int>>& memo) {
        if (i == s.size()) return num_open == 0;
        else if (num_open < 0) return false;
        else if (memo[i][num_open] != -1) return memo[i][num_open];

        bool result = false;
        if (s[i] == '(') {
            result |= recurse(s, i + 1, num_open + 1, memo);
        } else if (s[i] == ')') {
            result |= recurse(s, i + 1, num_open - 1, memo);
        } else {
            result |= recurse(s, i+1, num_open + 1, memo) ||  // choose * := (
                      recurse(s, i+1, num_open - 1, memo) ||  // choose * := )
                      recurse(s, i+1, num_open, memo);        // choose * := ''
        }
        memo[i][num_open] = result;
        return result;
    }

public:
    bool checkValidString(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        return recurse(s, 0, 0, memo);
    }
};

// ((**)