class Solution:
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        steps = ((-1, 0), (1, 0), (0, -1), (0, 1))

        def dfs(grid, x, y, m, n):
            if x < 0 or x >= m or y < 0 or y >= n or grid[x][y] == 0:
                return 0
            count = 1
            grid[x][y] = 0
            for i, j in steps:
                count += dfs(grid, x + i, y + j, m, n)
            return count

        result = 0
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    result = max(result, dfs(grid, i, j, m, n))
        return result
