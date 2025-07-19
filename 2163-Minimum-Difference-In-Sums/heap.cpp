using ll = long long;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        const int n = nums.size() / 3;
        vector<ll> min_sum(nums.size(), 0);
        min_sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            min_sum[i] = min_sum[i-1] + nums[i];
        }
        priority_queue<int> pq(nums.begin(), nums.begin() + n);
        for (int i = n; i < nums.size(); i++) {
            pq.push(nums[i]);
            const ll max_val = pq.top();
            pq.pop();
            min_sum[i] = (min_sum[i-1] + nums[i]) - max_val;
        }

        vector<ll> max_sum(nums.size(), 0);
        const int sz = nums.size();
        max_sum[sz-1] = nums[sz-1];
        for (int i = sz - 2; i > sz - 1 - n; i--) {
            max_sum[i] = max_sum[i+1] + nums[i];
        }
        priority_queue<int, vector<int>, std::greater<int>> pq2(nums.begin() + 2*n, nums.end());
        for (int i = sz - 1 - n; i >= 0; i--) {
            pq2.push(nums[i]);
            const ll min_val = pq2.top();
            pq2.pop();
            max_sum[i] = (max_sum[i+1] + nums[i]) - min_val;
        }

        // we can remove up to n elements
        // min_sum[n + i] is the min sum with removing i elements on the left,
        // and vice versa for the right
        // need to find a partition point
        ll min_diff = std::numeric_limits<ll>::max();
        for (int i = 0; i <= n; i++) {
            min_diff = min(min_diff, min_sum[n-1+i] - max_sum[n+i]);
        }
        return min_diff;
    }
};
