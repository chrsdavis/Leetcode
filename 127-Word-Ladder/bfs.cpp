class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string_view> words(wordList.begin(), wordList.end());
        if (words.count(endWord) == 0) return 0;
        queue<pair<string,int>> q;
        unordered_set<string_view> visited;
        q.emplace(beginWord, 1);
        while (!q.empty()) {
            auto [word, dep] = std::move(q.front());
            q.pop();
            if (word == endWord) return dep;
            for (int i = 0; i < word.size(); i++) { // find edges
                const char orig = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c; // Note: we cannot create a string view to this since it changes.
                    const auto real_word = words.find(word);
                    if (visited.count(word) > 0 || real_word == words.end())
                        continue;
                    visited.emplace(*real_word);  // use real_word b/c of string_view
                    q.emplace(word, dep+1);
                }
                word[i] = orig;
            }
        }
        return 0;
    }
};