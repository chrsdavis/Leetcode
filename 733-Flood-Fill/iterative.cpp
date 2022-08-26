// NEED TO FINISH THIS

#include <queue>
#include <utility>

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        const unsigned short int r_max = (unsigned short int)image.size() - 1;
        const unsigned short int c_max = (unsigned short int)image[0].size() - 1;
        const int cc = image[sr][sc];
        bool* closed = new bool[50 * 50];
        std::queue<pair<int, int>> stk;
        stk.push({sr, sc});
        while(!stk.empty())
        {
            pair<int, int> cell = stk.front();
            image[cell.first][cell.second] = color;
            stk.pop();
            const int& _r = cell.first, & _c = cell.second;
            if(_r > 0 && image[_r - 1][_c] == cc && !closed[(_r - 1) * (c_max + 1) + _c])
                stk.push({_r - 1, _c});
            if(_c > 0 && image[_r][_c - 1] == cc && !closed[_r * (c_max + 1) + _c - 1])
                stk.push({_r, _c - 1});
            if(_r < r_max && image[_r + 1][_c] == cc && !closed[(_r + 1) * (c_max + 1) + _c])
                stk.push({_r + 1, _c});
            if(_c < c_max && image[_r][_c + 1] == cc && !closed[_r * (c_max + 1) + _c + 1])
                stk.push({_r, _c + 1});
        }
        delete closed;
        return image;
    }
};
