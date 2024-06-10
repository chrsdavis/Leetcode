// beats 93% O(nlogn) time, O(1) space

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int longest=1;
        unordered_set<int> st;
        for(auto x:nums){
            st.insert(x);
        }
        for(auto x:st){
            if(st.find(x-1)==st.end()){
                int count=1;
                int it=x;
                while(st.find(it+1)!=st.end()){
                    it=it+1;
                    count++;
                }
                longest=max(count,longest);
            }
        }
        return longest;
    }
};