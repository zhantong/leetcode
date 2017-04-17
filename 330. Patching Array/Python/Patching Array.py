class Solution(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        hope = 1
        result = 0
        index = 0
        while hope <= n:
            if index < len(nums) and nums[index] <= hope:
                hope += nums[index]
                index += 1
            else:
                result += 1
                hope += hope
        return result
