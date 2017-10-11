class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        class Utils {
            int[][] steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            int dfs(int[][] grid, int x, int y) {
                if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] == 0) {
                    return 0;
                }
                int count = 1;
                grid[x][y] = 0;
                for (int[] step : steps) {
                    count += dfs(grid, x + step[0], y + step[1]);
                }
                return count;
            }
        }
        int result = 0;
        Utils utils = new Utils();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    result = Math.max(result, utils.dfs(grid, i, j));
                }
            }
        }
        return result;
    }
}