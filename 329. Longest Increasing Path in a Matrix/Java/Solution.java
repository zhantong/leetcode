public class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        class Utils {
            int dfs(int[][] matrix, int i, int j, int m, int n, int prev, int[][] memory) {
                if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] >= prev) {
                    return 0;
                }
                if (memory[i][j] != 0) {
                    return memory[i][j];
                }
                int result = 0;
                int current = matrix[i][j];
                result = Math.max(result, dfs(matrix, i - 1, j, m, n, current, memory));
                result = Math.max(result, dfs(matrix, i + 1, j, m, n, current, memory));
                result = Math.max(result, dfs(matrix, i, j - 1, m, n, current, memory));
                result = Math.max(result, dfs(matrix, i, j + 1, m, n, current, memory));
                result++;
                memory[i][j] = result;
                return result;
            }
        }
        if (matrix.length == 0) {
            return 0;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] memory = new int[m][n];
        int result = 0;
        Utils utils = new Utils();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = Math.max(result, utils.dfs(matrix, i, j, m, n, Integer.MAX_VALUE, memory));
            }
        }
        return result;
    }
}