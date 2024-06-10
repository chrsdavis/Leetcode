// hm[i] = length of seq. currently known at i
// hm[i] = length at i - 1 + length at i + 1
// E.g. we already know [1,2,3] and [5,6], so hm[3] = 3, and hm[5] = 2
// Then, we get [4], so hm[4] = hm[3] + hm[5] + 1= 3 + 2 + 1 = 6
// Now, we need to adjust the "edges" of the sequence for the next numbers
// I.e. h[1] and  h[6] should now be h[4] = 6.
// We know the seq at i-1 is h[i-1] long, so its left most edge is at
// i - h[i-1]; similarly, the rightmost element of the right sequence
// is at i + h[i+1]. So, we need to update h[i-h[i-1]] and h[i+h[i+1]] to the new count
// We only consider integers that don't already have an entry in the hash map;
// this way, we only need to update the 2 bounding edges, and not every element in the sequence.
// This gives us O(n) time and O(n) space.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hm; // hm[i] = len seq @ i
        int count = 0;
        for(int i: nums) {
            if(hm[i] == 0) { // new integer
                hm[i] = hm[i-1] + hm[i+1] + 1;
                // update left & right seq. edges
                hm[i - hm[i-1]] = hm[i];
                hm[i + hm[i+1]] = hm[i];
                count = max(count, hm[i]);
            }
        }
        return count;
    }
};