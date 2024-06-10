// slightly optimized pre/post solution
// no need for pre and postfix arrays, just use 2 ints

// O(n) time, and (discounting output vector) only O(1) space.
// this is not "truly" in-place, i guess

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int pre = 1, post = 1;
        for(int i = 0; i < n; i++) {
            ans[i] *= pre;
            pre *= nums[i];
        }
        for(int i = n-1; i >= 0; i--) {
            ans[i] *= post;
            post *= nums[i];
        }
        return ans;
    }
};