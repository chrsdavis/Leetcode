// Same logic as finding the largest palindrome (where we iterate through all palindromes)
// Basically, iterate through the string to try palindromes with centers at i.
// Need to account for odd (i-1, i+1) and even (i, i+1) palindromes.
// Then, probe left and right to try and expand the palindrome. If we can, then count then new palindrome.

class Solution {
public:
    int countSubstrings(string s) {
        int count = s.size();
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                count++;
            }

            l = i, r = i+1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                count++;
            }
        }
        return count;
    }
};