public class Solution {
    public char[][] updateBoard(char[][] board, int[] click) {
        int i = click[0];
        int j = click[1];
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
        } else {
            int count = 0;
            int m = board.length;
            int n = board[0].length;
            for (int a = -1; a <= 1; a++) {
                for (int b = -1; b <= 1; b++) {
                    int p = i + a;
                    int q = j + b;
                    if (p >= 0 && q >= 0 && p < m && q < n && board[p][q] == 'M') {
                        count++;
                    }
                }
            }
            if (count != 0) {
                board[i][j] = (char)(count + '0');
            } else {
                board[i][j] = 'B';
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        int p = i + a;
                        int q = j + b;
                        if (p >= 0 && q >= 0 && p < m && q < n && board[p][q] == 'E') {
                            updateBoard(board, new int[] {p, q});
                        }
                    }
                }
            }
        }
        return board;
    }
}