#include "util/common.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 0;
        unordered_set<int> numset(nums.begin(), nums.end());

        for (int num: nums) {
            if(numset.count(num - 1) == numset.end()) { // start of sequence
                int temp_count = 1;
                int current_num = num;
                while(numset.find(current_num + 1) != numset.end()) {
                    current_num++;
                    temp_count++;
                }
                count = max(temp_count, count);
            }
        }
        return count;
    }
};
