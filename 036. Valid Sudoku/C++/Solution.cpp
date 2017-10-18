class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        for (const auto &row : board) {
            vector<bool> counts(9, false);
            for (const auto &item : row) {
                if (item != '.') {
                    if (counts[item - '1']) {
                        return false;
                    }
                    counts[item - '1'] = true;
                }
            }
        }
        for (int j = 0; j < 9; j++) {
            vector<bool> counts(9, false);
            for (int i = 0; i < 9; i++) {
                const char &item = board[i][j];
                if (item != '.') {
                    if (counts[item - '1']) {
                        return false;
                    }
                    counts[item - '1'] = true;
                }
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<bool> counts(9, false);
                for (int a = i; a <= i + 2; a++) {
                    for (int b = j; b <= j + 2; b++) {
                        const char &item = board[a][b];
                        if (item != '.') {
                            if (counts[item - '1']) {
                                return false;
                            }
                            counts[item - '1'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};