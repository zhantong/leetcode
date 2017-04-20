public class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (char[] row : board) {
            boolean[] counts = new boolean[9];
            for (char item : row) {
                if (item != '.') {
                    if (counts[item - '1']) {
                        return false;
                    }
                    counts[item - '1'] = true;
                }
            }
        }
        for (int j = 0; j < 9; j++) {
            boolean[] counts = new boolean[9];
            for (int i = 0; i < 9; i++) {
                char item = board[i][j];
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
                boolean[] counts = new boolean[9];
                for (int a = i; a <= i + 2; a++) {
                    for (int b = j; b <= j + 2; b++) {
                        char item = board[a][b];
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
}