class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    delete_islands(grid, i, j);
                }
            }
        }
        return count;
    }

    void delete_islands(vector<vector<char>>& grid, int r, int c) {
        if( r >= 0 && r < grid.size() &&
            c >= 0 && c < grid[0].size() &&
            grid[r][c] == '1') {
                grid[r][c] = '0';
                delete_islands(grid, r, c + 1);
                delete_islands(grid, r, c - 1);
                delete_islands(grid, r + 1, c);
                delete_islands(grid, r - 1, c);
        }
    }
};