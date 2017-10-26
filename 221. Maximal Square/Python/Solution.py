class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix:
            return 0
        m = len(matrix)
        n = len(matrix[0])
        memory = [[0] * n for i in range(m)]
        result = 0
        for i in range(m):
            if matrix[i][0] == '1':
                memory[i][0] = 1
                result = 1
        for j in range(n):
            if matrix[0][j] == '1':
                memory[0][j] = 1
                result = 1
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == '1':
                    memory[i][j] = min(memory[i - 1][j], memory[i - 1]
                                       [j - 1], memory[i][j - 1]) + 1
                    result = max(result, memory[i][j])
        return result * result
