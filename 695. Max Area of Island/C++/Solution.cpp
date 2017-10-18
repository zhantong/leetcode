class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        class Utils {
        public:
            int steps[4][2] = {{-1, 0},
                {1,  0},
                {0,  -1},
                {0,  1}
            };

            int dfs(vector<vector<int>> &grid, int x, int y) {
                if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
                    return 0;
                }
                int count = 1;
                grid[x][y] = 0;
                for (auto &step : steps) {
                    count += dfs(grid, x + step[0], y + step[1]);
                }
                return count;
            }
        };
        int result = 0;
        Utils utils;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    result = max(result, utils.dfs(grid, i, j));
                }
            }
        }
        return result;
    }
};