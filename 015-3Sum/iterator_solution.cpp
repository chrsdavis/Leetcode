// found this solution using iterators to avoid subscript operator
// beats 99.92%

#include "util/common.h"

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> rv;
    auto iptr = nums.begin();
    auto end = nums.end();
    sort(iptr, end);
    auto limit = end - 2;
    int aa = *iptr;
    while (iptr < limit) {
      int want = 0 - aa;
      auto lo = iptr + 1;
      auto hi = end - 1;
      int bb = *lo;
      int cc = *hi;
      while (lo < hi) {
        int sum = bb + cc;
        if (sum < want)
          bb = *++lo;
        else if (sum > want)
          cc = *--hi;
        else {
          rv.emplace_back(vector<int>{aa, bb, cc});
          int bbb = bb;
          int ccc = cc;
          do {
            bb = *++lo;
          } while ((bb == bbb) && (lo < hi));
          do {
            cc = *--hi;
          } while ((cc == ccc) && (lo < hi));
        }
      }
      int aaa = aa;
      do {
        aa = *++iptr;
      } while ((aa == aaa) && (iptr < limit));
    }
    return rv;
  }
};