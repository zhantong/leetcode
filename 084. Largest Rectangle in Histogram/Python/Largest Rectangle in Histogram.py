class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = []
        i = 0
        result = 0
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
