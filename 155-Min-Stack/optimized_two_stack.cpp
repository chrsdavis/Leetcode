#include "util/common.h"

// stores index of previous min in stack
// optimized version of stack of pairs solution, as that stores a lot of duplicates for min
// instead of storing min for every value, we just store index of min in a stack and just
// update it whenever we cross that index again

class MinStack {

private:
    vector<int> data, min_idx;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        data.push_back(val);
        if(!min_idx.size() || val < data[min_idx.back()])
            min_idx.push_back(data.size() - 1);
    }
    
    void pop() {
        if(min_idx.back() == data.size() - 1)
            min_idx.pop_back();
        data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return data[min_idx.back()];
    }
};
