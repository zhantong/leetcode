class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        target = sum(nums)
        if target % 2:
            return False
        target //= 2
        dp = [[False] * (target + 1) for i in range(len(nums) + 1)]
        dp[0][0] = True
        for i in range(1, len(nums) + 1):
            for j in range(target + 1):
                dp[i][j] = dp[i - 1][j]
                if j >= nums[i - 1]:
                    dp[i][j] = dp[i][j] or dp[i - 1][j - nums[i - 1]]
        return dp[len(nums)][target]
