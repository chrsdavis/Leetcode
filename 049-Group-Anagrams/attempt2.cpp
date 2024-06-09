// 24 ms

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        unordered_map<string, vector<string>> hm;
        for(auto str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            hm[tmp].push_back(str);
        }
        for(auto& p: hm) output.push_back(p.second);
        return output;
    }
};