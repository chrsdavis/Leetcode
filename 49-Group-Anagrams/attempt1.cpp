// beats 59.24% in time, 63.83% in memory
// 39 ms, 20.6 MB

#include <bits/stdc++.h>
class Solution {
public:
    string count_sort(string str) {
        int chars[26] = {0};
        for(char c: str) chars[c-'a']++;
        int j = 0;
        for(int i = 0; i < str.size(); i++) {
            while(chars[j] == 0 && j++ < 26);
            str[i] = char(j + 'a');
            chars[j]--;
        }
        return str;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hm;
        vector<vector<string>> sol;
        for(string str: strs)
            hm[count_sort(str)].push_back(str);
        for(auto it: hm)
            sol.push_back(it.second);
        return sol;
    }
};