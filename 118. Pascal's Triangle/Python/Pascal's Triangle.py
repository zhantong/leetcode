class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        result = [None] * numRows
        if numRows >= 1:
            result[0] = [1]
        if numRows >= 2:
            result[1] = [1, 1]
        for row in range(3, numRows + 1):
            current = [None] * row
            current[0] = 1
            current[-1] = 1
            for i in range(1, row - 1):
                current[i] = result[row - 2][i - 1] + result[row - 2][i]
            result[row - 1] = current
        return result
