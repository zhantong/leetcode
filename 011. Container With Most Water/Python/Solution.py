class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_water = 0
        low = 0
        high = len(height) - 1
        while low < high:
            tall = min(height[low], height[high])
            max_water = max(max_water, tall * (high - low))
            while low < high and height[low] <= tall:
                low += 1
            while low < high and height[high] <= tall:
                high -= 1
        return max_water
