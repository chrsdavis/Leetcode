class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int cur_sum = 0;
        for (int i: nums) {
            cur_sum += i;
            max_sum = max(cur_sum, max_sum);
            cur_sum = max(cur_sum, 0);
        }
        return max_sum;
    }
};