class Solution {
public:
    int totalNQueens(int n) {
        class Utils {
        public:
            bool isValid(vector<string> &board, int i, int j) {
                for (int x = 0; x < i; x++) {
                    for (int y = 0; y < board[i].length(); y++) {
                        if (board[x][y] == 'Q' && (y == j || i - x == j - y || i - x == y - j)) {
                            return false;
                        }
                    }
                }
                return true;
            }

            void backTrace(vector<string> &board, int rowIndex, int &result) {
                if (rowIndex == board.size()) {
                    result++;
                    return;
                }
                for (int j = 0; j < board[rowIndex].length(); j++) {
                    if (isValid(board, rowIndex, j)) {
                        board[rowIndex][j] = 'Q';
                        backTrace(board, rowIndex + 1, result);
                        board[rowIndex][j] = '.';
                    }
                }
            }
        };
        vector<string> board(n, string(n, '.'));
        Utils utils;
        int result = 0;
        utils.backTrace(board, 0, result);
        return result;
    }
};