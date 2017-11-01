class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        class Utils {
            int[][] steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            int dfs(int[][] grid, int x, int y, int m, int n) {
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
                    return 0;
                }
                int count = 1;
                grid[x][y] = 0;
                for (int[] step : steps) {
                    count += dfs(grid, x + step[0], y + step[1], m, n);
                }
                return count;
            }
        }
        int result = 0;
        int m = grid.length;
        int n = grid[0].length;
        Utils utils = new Utils();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    result = Math.max(result, utils.dfs(grid, i, j, m, n));
                }
            }
        }
        return result;
    }
}