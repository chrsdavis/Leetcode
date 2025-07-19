// a a a a
// a b a b

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<vector<int>> mod_k(k);
        for (int i = 0; i < nums.size(); i++)
            mod_k[nums[i] % k].push_back(i);
        std::sort(mod_k.begin(), mod_k.end(),
            [](const auto& a, const auto& b){ return a.size() > b.size(); });

        int max_len = max(2uz, mod_k[0].size()); // longest a a a a a subset
        for (int a = 0; a < k - 1; a++) { // find longest a b a b a subset
            for (int b = a + 1; b < k && mod_k[a].size() + mod_k[b].size() > max_len; b++) {
                int num_ab = 0; // find valid pairs of [a, ..., b]
                for (int i = 0, j = 0; i < mod_k[a].size() && j < mod_k[b].size(); j++) {
                    if (mod_k[a][i] < mod_k[b][j])
                        num_ab += 2; // valid [a,b] pair, so find another
                    while (i < mod_k[a].size() && mod_k[a][i] < mod_k[b][j])
                        i++;
                }
                // account for [b, a, ...] and [..., b, a]
                // i.e. sequence isn't just a,b repeating, and ends/starts early
                if (mod_k[b][0] < mod_k[a][0]) num_ab++; // [b, a, ...] case
                if (mod_k[b].back() < mod_k[a].back()) num_ab++; // [..., b, a] case
                max_len = max(max_len, num_ab);
            }
        }
        return max_len;
    }
};
