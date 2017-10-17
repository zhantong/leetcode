class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        max_here = nums[0]
        min_here = nums[0]
        max_so_far = nums[0]
        for num in nums[1:]:
            max_here *= num
            min_here *= num
            max_here, min_here = max(max_here, min_here, num), min(max_here, min_here, num)
            max_so_far = max(max_here, max_so_far)
        return max_so_far
