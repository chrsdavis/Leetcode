// Basically the same as the lambda solution.
// But, we can actually just return "low", no need to keep track of a "min_amount" var

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1;
        for(int p: piles)
            high = max(p, high);

        while (low <= high) {
            int k = (high - low) / 2 + low;
            unsigned int count = 0;
            for(int p: piles) {
                count += (p / k) + (int)(p % k > 0);
                if(count > h) break; // avoid overflow
            }
            if(count <= h) { // if valid answer
                high = k - 1;
            } else
                low = k + 1;
        }
        return low;
    }
};