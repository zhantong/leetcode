class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxEndingHere = nums[0]
        maxSoFar = nums[0]
        for num in nums[1:]:
            maxEndingHere = max(num, maxEndingHere + num)
            maxSoFar = max(maxSoFar, maxEndingHere)
        return maxSoFar
