class Solution:
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        def dfs(grid, x, y):
            if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]) or grid[x][y] == 0:
                return 0
            count = 1
            grid[x][y] = 0
            steps = ((-1, 0), (1, 0), (0, -1), (0, 1))
            for i, j in steps:
                count += dfs(grid, x + i, y + j)
            return count

        result = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    result = max(result, dfs(grid, i, j))
        return result
