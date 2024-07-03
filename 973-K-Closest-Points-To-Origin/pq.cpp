class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> pq; 
        auto cmp = [](const auto& a, const auto& b) {
            int a_dist = a[0] * a[0] + a[1] * a[1];
            int b_dist = b[0] * b[0] + b[1] * b[1];
            return a_dist < b_dist; 
        };

        for(auto p: points) {
            pq.push_back(p);
            push_heap(pq.begin(), pq.end(), cmp);
            if(pq.size() > k) {
                pop_heap(pq.begin(), pq.end(), cmp);
                pq.pop_back();
            }
        }
        return pq;
    }
};