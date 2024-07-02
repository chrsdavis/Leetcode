class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : 
        pq(nums.begin(), nums.end()), k(k) { 
            while(pq.size() > k) pq.pop(); 
        }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }

private:
    priority_queue<int, vector<int>, std::greater<int>> pq;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */