// Run a BFS at every rotten orange; record depth at every BFS iteration; max depth is num iterations needed

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>> q;
        int num_fresh = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.emplace(i + 1, j, 1);
                    q.emplace(i - 1, j, 1);
                    q.emplace(i, j + 1, 1);
                    q.emplace(i, j - 1, 1);
                } else if(grid[i][j] == 1) {
                    num_fresh++;
                }
            }
        }
        if(num_fresh == 0) return 0;
        int num_days = -1;
        while(!q.empty()) {
            auto [x,y,depth] = q.front();
            q.pop();
            if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1)
                continue;
            grid[x][y] = 2;
            num_fresh--;
            q.emplace(x + 1, y, depth + 1);
            q.emplace(x - 1, y, depth + 1);
            q.emplace(x, y + 1, depth + 1);
            q.emplace(x, y - 1, depth + 1);
            num_days = max(num_days, depth);
        }
        return num_fresh == 0 ? num_days : -1;
    }
};