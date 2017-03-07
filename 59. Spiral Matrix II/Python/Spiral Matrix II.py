class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        row_start = 0
        row_end = n - 1
        col_start = 0
        col_end = n - 1
        result = [[None] * n for i in range(n)]
        count = 1
        while row_start <= row_end and col_start <= col_end:
            for i in range(col_start, col_end + 1):
                result[row_start][i] = count
                count += 1
            row_start += 1
            for i in range(row_start, row_end + 1):
                result[i][col_end] = count
                count += 1
            col_end -= 1
            for i in range(col_end, col_start - 1, -1):
                result[row_end][i] = count
                count += 1
            row_end -= 1
            for i in range(row_end, row_start - 1, -1):
                result[i][col_start] = count
                count += 1
            col_start += 1
        return result
