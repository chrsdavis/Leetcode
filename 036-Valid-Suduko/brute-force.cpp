class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) { // check all 3x3 sub grids
            bool digits[9] = {0};
            int R = (i / 3) * 3;
            int C = (i * 3) % 9;
            for(int r = 0; r < 3; r++) {
                for(int c = 0; c < 3; c++) {
                    if(board[r+R][c+C] == '.') continue;
                    if(digits[ board[r+R][c+C] - '1' ]) 
                        return false;
                    digits[ board[r+R][c+C] - '1' ] = true;
                }
            }
        }

        for(int i = 0; i < 9; i++) { // check all rows and columns
            bool digitsR[9] = {0};
            bool digitsC[9] = {0};
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    if(digitsR[board[i][j] - '1'])
                        return false;
                    digitsR[ board[i][j] - '1'] = true;
                }

                if(board[j][i] != '.') {
                    if(digitsC[board[j][i] - '1'])
                        return false;
                    digitsC[ board[j][i] - '1'] = true;
                }
            }
        }
        return true;
    }
};