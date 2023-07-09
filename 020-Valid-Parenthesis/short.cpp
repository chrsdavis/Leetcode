#include "util/common.h"

// short solution, might be slower and less clear than switch statement ones

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2) return false;
        stack<char> stk;
        for(char c: s) {
            if(c == '(' || c == '{' || c == '[')
                stk.push(c);
            else {
                if(stk.empty() || stk.top() != (char)(c - 1 - (c != ')') ))
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};