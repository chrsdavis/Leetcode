#include "util/common.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0, upper = nums.size() - 1;
    while (lower < upper) {
        int mid = (upper + lower) / 2;

        // if(nums[mid] == target) return mid;
        if ((nums[0] <= target) ^ (nums[0] > nums[mid]) ^ (target <= nums[mid]))
            lower = mid + 1;
        else
            upper = mid;
    }
    return nums[lower] == target ? lower : -1;
    }
};

//  6 7 1 2 3 4 5
// 6 > 2, so the drop is in [0, 3] (@ 2) and [mid,end] is sorted
// so if target < nums[mid], then it CAN'T be to right,
// meaning it must be from [0,3], so we go left.

// otherwise, take target > nums[mid]. We know that [mid,end] is sorted,
// so if target in nums[mid,end], then it MUST be on the RIGHT (i.e. [mid,end]).
// if the target is > nums[end], then the target is in the "wrap-around" that was
// rotated to the start of the array, meaning it is on the LEFT.

// -------------------------------------------------------------------
// To summarize, suppose the first array value is greater than midpoint.
// I.e. assume nums[0] > nums[mid].
// This means the "drop"/pivot point is on the left side of the array.
// E.g. [4 |1| 2 3] and 4 > 1
// Notice that this means [mid,end] is perfectly sorted. Thus, if the target
// is in [nums[mid], nums[end]], then it is in [mid, end], i.e. on the right
// On the other hand, if the target is greater than both nums[mid] and
// nums[end], then it is in the bit that wraps around to the front of the array,
// i.e. somewhere on the left side
// If the target is less than both the start and the midpoint, then it must
// be on the left, where the pivot point is

// Now, suppose that nums[0] <= nums[mid]. This means the pivot must be on
// the right half, so [0, mid] is perfectly sorted. Thus, if
// target is in [nums[0], nums[mid]], then it must be on the left.
// if it is less than nums[0] (and nums[mid] by extension), 
// then it is just after the pivot section on the right half.
// If it is greater than nums[mid] (and by extension nums[0]),
// then it is just before the pivot on the right.

// So, to fully summarize, we go LEFT if:
// nums[0] > nums[mid] (pivot in left) and target >= nums[0] > nums[mid]
// nums[0] > nums[mid] (pivot in left) and target <= nums[mid] < nums[0]

// nums[0] <= nums[mid] (pivot in right) and nums[0] <= target <= nums[mid]

// thus, we go left if: 
/*
    nums[0] <= target <= mid // bc [0,mid] sorted
        target <= mid < nums[0] // bc [mid,end] sorted
            mid < nums[0] <= target // bc it wraps around to start

    ----------------------------------------
    So instead of writing out all of:
    - nums[0] < target < mid OR
    - target < mid < nums[0] OR
    - mid < nums[0] < target

    Let's try and simplify it


    So, out of the individual expressions: 
    A: nums[0] <= target
    B: target <= mid
    C: mid < nums[0]

    This means the original three cases are just:
        A&B OR B&C OR C&A

    This means that exactly TWO of the above statements must be true.
    Note that by contradiction they cannot be ALL true or ALL false, 
    no matter what. I.e. the only possibilites are "1 true" vs "2 true".

    The easiest thing would just be to add them all up and check the sum,
    but one thing we could do is to just find the opposite case 
    (i.e. go right) by checking that only 1 is true.

    Note the below expression:
    A XOR B XOR C

    If 1 is true, the expression is WLOG: 
        T XOR F XOR F == T XOR F == T
    If 2 are true, then WLOG it's: 
        T XOR T XOR F == T XOR T == F

    I.e. only 1 must be true, therefore its NOT the left case, so we go right.

    We can just XOR the three unique (individual) inequalities above.
    I.e.:
    nums[0] < target XOR target < mid XOR mid < nums[0]

    So, we just binary search with this statement deciding if we go left
    or right. 

    Note that:
    A ^ B ^ C == !!A ^ (B ^ C) == !A ^ !(B ^ C) == !A ^ (B ^ !C) == !A ^ B ^ !C

    So we can avoid the <=/>= checks by inverting the A and C statements
    to use (the opposite) strict inequality.



*/

