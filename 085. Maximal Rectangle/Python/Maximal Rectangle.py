class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix:
            return 0
        heights = [0] * len(matrix[0])
        result = 0
        for row in matrix:
            for i, item in enumerate(row):
                if item == '1':
                    heights[i] += 1
                else:
                    heights[i] = 0
            stack = []
            i = 0
            while i < len(heights):
                while stack and heights[i] < heights[stack[-1]]:
                    index = stack.pop()
                    current = heights[index] * (i - (stack[-1] if stack else -1) - 1)
                    result = max(result, current)
                stack.append(i)
                i += 1
            while stack:
                index = stack.pop()
                current = heights[index] * (i - (stack[-1] if stack else -1) - 1)
                result = max(result, current)
        return result
