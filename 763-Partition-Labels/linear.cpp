class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last_idx[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            last_idx[s[i] - 'a'] = i;
        }
        int cur_endpoint = 0, prev_endpoint = -1;
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            cur_endpoint = max(cur_endpoint, last_idx[s[i] - 'a']);
            if (i == cur_endpoint) {
                ans.push_back(cur_endpoint - prev_endpoint);
                prev_endpoint = cur_endpoint;
            }
        }
        return ans;
    }
};