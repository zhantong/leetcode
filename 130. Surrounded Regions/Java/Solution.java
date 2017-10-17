public class Solution {
    public void solve(char[][] board) {
        class Utils {
            void dfs(char[][] board, int i, int j) {
                if (i < 0 || j < 0 || i >= board.length || j >= board[0].length) {
                    return;
                }
                board[i][j] = '1';
                if (i > 1 && board[i - 1][j] == 'O') {
                    dfs(board, i - 1, j);
                }
                if (i < board.length - 2 && board[i + 1][j] == 'O') {
                    dfs(board, i + 1, j);
                }
                if (j > 1 && board[i][j - 1] == 'O') {
                    dfs(board, i, j - 1);
                }
                if (j < board[0].length - 2 && board[i][j + 1] == 'O') {
                    dfs(board, i, j + 1);
                }
            }
        }
        if (board.length == 0) {
            return;
        }
        Utils utils = new Utils();
        int m = board.length;
        int n = board[0].length;
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                utils.dfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                utils.dfs(board, i, n - 1);
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                utils.dfs(board, 0, j);
            }
            if (board[m - 1][j] == 'O') {
                utils.dfs(board, m - 1, j);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }
}