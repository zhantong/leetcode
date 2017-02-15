class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in range(0, len(nums)):
            result ^= i
            result ^= nums[i]
        result ^= len(nums)
        return result
