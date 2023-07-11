#include "util/common.h"

// I use an array of pairs to store the min of all values "below" the current one in the stack
// E.g.: 
// val | min
//   1 | -4
//  -4 | -4
//   8 | 0
//   0 | 0
//   4 | 4
// As we pop down from the top of the stack, we just reiterate through the existing values, so we 
// preserve the min value


class MinStack {

private:
    struct pair {
        int val;
        int min;
    };

    vector<pair> data;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        data.push_back({val, data.size() ? min(data.back().min, val) : val});
    }
    
    void pop() {
        data.pop_back();
    }
    
    int top() {
        return data.size() ? data.back().val : 0;
    }
    
    int getMin() {
        return data.size() ? data.back().min : INT_MIN;
    }
};
