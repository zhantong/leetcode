public class Solution {
    public int maximalSquare(char[][] matrix) {
        if (matrix.length == 0) {
            return 0;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] memory = new int[m][n];
        int result = 0;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == '1') {
                memory[i][0] = 1;
                result = 1;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == '1') {
                memory[0][j] = 1;
                result = 1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    memory[i][j] = Math.min(Math.min(memory[i - 1][j], memory[i - 1][j - 1]), memory[i][j - 1]) + 1;
                    result = Math.max(result, memory[i][j]);
                }
            }
        }
        return result * result;
    }
}