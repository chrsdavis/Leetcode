#include "util/common.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> hm;
        for(int i : nums) if(hm[i]++) return true;
        return false;
    }
};