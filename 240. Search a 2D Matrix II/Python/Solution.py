class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix:
            return False
        i = 0
        j = len(matrix[0]) - 1
        while i < len(matrix) and j >= 0:
            current = matrix[i][j]
            if current == target:
                return True
            elif current > target:
                j -= 1
            else:
                i += 1
        return False
