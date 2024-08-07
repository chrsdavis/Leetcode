class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(
            stones.begin(), stones.end()
        );
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a > b) swap(a,b);
            pq.push(b - a);
        }
        return pq.top();
    }
};