#include "util/common.h"
// We simply take a prefix and postfix array
// I.e. pre[n] = arr[0] * ... * arr[n - 1]
// and post[n] = arr[end] * ... * arr[n+1]
// so, ans[n] = pre[n] * post[n] = arr[0] * ... * arr[n-1] * arr[n + 1] * ... * arr[end]

// O(n) time, O(n) space, but can be done in place? I.e. O(1) additional space...?

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(), 1);
        vector<int> post(nums.size(), 1);
        int K = nums.size();
        for(int i = 1; i < nums.size(); i++) {
            int j = K-1-i;
            pre[i] = pre[i - 1] * nums[i - 1];
            post[j] = post[j + 1] * nums[j + 1];
        }
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = pre[i] * post[i];
        }
        return nums;
    }
};