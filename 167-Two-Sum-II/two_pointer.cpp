#include "util/common.h"

// 11 ms, beats 85%

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        int temp_target = numbers[i] + numbers[j];
        while(temp_target != target) {
            if(temp_target < target) i++;
            else j--;
            temp_target = numbers[i] + numbers[j];
        }
        return {i + 1,j + 1};
    }
};
