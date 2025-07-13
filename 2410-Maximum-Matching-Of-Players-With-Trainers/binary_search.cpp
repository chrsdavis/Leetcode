class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int j = 0, cnt = 0;
        for (const int player: players) {
            auto it = std::lower_bound(trainers.begin() + j,
                                       trainers.end(), player);
            if (it == trainers.end())
                break;
            cnt++;
            j = (it - trainers.begin()) + 1;
        }
        return cnt;
    }
};