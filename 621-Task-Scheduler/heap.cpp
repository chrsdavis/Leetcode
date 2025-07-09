class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char t: tasks)
            freq[t - 'A']++;
        int last_time[26];
        fill(last_time, last_time + 26, INT_MIN);

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.emplace(freq[i], i);
        }
        queue<pair<int,int>> paused;
        int intervals = 0;
        while (!pq.empty() || !paused.empty()) {
            intervals++;
            while (!paused.empty() && 
                   last_time[paused.front().second] + n < intervals) {
                pq.push(paused.front());
                paused.pop();
            }
            if (pq.empty()) {
                const auto [f,k] = paused.front();
                paused.pop();
                intervals = max(last_time[k] + n + 1, intervals);
                pq.emplace(f,k);
            }
            auto job = pq.top();
            pq.pop();
            job.first--;
            if (job.first > 0) paused.push(job);
            last_time[job.second] = intervals;
        }
        return intervals;
    }
};