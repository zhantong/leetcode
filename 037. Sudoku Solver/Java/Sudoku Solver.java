public class Solution {
    public void solveSudoku(char[][] board) {
        class Utils {
            boolean sudoku(char[][] board, int pos) {
                if (pos == 81) {
                    return true;
                }
                int i = pos / 9;
                int j = pos % 9;
                if (board[i][j] != '.') {
                    return sudoku(board, pos + 1);
                }
                for (char letter = '1'; letter <= '9'; letter++) {
                    if (isValid(board, i, j, letter)) {
                        board[i][j] = letter;
                        if (sudoku(board, pos + 1)) {
                            return true;
                        }
                    }
                }
                board[i][j] = '.';
                return false;
            }

            boolean isValid(char[][] board, int row, int column, char letter) {
                for (int i = 0; i < 9; i++) {
                    if (board[i][column] == letter) {
                        return false;
                    }
                }
                for (int j = 0; j < 9; j++) {
                    if (board[row][j] == letter) {
                        return false;
                    }
                }
                for (int i = 3 * (row / 3), countI = 0; countI < 3; i++, countI++) {
                    for (int j = 3 * (column / 3), countJ = 0; countJ < 3; j++, countJ++) {
                        if (board[i][j] == letter) {
                            return false;
                        }
                    }
                }
                return true;
            }
        }
        Utils utils = new Utils();
        utils.sudoku(board, 0);
    }
}