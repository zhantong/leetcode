class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        results = [0] * (len(nums) + 1)
        results[0] = 0
        results[1] = nums[0]
        for i in range(2, len(nums) + 1):
            results[i] = max(nums[i - 1] + results[i - 2], results[i - 1])
        return results[-1]
