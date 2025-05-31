// 9ms, beats 95.47%

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> hm;
        vector<vector<string>> ans;
        for (const auto& str: strs) {
            auto str2 = str;
            sort(str2.begin(), str2.end());
            auto it = hm.find(str2);
            if (it != hm.end()) {
                ans[it->second].push_back(str);
            } else {
                hm[str2] = ans.size();
                ans.push_back({str}); 
            }
        }
        return ans;
    }
};