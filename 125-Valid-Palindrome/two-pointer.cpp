// https://leetcode.com/problems/valid-palindrome/submissions/
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        short left = 0, right = (short)s.length() - 1;
        while(left < right) {
            while (!isalnum(s[left]) && left < right) left++;
            while (!isalnum(s[right]) && right > left) right--;
            if(tolower(s[left]) != tolower(s[right])) return false;
            left++, right--;
        }
        return true;
    }
};
