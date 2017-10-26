class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """

        def dfs(grid, i, j, m, n):
            if i < 0 or i == m or j < 0 or j == n or grid[i][j] == '0':
                return
            grid[i][j] = '0'
            dfs(grid, i - 1, j, m, n)
            dfs(grid, i + 1, j, m, n)
            dfs(grid, i, j - 1, m, n)
            dfs(grid, i, j + 1, m, n)
        if not grid:
            return 0
        result = 0
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    dfs(grid, i, j, m, n)
                    result += 1
        return result
