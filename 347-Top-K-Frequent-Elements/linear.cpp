#include "util/common.h"
// the important thing to note is that the top k elements DO NOT NEED to be SORTED; 
// we only have to know which elements are in the top k, so there is no reason to waste O(log(k)) on sorting the top k

// Thus, we can use a selection algorithm (quickselect / introselect) to partition an array in a partial sort
// std::nth_element takes array s.t. all elements in [begin, middle) <= all elements in [middle, end]
// however, the elements in [begin, middle) are NOT sorted themselves.
// E.g. [1,5,3,4,2] ==> [1,3,2 | 5,4] (nth_element)
// E.g. [1,5,3,4,2] ==> [1,2,3 | 5,4] (partial_sort)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hm;
        vector<int> ans;
        for(int n: nums) { // count frequency of elements
            if(hm[n]++ == 0) {
                ans.push_back(n);
            }
        }
        // [0, k) == [0, k-1] are all < [k,end]
        // we want [0, k-1] since that is k elements, sort by frequency hash map
        std::nth_element(ans.begin(), ans.begin() + k - 1, ans.end(), [&hm](int a, int b) {
            return hm[a] > hm[b];
        });
        ans.resize(k);
        return ans;
    }
};