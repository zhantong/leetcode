public class Solution {
    public int numIslands(char[][] grid) {
        class Utils {
            void dfs(char[][] grid, int i, int j, int m, int n) {
                if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
                    return;
                }
                grid[i][j] = '0';
                dfs(grid, i - 1, j, m, n);
                dfs(grid, i + 1, j, m, n);
                dfs(grid, i, j - 1, m, n);
                dfs(grid, i, j + 1, m, n);
            }
        }
        if (grid.length == 0) {
            return 0;
        }
        Utils utils = new Utils();
        int result = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    utils.dfs(grid, i, j, m, n);
                    result++;
                }
            }
        }
        return result;
    }
}