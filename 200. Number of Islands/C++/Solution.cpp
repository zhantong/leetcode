class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        class Utils {
        public:
            void dfs(vector<vector<char>> &grid, int i, int j, int m, int n) {
                if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
                    return;
                }
                grid[i][j] = '0';
                dfs(grid, i - 1, j, m, n);
                dfs(grid, i + 1, j, m, n);
                dfs(grid, i, j - 1, m, n);
                dfs(grid, i, j + 1, m, n);
            }
        };
        if (grid.size() == 0) {
            return 0;
        }
        Utils utils;
        int result = 0;
        int m = grid.size();
        int n = grid[0].size();
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
};