class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        def dfs(matrix, i, j, m, n, prev, memory):
            if i < 0 or i >= m or j < 0 or j >= n or matrix[i][j] >= prev:
                return 0
            if memory[i][j] != 0:
                return memory[i][j]
            result = 0
            current = matrix[i][j]
            result = max(result, dfs(matrix, i - 1, j, m, n, current, memory))
            result = max(result, dfs(matrix, i + 1, j, m, n, current, memory))
            result = max(result, dfs(matrix, i, j - 1, m, n, current, memory))
            result = max(result, dfs(matrix, i, j + 1, m, n, current, memory))
            result += 1
            memory[i][j] = result
            return result

        if not matrix:
            return 0
        m = len(matrix)
        n = len(matrix[0])
        memory = [[0] * n for _ in range(m)]
        result = 0
        for i in range(m):
            for j in range(n):
                result = max(result, dfs(matrix, i, j, m, n, sys.maxsize, memory))
        return result
