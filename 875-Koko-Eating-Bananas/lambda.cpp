#include "util/common.h"


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upper = *max_element(piles.begin(), piles.end());
        int lower = 1;
        int min_time = -1;
        while(lower <= upper) {
            int mid = (upper + lower) >> 1;
            unsigned int current_time = 0;
            for_each(piles.begin(), piles.end(), [=,&current_time](auto p) {
                current_time += (p % mid) ? 1 + p/mid : p/mid;
            });
            if(current_time > h)
                lower = mid + 1;
            else {
                min_time = mid;
                upper = mid - 1;
            }
        }
        return min_time;
    }
};



/* 
For beter performance, add a flag and a break once the current_time > h, 
as there is no point in continuing to add up the time check. I.e. break out of the loop that
counts up the current_time and set the flag. Then, check if the flag is true outside the loop,
*/
