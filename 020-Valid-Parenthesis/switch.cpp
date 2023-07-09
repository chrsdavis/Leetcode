#include "util/common.h"

// basic solve with switch statement and fallthroughs

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
                case ')':
                    if(stk.empty() || stk.top() != '(') return false;
                    stk.pop();
                    break;
                case '}':
                    if(stk.empty() || stk.top() != '{') return false;
                    stk.pop();
                    break;
                case ']':
                    if(stk.empty() || stk.top() != '[') return false;
                    stk.pop();
                    break;
            }
        }
        return stk.empty();
    }
};