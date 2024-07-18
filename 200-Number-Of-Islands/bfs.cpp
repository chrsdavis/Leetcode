class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid[0].size(), m = grid.size();
        int offsets[] = {0, 1, 0, -1, 0};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') { // remove this island via bfs
                    count++;
                    queue<pair<int,int>> q;
                    q.emplace(i,j);
                    while(!q.empty()) {
                        auto [x,y] = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++) {
                            int r = x + offsets[k];
                            int c = y + offsets[k+1];
                            if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                q.emplace(r,c);
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};