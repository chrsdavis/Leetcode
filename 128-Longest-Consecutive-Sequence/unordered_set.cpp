#include "util/common.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset;
        int current_num, count = 0;
        for (int num: nums) numset.insert(num);

        for (int num: nums) {
            if(!numset.count(num - 1)) {
                int temp_count = 1;
                current_num = num;
                while(numset.count(current_num + 1)) {
                    current_num++;
                    temp_count++;
                }
                count = max(temp_count, count);
            }
        }
        return count;
    }
};