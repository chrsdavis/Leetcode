// Less efficient and more complicated than "top-down" in simple.cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        const int n = nums.size() - 1;
        while (pos < n && nums[pos] > 0) {
            int next = pos;
            int highest = -1;
            const int limit = pos + nums[pos];
            if (limit >= n) return true;
            for (int i = pos + 1; i <= limit; i++) {
                if (i + nums[i] > highest) {
                    highest = i + nums[i];
                    next = i;
                }
            }
            pos = next;
        }
        return pos == n;
    }
};