#include "util/common.h"


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upper = *max_element(piles.begin(), piles.end());
        int lower = 1;
        int min_amount = -1; // best time
        while(lower <= upper) {
            int mid = (upper + lower) >> 1; // # of bananas to eat per cycle
            unsigned int current_time = 0; // # of cycles total
            for_each(piles.begin(), piles.end(), [=,&current_time](auto p) {
                current_time += (p % mid) ? 1 + p/mid : p/mid; // number of cycles required
            });
            if(current_time > h)  // taking too long, so need to increase count
                lower = mid + 1;
            else { // this answer works, so try reducing the count
                min_amount = mid;
                upper = mid - 1;
            }
        }
        return min_amount;
    }
};

/*
For lower, we need to eat at least 1 banana, as otherwise we would never finish.
For upper, just start by taking the largest banana pile, since that means we are guaranteed to finish within
size(piles) steps.
*/

/* 
For beter performance, add a flag and a break once the current_time > h, 
as there is no point in continuing to add up the time check. I.e. break out of the loop that
counts up the current_time and set the flag. Then, check if the flag is true outside the loop,
*/
