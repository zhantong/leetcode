class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix:
            return False
        m = len(matrix)
        n = len(matrix[0])
        low = 0
        high = m * n - 1
        while low <= high:
            mid = (low + high) // 2
            value = matrix[mid // n][mid % n]
            if value == target:
                return True
            elif value > target:
                high = mid - 1
            else:
                low = mid + 1
        return False
