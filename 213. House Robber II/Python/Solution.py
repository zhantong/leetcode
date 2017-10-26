class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def robber(nums, start, end):
            if start >= end:
                return 0
            dp = [0] * end
            dp[start] = nums[start]
            for i in range(start + 1, end):
                dp[i] = max(nums[i] + dp[i - 2] if i > 1 else 0, dp[i - 1])
            return dp[end - 1]
        if len(nums) == 1:
            return nums[0]
        return max(robber(nums, 0, len(nums) - 1), robber(nums, 1, len(nums)))
