#include "util/common.h"

class Solution {
public:
    int maxArea(vector<int>& h) {
        int max_area = 0;
        int i = 0, j = h.size() - 1;

        while(i < j) {
            max_area = max(min(h[i], h[j]) * (j - i), max_area);
            if (h[i] < h[j]) i++;
            else j--;
        }
        return max_area;
    }
};
