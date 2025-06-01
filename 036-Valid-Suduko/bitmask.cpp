class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_digits[9] = {0};
        int col_digits[9] = {0};
        int sqr_digits[9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                const int e = board[i][j] - '1';
                const int mask = 1 << e;
                const int sqr_idx = 3*(i / 3) + (j / 3);

                if (row_digits[i] & mask ||
                    col_digits[j] & mask ||
                    sqr_digits[sqr_idx] & mask)
                        return false;

                row_digits[i] |= mask;
                col_digits[j] |= mask;
                sqr_digits[sqr_idx] |= mask;
            }
        }
        return true;
    }
};