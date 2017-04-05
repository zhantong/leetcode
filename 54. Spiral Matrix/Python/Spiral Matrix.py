class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []
        m = len(matrix)
        n = len(matrix[0])
        result = []
        left = 0
        right = n
        up = 0
        down = m
        while left < right and up < down:
            for j in range(left, right):
                result.append(matrix[up][j])
            up += 1
            if up == down:
                break
            for i in range(up, down):
                result.append(matrix[i][right - 1])
            right -= 1
            if right == left:
                break
            for j in range(right - 1, left - 1, -1):
                result.append(matrix[down - 1][j])
            down -= 1
            if down == up:
                break
            for i in range(down - 1, up - 1, -1):
                result.append(matrix[i][left])
            left += 1
            if left == right:
                break
        return result
