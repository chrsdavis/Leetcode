#include "util/common.h"

/*
IDEAS:
-----------------------------------------------------------------------
- Brute force:
    • merge sort both arrays (O(m + n)) and find median (O(1))
    • space complexity: O(1) by just swapping elements of the 2 arrays
-----------------------------------------------------------------------
- Binary search:
    • We can partition the arrays (potentially a partition of size 0),
    such that 

*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        // want to assume s_a < s_b
        int s_a = A.size(), s_b = B.size();
        int mid = (s_a + s_b + 1) / 2;
        if(s_a > s_b) return findMedianSortedArrays(B, A);
        int lower = 0, upper = s_a; // [0,...,n] [0,...,m]
        while (lower <= upper) { // bin sort on nums1 partition
            int part_a = (lower + upper) / 2;
            int part_b = mid - part_a;

            int max_left_a = (part_a == 0) ? INT_MIN : A[part_a - 1];
            int min_right_a = (part_a == s_a) ? INT_MAX : A[part_a];

            int max_left_b = (part_b == 0) ? INT_MIN : B[part_b - 1];
            int min_right_b = (part_b == s_b) ? INT_MAX : B[part_b];

            // A: [. max_left | min_right .]
            // B: [. max_left | min_right .]
            // Need all of left to be <= all of right
            // b/c it's sorted, we only need to check the areas
            // around the partitions, since left <= right for any array
            // b/c of sorting. Thus, we need leftB < rightA and
            // leftA < rightB
            if(max_left_a <= min_right_b && max_left_b <= min_right_a) {
                // now we just have to consider even/odd of total length
                return ((s_a + s_b) % 2) == 0 ?
                    (max(max_left_a, max_left_b) + 
                        min(min_right_a, min_right_b)) / 2.0 :
                    max(max_left_a, max_left_b);

            } else if (max_left_a > min_right_b) {
                // the a partition is too far right (high)
                upper = part_a - 1;
            } else { // the a partition is too far left (low)
                lower = part_a + 1;
            }
        }
        return 0.0;
    }
};
