// since target = 0, then (sorted) nums[i] <= 0, since otherwise
// the sum must be positive > 0

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        int i = 0; // target = 0
        while(i < nums.size() && nums[i] <= 0) {
            if(i > 0 && nums[i] == nums[i-1]) { // need a non-pos value to have 0 sum
                i++; // duplicate
                continue;
            }

            // just do sorted 2 sum (multiple answers)
            int l = i + 1, r = nums.size() - 1;
            while(l < r) { 
                int tmp = nums[l] + nums[r];
                if(tmp < abs(nums[i])) l++;
                else if(tmp > abs(nums[i])) r--;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int t = nums[l]; // go past duplicates
                    while(l < r && nums[l] == t) l++;
                }
            }
            i++;
        }
        return ans;
    }
};