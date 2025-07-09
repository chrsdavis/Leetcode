// O(nk)
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> table(nums.size(), INT_MAX);
        table[0] = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            const int limit = min((int)nums.size(), i + nums[i] + 1);
            for (int j = i + 1; j < limit; j++) {
                table[j] = min(table[j], table[i] + 1);
            }
        }
        return table[nums.size() - 1];
    }
};