#include "util/common.h"

// Added edge case checks to sort_2sum.cpp's soluton
// Note: could be improved by using iterators b/c don't need random access from subscript operator
// beats 99.6%, runs O(n^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> sol;
        if(nums[0] > 0 || n < 3) return sol; // all positive (can't be 0) or too small, so no answer

        for(int i = 0; i < n - 2; i++) {
            // if positive, next elements all positive, so can't reach target
            if(nums[i] > 0) break; // no need to go further
            
            if(i != 0 && nums[i] == nums[i - 1]) // duplicate e.g. [3 |3| 4 5 6]
                continue; // already run with this nums[i]'s value, so check next i value

            int left = i + 1, right = n - 1;
            int target = -nums[i]; // Run normal 2sum with this target (sort solution) on rest of nums

            while(left < right) { 
                // check sum against 0, not target if using this commented code (may be faster?)
                // int sum = nums[left] + nums[i] + nums[right];

                int sum = nums[left] + nums[right];
                
                if(sum > target) right--;
                else if(sum < target) left++;
                else {
                    sol.push_back({nums[i], nums[left], nums[right]});
                    do { left++; } // advance to find any other solutions for this i value
                    while(left < right && nums[left] == nums[left - 1]); // skip duplicates
                    do { right--; }
                    while(left < right && nums[right] == nums[right + 1]);
                }
            }
        }
        return sol;
    }
};