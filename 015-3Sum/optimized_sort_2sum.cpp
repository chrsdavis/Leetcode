// Added edge case checks to sort_2sum.cpp's soluton
// beats 99.6%

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> sol;
        if(nums[0] > 0 || n < 3) return sol;

        for(int i = 0; i < n - 2; i++) {
            // if positive, next elements all positive, so can't reach target
            if(nums[i] > 0) break; // no need to go further
            
            if(i != 0 && nums[i] == nums[i - 1])
                continue; // duplicate e.g. [3 |3| 4 5 6], so check next i

            int left = i + 1, right = n - 1;
            int target = -nums[i];

            while(left < right) {
                // int sum = nums[left] + nums[i] + nums[right];
                // check sum against zero, not target if using above code
                int sum = nums[left] + nums[right];
                
                if(sum > target) right--;
                else if(sum < target) left++;
                else {
                    sol.push_back({nums[i], nums[left], nums[right]});
                    do { left++; }
                    while(left < right && nums[left] == nums[left - 1]);
                    do { right--; }
                    while(left < right && nums[right] == nums[right + 1]);
                }
            }
        }
        return sol;
    }
};