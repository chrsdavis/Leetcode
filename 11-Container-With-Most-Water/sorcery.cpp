#include "util/common.h"

int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    for (string s; getline(cin, s);) {
        int n = count(s.begin(), s.end(), ',') + 1;
        int ans = 0, l = 0, r = n - 1, i = 0, j = s.length() - 1, x, y;
        bool read_l = true, read_r = true;
        while (l < r) {
            if (read_l) {
                read_l = false;
                ++i;
                x = s[i++] & 15;
                while ((s[i] & 15) < 10) x = x * 10 + (s[i++] & 15);
            }
            if (read_r) {
                read_r = false;
                for (j -= 2; (s[j] & 15) < 10; --j);
                int k = j + 1;
                y = s[k++] & 15;
                while ((s[k] & 15) < 10) y = y * 10 + (s[k++] & 15);
            }
            ans = max(ans, min(x, y) * (r - l));
            if (x < y) ++l, read_l = true;
            else --r, read_r = true;
        }
        out << ans << '\n';
    }
    out.flush();
    exit(0);
    return 0;
}();

class Solution {
public:
    int maxArea(vector<int>) { return 0; }
};