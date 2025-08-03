// very slow, much more than the other bfs version.

class Solution {
bool equiv(string_view str1, string_view str2) {
    int mismatches = 0;
    for (int i = 0; i < str1.size(); i++) {
        mismatches += (int)(str1[i] - str2[i] != 0);
    }
    return mismatches < 2;
}

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string_view, vector<string_view>> adj;
        wordList.push_back(beginWord);
        bool has_end = false;
        const int n = wordList.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string_view word1 = wordList[i], word2 = wordList[j];
                if (word1 == word2) continue;
                if (equiv(word1, word2)) {
                    adj[word1].emplace_back(word2);
                    adj[word2].emplace_back(word1);
                }
                if (!has_end && endWord == word1) has_end = true;
            }
        }

        if (!has_end) return 0;

        unordered_set<string_view> visited;
        visited.insert(beginWord);
        queue<pair<string_view, int>> q;
        q.emplace(beginWord, 1);
        while (!q.empty()) {
            const auto [word, dep] = q.front();
            q.pop();
            if (word == endWord) return dep;
            for (auto str: adj[word]) {
                if (!visited.insert(str).second) continue;
                q.emplace(str, dep+1);
            }
        }
        return 0;
    }
};