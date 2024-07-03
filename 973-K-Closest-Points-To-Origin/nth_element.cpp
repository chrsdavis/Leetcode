// best without making your own quickselect / introselect

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::nth_element(
            points.begin(),
            points.begin() + k,
            points.end(),
            [](const auto& a, const auto& b) {
                int a_dist = a[0] * a[0] + a[1] * a[1];
                int b_dist = b[0] * b[0] + b[1] * b[1];
                return a_dist < b_dist; 
            });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};