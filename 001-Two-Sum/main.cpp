class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, size_t> hm;
        for(size_t i = 0; i < hm.size(); i++) {
            if(hm.contains(target - nums[i]))
                return {i, hm[target - nums[i]]};
            hm[nums[i]] = i;
        }
        return {};
    }
};