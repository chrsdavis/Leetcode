class Solution {
public:
    bool isAnagram(string s, string t) {
        int cs[26] = {0};
        for (char c: s) cs[int(c) - 97]++;
        for (char c: t) cs[int(c) - 97]--;
        for (int i = 0; i < 26; i++) {
            if(cs[i]) return false;
        }
        return true;
    }

};