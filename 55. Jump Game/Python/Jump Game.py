class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        current = 0
        i = 0
        while i < len(nums) and i <= current:
            current = max(current, i + nums[i])
            i += 1
        return i == len(nums)
