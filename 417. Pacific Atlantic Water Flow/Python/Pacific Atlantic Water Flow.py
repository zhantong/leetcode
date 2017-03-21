class Solution(object):
    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        if not matrix:
            return []

        def dfs(matrix, visited, i, j, m, n):
            if visited[i][j]:
                return
            visited[i][j] = True
            if i > 0 and not visited[i - 1][j] and matrix[i][j] <= matrix[i - 1][j]:
                dfs(matrix, visited, i - 1, j, m, n)
            if i < m and not visited[i + 1][j] and matrix[i][j] <= matrix[i + 1][j]:
                dfs(matrix, visited, i + 1, j, m, n)
            if j > 0 and not visited[i][j - 1] and matrix[i][j] <= matrix[i][j - 1]:
                dfs(matrix, visited, i, j - 1, m, n)
            if j < n and not visited[i][j + 1] and matrix[i][j] <= matrix[i][j + 1]:
                dfs(matrix, visited, i, j + 1, m, n)

        m = len(matrix)
        n = len(matrix[0])
        pacific = [[False] * n for i in range(m)]
        for i in range(m):
            dfs(matrix, pacific, i, 0, m - 1, n - 1)
        for j in range(n):
            dfs(matrix, pacific, 0, j, m - 1, n - 1)
        atlantic = [[False] * n for i in range(m)]
        for i in range(m):
            dfs(matrix, atlantic, i, n - 1, m - 1, n - 1)
        for j in range(n):
            dfs(matrix, atlantic, m - 1, j, m - 1, n - 1)
        result = []
        for i in range(m):
            for j in range(n):
                if pacific[i][j] and atlantic[i][j]:
                    result.append([i, j])
        return result
