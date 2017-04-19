public class Solution {
    public List<List<String>> solveNQueens(int n) {
        class Utils {
            List<String> convert(char[][] board) {
                List<String> result = new ArrayList<>();
                for (char[] row : board) {
                    result.add(new String(row));
                }
                return result;
            }

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

            void backTrace(char[][] board, int rowIndex, List<List<String>> result) {
                if (rowIndex == board.length) {
                    result.add(convert(board));
                    return;
                }
                for (int j = 0; j < board[rowIndex].length; j++) {
                    if (isValid(board, rowIndex, j)) {
                        board[rowIndex][j] = 'Q';
                        backTrace(board, rowIndex + 1, result);
                        board[rowIndex][j] = '.';
                    }
                }
            }
        }
        char[][] board = new char[n][n];
        for (int i = 0; i < board.length; i++) {
            Arrays.fill(board[i], '.');
        }
        List<List<String>> result = new ArrayList<>();
        Utils utils = new Utils();
        utils.backTrace(board, 0, result);
        return result;
    }
}