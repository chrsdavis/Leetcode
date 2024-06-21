/*
The key here is to use 2 pointers and keep track of the leftmost and rightmost maximums.
The pointers go from either end towards the middle.
If a given pointer is less than both the left and right maximums, then the water level at that point
is guaranteed to be min(max_left, max_right), since either max_left or max_right is an edge (depends on
whether this is left or right pointer), and the water height must be <= both edges.
*/


class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max_left = height[l], max_right = height[r];
        int count = 0;
        while(l < r) {
            if(max_left <= max_right) {
                l++;
                max_left = max(max_left, height[l]);
                count += max_left - height[l];
            } else {
                r--;
                max_right = max(max_right, height[r]);
                count += max_right - height[r];
            }
        }
        return count;
    }
};