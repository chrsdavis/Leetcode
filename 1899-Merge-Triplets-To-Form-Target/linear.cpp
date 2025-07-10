class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        array<bool, 3> valid{false, false, false};
        for (const auto& triplet: triplets) {
            for (int i = 0; i < 3; i++) {
                if (triplet[i] == target[i] &&
                    triplet[(i+1) % 3] <= target[(i+1) % 3] &&
                    triplet[(i+2) % 3] <= target[(i+2) % 3]) {
                    valid[i] = true;
                }
            }
        }
        return valid[0] && valid[1] && valid[2];
    }
};