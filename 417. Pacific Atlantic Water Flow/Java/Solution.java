public class Solution {
    public List<int[]> pacificAtlantic(int[][] matrix) {
        class Utils {
            void dfs(int[][] matrix, boolean[][] visited, int i, int j, int m, int n) {
                if (visited[i][j]) {
                    return;
                }
                visited[i][j] = true;
                if (i > 0 && !visited[i - 1][j] && matrix[i][j] <= matrix[i - 1][j]) {
                    dfs(matrix, visited, i - 1, j, m, n);
                }
                if (i < m && !visited[i + 1][j] && matrix[i][j] <= matrix[i + 1][j]) {
                    dfs(matrix, visited, i + 1, j, m, n);
                }
                if (j > 0 && !visited[i][j - 1] && matrix[i][j] <= matrix[i][j - 1]) {
                    dfs(matrix, visited, i, j - 1, m, n);
                }
                if (j < n && !visited[i][j + 1] && matrix[i][j] <= matrix[i][j + 1]) {
                    dfs(matrix, visited, i, j + 1, m, n);
                }
            }
        }
        if (matrix.length == 0) {
            return new ArrayList<>();
        }
        Utils utils = new Utils();
        int m = matrix.length;
        int n = matrix[0].length;
        boolean[][] pacific = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            utils.dfs(matrix, pacific, i, 0, m - 1, n - 1);
        }
        for (int j = 0; j < n; j++) {
            utils.dfs(matrix, pacific, 0, j, m - 1, n - 1);
        }
        boolean[][] atlantic = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            utils.dfs(matrix, atlantic, i, n - 1, m - 1, n - 1);
        }
        for (int j = 0; j < n; j++) {
            utils.dfs(matrix, atlantic, m - 1, j, m - 1, n - 1);
        }
        List<int[]> result = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.add(new int[] {i, j});
                }
            }
        }
        return result;
    }
}