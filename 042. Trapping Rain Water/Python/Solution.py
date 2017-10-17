class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = 0
        right = len(height) - 1
        current_max_left = 0
        current_max_right = 0
        result = 0
        while left < right:
            if height[left] <= height[right]:
                current_max_left = max(current_max_left, height[left])
                result += current_max_left - height[left]
                left += 1
            else:
                current_max_right = max(current_max_right, height[right])
                result += current_max_right - height[right]
                right -= 1
        return result
