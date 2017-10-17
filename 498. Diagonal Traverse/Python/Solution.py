class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        result = []
        if not matrix:
            return result
        m = len(matrix)
        n = len(matrix[0])
        i = 0
        j = 0
        result.append(matrix[0][0])
        while i != m - 1 or j != n - 1:

            if (i + j) % 2:
                if i < m - 1 and j == 0:
                    i += 1
                elif i == m - 1:
                    j += 1
                else:
                    i += 1
                    j -= 1
            else:
                if i == 0 and j < n - 1:
                    j += 1
                elif j == n - 1:
                    i += 1
                else:
                    i -= 1
                    j += 1
            result.append(matrix[i][j])
        return result
