class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    max_area = max(max_area, area_of_island(grid, i, j));
                }
            }
        }
        return max_area;
    }

    int area_of_island(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
            return 0;
        grid[r][c] = 0;
        return 1 + area_of_island(grid, r + 1, c) +
               area_of_island(grid, r - 1, c) +
               area_of_island(grid, r, c + 1) +
               area_of_island(grid, r, c - 1);
    }
};