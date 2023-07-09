#include "util/common.h"

// Loop through array and run normal 2sum on the rest of array to right
// Can be multiple solutions, so keep advancing the two pointer 2sum algo to find all solutions
// Note: can optimize more based on negative and positive values since they get sorted
// Runs in O(n^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> sol;
        for(int i = 0; i < n - 2; i++) {
            if(i != 0 && nums[i] == nums[i - 1])
                continue; // duplicate e.g. [3 |3| 4 5 6]

            int left = i + 1, right = n - 1; // Run normal two sum (sort version)
            while(left < right) {
                int target = -nums[i];
                int sum = nums[left] + nums[right];
                
                if(sum > target) right--;
                else if(sum < target) left++;
                else { // valid solution
                    sol.push_back({nums[i], nums[left], nums[right]});
                    do { left++; } // advance to see if any other solutions involving nums[i]
                    while(left < right && nums[left] == nums[left - 1]); // skip duplicates
                    do { right--; }
                    while(left < right && nums[right] == nums[right + 1]);
                }
            }
        }
        return sol;
    }
};