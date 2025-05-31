class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_digits[9][9] = {0};
        int col_digits[9][9] = {0};
        int sqr_digits[9][9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                const int e = board[i][j] - '1';
                row_digits[i][e]++;
                col_digits[j][e]++;
                sqr_digits[3*(i / 3) + (j / 3)][e]++;
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                for (int e = 0; e < 9; e++) {
                    if (row_digits[i][e] > 1 ||
                        col_digits[j][e] > 1 ||
                        sqr_digits[3*(i / 3) + (j / 3)][e] > 1)
                            return false;
                }
            }
        }
        return true;
    }
};