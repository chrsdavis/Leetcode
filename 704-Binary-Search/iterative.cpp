// https://leetcode.com/problems/binary-search/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0, upper = (int)nums.size() - 1;
        int mid;
        while(lower <= upper)
        {
            mid = (upper - lower) / 2 + lower;
            if(target == nums[mid]) return mid;
            else if(target > nums[mid]) lower = mid + 1;
            else upper = mid - 1;
        }
        return -1;
    }
};
