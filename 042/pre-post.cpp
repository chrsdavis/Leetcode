// for any given column, the heght of water is min(max to left, max to right)
// so, to find the water height at col i, we just make a prefix and suffix array that
// tracks the maximum from the left and the right
// pre[0] = 0, pre[1] = height[0], and post[end] = 0, post[end-1] = height[end-1]

// O(n) time, O(n) space; there is a way to do it in O(1) space, see other sol

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> pre(height.size(), 0);
        vector<int> post(height.size(), 0);
        int n = height.size();
        for(int i = 1; i < n; i++) {
            pre[i] = max(height[i-1], pre[i-1]);
            post[n-1-i] = max(height[n-i], post[n-i]);
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            int depth = min(pre[i], post[i]);
            count += max(0, depth - height[i]);
        }
        return count;
    }
};