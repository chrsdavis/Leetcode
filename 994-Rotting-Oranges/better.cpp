// Beats 100% time 97% memory

class Solution {
static constexpr array<pair<int,int>, 4> moves = {
    {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>> q;
        const int n = grid.size(), m = grid[0].size();
        int num_fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    grid[i][j] = '$'; // mark as visited
                    q.emplace(i, j, 0);
                } else if (grid[i][j] == 1) {
                    num_fresh++;
                }
            }
        }

        int max_dist = 0;
        while (!q.empty()) {
            const auto [x,y,d] = q.front();
            q.pop();
            max_dist = max(max_dist, d);
            for (const auto [dx,dy]: moves) {
                if (x+dx >= 0 && x+dx < n &&
                    y+dy >= 0 && y+dy < m &&
                    grid[x+dx][y+dy] == 1) {
                    q.emplace(x+dx, y+dy, d+1);
                    grid[x+dx][y+dy] = '$';
                    num_fresh--;
                }
            }
        }
        return num_fresh == 0 ? max_dist : -1;
    }
};