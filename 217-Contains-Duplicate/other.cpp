#include "util/common.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> hm;
        for(int n: nums) {
            if(hm[n]) return true;
            hm[n] = true;
        }
        return false;
    }
};
