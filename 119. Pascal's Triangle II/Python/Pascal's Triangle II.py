class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        result = [0] * (rowIndex + 1)
        result[0] = 1
        for row in range(1, rowIndex + 1):
            for i in range(row, 0, -1):
                result[i] += result[i - 1]
        return result
