#include "util/common.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int upper = m * n - 1;
        int lower = 0;
        while(upper >= lower) {
            int mid = lower + (upper - lower) / 2;
            if(matrix[mid / n][mid % n] == target)
                return true;
            else if(matrix[mid / n][mid % n] < target)
                lower = mid + 1;
            else
                upper = mid - 1;
        }
        return false;
    }
};
