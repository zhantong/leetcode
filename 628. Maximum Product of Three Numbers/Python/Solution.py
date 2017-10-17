class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_1 = -sys.maxsize
        max_2 = -sys.maxsize
        max_3 = -sys.maxsize
        min_1 = sys.maxsize
        min_2 = sys.maxsize
        for num in nums:
            if num > max_1:
                max_3 = max_2
                max_2 = max_1
                max_1 = num
            elif num > max_2:
                max_3 = max_2
                max_2 = num
            elif num > max_3:
                max_3 = num
            if num < min_1:
                min_2 = min_1
                min_1 = num
            elif num < min_2:
                min_2 = num
        return max(max_1 * max_2 * max_3, max_1 * min_1 * min_2)
