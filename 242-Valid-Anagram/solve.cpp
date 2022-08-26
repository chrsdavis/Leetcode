// https://leetcode.com/problems/valid-anagram/submissions/

// just use bottom version

#include <cstring>

class Solution {
public:
    bool isAnagram(string s, string t) {
        unsigned short int table[26];  // a = 97, z = 122
        // change table to signed normal int to skip this loop
        for(int i = 0; i < 26; i++)
            table[i] = 1;
        for(size_t i = 0; i < s.length(); i++)
            table[s[i] - 97]++;
        for(size_t i = 0; i < t.length(); i++)
            table[t[i] - 97]--;
        for(int i = 0; i < 26; i++)
            if (table[i] != 1) return false;
        return true;
    }
};


/* slighly faster version but worse mem (ushort -> int) */
/*
bool isAnagram(string s, string t) {
    int table[26] = {};  // a = 97, z = 122
    for(size_t i = 0; i < s.length(); i++)
        table[s[i] - 97]++;
    for(size_t i = 0; i < t.length(); i++)
        table[t[i] - 97]--;
    for(int i = 0; i < 26; i++)
        if (table[i] != 1) return false;
    return true;
}
*/
