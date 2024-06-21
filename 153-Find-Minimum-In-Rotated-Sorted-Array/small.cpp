class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if(nums[l] < nums[r]) return nums[l];
        while (l < r) {
            int m = (l + r) / 2;
            if(nums[m] >= nums[0]) l = m + 1;
            else r = m;
        }
        return nums[l];
    }
};