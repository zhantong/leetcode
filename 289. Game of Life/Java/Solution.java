public class Solution {
    public void gameOfLife(int[][] board) {
        int m = board.length;
        int n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                for (int a = i - 1; a <= i + 1; a++) {
                    for (int b = j - 1; b <= j + 1; b++) {
                        if (a >= 0 && b >= 0 && a < m && b < n && (board[a][b] & 1) == 1) {
                            count++;
                        }
                    }
                }
                count -= board[i][j] & 1;
                if (((board[i][j] & 1) == 1 && (count == 2 || count == 3)) || ((board[i][j] & 1) == 0 && count == 3)) {
                    board[i][j] |= 2;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
}