# 4. [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the median of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.
<br><br>

#### <b>Example 1</b>
> **Input:** nums1 = [1,3], nums2 = [2] <br>
**Output:** 2.00000 <br>
**Explanation:** merged array = [1,2,3] and median is 2.


#### <b>Example 2 </b>
> **Input:** nums1 = [1,2], nums2 = [3,4] <br>
**Output:** 2.50000 <br>
**Explanation:** merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

<br>

#### <b>Constraints</b>
- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `0 <= n <= 1000`
- `-106 <= nums1[i], nums2[i] <= 106`
