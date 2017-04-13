public class Solution {
    public int totalNQueens(int n) {
        class Utils {
            boolean isValid(char[][] board, int i, int j) {
                for (int x = 0; x < i; x++) {
                    for (int y = 0; y < board[i].length; y++) {
                        if (board[x][y] == 'Q' && (y == j || i - x == j - y || i - x == y - j)) {
                            return false;
                        }
                    }
                }
                return true;
            }

            int backTrace(char[][] board, int rowIndex, int result) {
                if (rowIndex == board.length) {
                    result++;
                    return result;
                }
                for (int j = 0; j < board[rowIndex].length; j++) {
                    if (isValid(board, rowIndex, j)) {
                        board[rowIndex][j] = 'Q';
                        result = backTrace(board, rowIndex + 1, result);
                        board[rowIndex][j] = '.';
                    }
                }
                return result;
            }
        }
        char[][] board = new char[n][n];
        for (int i = 0; i < board.length; i++) {
            Arrays.fill(board[i], '.');
        }
        Utils utils = new Utils();
        return utils.backTrace(board, 0, 0);
    }
}