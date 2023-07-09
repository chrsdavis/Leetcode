#include "util/common.h"

// slightly optimized by making use of ASCII table properties

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2) return false;
        stack<char> stk;
        for(char c: s) {
            switch(c) {
                case '{':
                case '(':
                case '[':
                    stk.push(c);
                    break;
                case ')': // bc ASCII sucks and is inconsistent
                    if(stk.empty() || stk.top() != '(') return false;
                    stk.pop();
                    break;
                case '}':
                case ']':
                    if(stk.empty() || stk.top() != (char)(c-2)) return false;
                    stk.pop();
                    break;
            }
        }
        return stk.empty();
    }
};