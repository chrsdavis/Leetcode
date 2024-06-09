class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> keys; // {count, key}
        int prev = nums[0];
        pair<int, int> p = {0, prev};
        for(int n: nums) {
            if(n == prev) {
                p.first++;
            }else{
                keys.push_back(p);
                p.first = 1;
                p.second = n;
                prev = n;
            }
        }
        keys.push_back(p);
        sort(keys.rbegin(), keys.rend());
        vector<int> output;
        int N = min(k, (int)keys.size());
        for(int i = 0; i < N; i++) {
            output.push_back(keys[i].second);
        }
        return output;
    }
};