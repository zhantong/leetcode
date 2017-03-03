class Solution(object):
    def PredictTheWinner(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        dp = [[0] * len(nums) for i in range(len(nums))]
        for j in range(len(nums)):
            current_sum = 0
            for i in range(j, -1, -1):
                current_sum += nums[i]
                if i == j:
                    dp[i][i] = nums[i]
                else:
                    dp[i][j] = max(current_sum - dp[i][j - 1], current_sum - dp[i + 1][j])
        return 2 * dp[0][len(nums) - 1] >= sum(nums)
