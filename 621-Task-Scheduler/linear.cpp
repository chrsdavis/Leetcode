class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> freq{0};
        int max_freq = 0;
        int max_freq_cnt = 0;
        for(char i: tasks){
            freq[i-'A']++;
            max_freq = max(max_freq, freq[i-'A']);
        }
        for(int i = 0; i < 26; i++){
            if(freq[i] == max_freq) max_freq_cnt++;
        }
        int time = (max_freq-1) * (n+1) + max_freq_cnt;
        return max(time, static_cast<int>(tasks.size()));
    }
};