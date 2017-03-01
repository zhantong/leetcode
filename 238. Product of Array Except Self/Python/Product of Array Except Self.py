class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = [None] * len(nums)
        result[0] = 1
        for i in range(1, len(nums)):
            result[i] = result[i - 1] * nums[i - 1]
        temp = 1
        for i in range(len(nums) - 1, -1, -1):
            result[i] *= temp
            temp *= nums[i]
        return result
