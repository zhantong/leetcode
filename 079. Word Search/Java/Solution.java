public class Solution {
    public boolean exist(char[][] board, String word) {
        class Utils {
            boolean exist(char[][] board, String word, int i, int j, int index) {
                if (index == word.length()) {
                    return true;
                }
                if (i < 0 || j < 0 || i >= board.length || j >= board[0].length || board[i][j] != word.charAt(index)) {
                    return false;
                }
                char temp = board[i][j];
                board[i][j] = '0';
                if (exist(board, word, i + 1, j, index + 1)
                    || exist(board, word, i, j + 1, index + 1)
                    || exist(board, word, i - 1, j, index + 1)
                    || exist(board, word, i, j - 1, index + 1)) {
                    return true;
                }
                board[i][j] = temp;
                return false;
            }
        }
        Utils utils = new Utils();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (utils.exist(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
}