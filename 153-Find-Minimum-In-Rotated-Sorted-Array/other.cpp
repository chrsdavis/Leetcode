class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if(nums[l] <= nums[m] && nums[m] <= nums[r]) {
                return nums[l];
            } else if(nums[m] >= nums[l]) {
                l = m + 1; // must be m + 1
            } else if(nums[m] <= nums[r]) {
                r = m; // not m - 1 because of issue
            }
        }
        return nums[l];
    }
};