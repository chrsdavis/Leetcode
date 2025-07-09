// O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        int pos = 0;
        int jumps = 0;
        const int n = nums.size() - 1;
        while (pos < n) {
            jumps++;
            int furthest = pos + nums[pos];
            if (furthest >= n) return jumps;
            int next = pos + nums[pos];
            const int limit = pos + nums[pos];
            for (int i = pos + 1; i <= limit; i++) {
                if (furthest < i + nums[i]) {
                    furthest = i + nums[i];
                    next = i;
                }
            }
            pos = next;
        }
        return jumps;
    }
};