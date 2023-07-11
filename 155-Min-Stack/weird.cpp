#include "util/common.h"

// weird solve I found

class MinStack {
    stack<long long>st;
    int mini=INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            mini=val;
        }else
        {
            if(mini<=val)
            st.push(val);
            else
            {
                //long long x=(long long)2*val-mini;
                st.push(2*1LL*val*1LL-mini);
                mini=val;
            }
        }
    }
    
    void pop() {
        if(st.empty())
        return ;
        if(st.top()>=mini)
        st.pop();
        else
        {
            mini=2*1LL*mini*1LL-st.top();
            st.pop();
        }
    }
    
    int top() {
         if(st.empty())
        return -1;
        if(st.top()<mini)
        return mini;
        return st.top();
    }
    
    int getMin() {
        return st.empty()?-1:mini;
    }
};
